/* 
 Copyright (c) 2019-2021 Sinric Pro

 The copyright in these pages (including without limitation all text, graphics and computer code relating thereto or associated therewith) 
 and all other intellectual property and proprietary rights therein belongs to Sinric Pro and all rights are reserved.

 Permission is given for the downloading and temporary storage of one or more of these pages for the sole purpose of viewing them on a stand-alone personal computer or monitor. 
 Permanent copying or redistribution, or reproduction of all or part of this library in any form is strictly prohibited without express permission of Sinric Pro.
*/

#pragma once 

#include <DNSServer.h>
#include <ArduinoJson.h>
#include "ProvUtil.h" 
#include "ConfigHttpServer.h"
#include "ProvDebug.h"
#include "ProvState.h"
void touch1(void);
#if defined(ENABLE_LED_INDICATOR)
  #include "Indicator.h"
#endif

#if defined(ENABLE_RESET_BUTTON)
  #include "ResetButton.h"
#endif

#if defined(ESP32)
  #include <WiFi.h>
  #include "SPIFFS.h"
  #include "nvs_flash.h"
  #include "esp_system.h"  
  #include <esp_wifi.h>
  #include <WiFiUDP.h> 
  #include "BLEProv.h"
#else
  #include <ESP8266WiFi.h>; 
  #include <FS.h>
  #include <WiFiUdp.h>
  #include "SmartConfigProv.h"
  
  extern "C" {
    #include "user_interface.h"
  }
#endif
 
//void serialdata(void);
//#define rst_pin D8



class WiFiProv {
  public:
    WiFiProv(DeviceConfig &config);
    ~WiFiProv();

    bool hasProvisioned();
    void beginProvision();
    using ProvDoneCallback = std::function<void(void)>;

  private:
    String onDeviceInfo();    
    bool startSmartConfig();     
    void notifySuccess();     
    void startHttpConfigServer();
    void restart();
    
    // BLE
    bool onBleWiFiCredetials(String wifiConfig);
    bool startBLEConfig();
    void onBleProvDone();
    void onProvDone(ProvDoneCallback cb);

    bool onAuthCredetials(const String &authConfig);  
     
    //DeviceConfig &config;
    bool m_isConfigured;

    ConfigStore m_configStore;
    ProvDoneCallback m_provDoneCallback;
    ConfigHttpServer m_configHttpServer;    

    #if defined(ESP8266)
      SmartConfigProv m_smartConfigProv;    
    #endif 
};

/**
* @brief Load the product configuration. If not configured yet, start the provisioning process.
*/ 
WiFiProv::WiFiProv(DeviceConfig &config) : m_configStore(config), m_configHttpServer(m_configStore) {
  m_isConfigured = m_configStore.loadConfig();
  DEBUG_PROV(PSTR("[WiFiProv()]: Is already provisioned ? %s\r\n"), m_isConfigured ? "YES" : "NO");
}

 /**
 * @brief Check whether device has been provisioned already.
 * 
 * @retval true
 *      Yes
 * @retval false
 *      No
 */
bool WiFiProv::hasProvisioned() { 
  return m_isConfigured;
}

/**
 * @brief Start device provisioning. Device may reboot after provisioning complete.
 */
void WiFiProv::beginProvision() {
  if (!m_isConfigured) {

    #if defined(ENABLE_LED_INDICATOR)
      indicator_init();
    #endif

    #if defined(ENABLE_RESET_BUTTON)
      resetbutton_init();
    #endif
    
    ProvState::getInstance()->state = ProvState::MODE_WAIT_WIFI_CONFIG;
     
    #ifdef ESP32
       bool didSuccess = startBLEConfig(); // Start Bluetooth provisioning on ESP32 chipset
       
       if(!didSuccess) { // BLE Config timeout. Fall-back to AP based WebUI provisioning
         ProvState::getInstance()->state = ProvState::MODE_SWITCH_TO_STA;
         
         m_configHttpServer.startSoftAP(); // setup SoftAP 
         startHttpConfigServer(); // Start WebUI
         restart();
      }

      m_isConfigured = true;
    #else
      bool didSuccess = startSmartConfig(); // wait until wifi is available or smartconfig timeout
      
      if(didSuccess) { 
        startHttpConfigServer(); // WiFi credentails received via SmartConfig. Start the HTTP Server to receive appkey/secret and device ids
      } else {
        ProvState::getInstance()->state = ProvState::MODE_SWITCH_TO_STA;
        
        m_configHttpServer.startSoftAP(); // setup SoftAP 
        startHttpConfigServer(); // Start WebUI
      }

      // Note: SmartConfig/AP mode: cannot connect to server without restart even though connected to WiFi (host-not found) once restarted, ESP will get the config and connect to server.
      restart();
    #endif
  } 

}

WiFiProv::~WiFiProv(){}

/**
* @brief Start the HTTP to requests from the app
*/ 
void WiFiProv::startHttpConfigServer() {
  DEBUG_PROV(PSTR("[WiFiProv::startHttpConfigServer]: Setting up HTTP Server...\r\n"));
  
  m_configHttpServer.onAuthCredentials(std::bind(&WiFiProv::onAuthCredetials, this, std::placeholders::_1)); // callback to receive appkey/secret and device ids 
  
  m_configHttpServer.start();   // setup server 
  m_configHttpServer.handle();  // run server until config is received
  m_configHttpServer.stop();    // stop server        
}

/**
* @brief Gets called when appkey/appsecret and device ids are recevied by the app.
* @param authConfig
*      appkey/appsecret and device ids in json
* @return
*      ok
*/ 
bool WiFiProv::onAuthCredetials(const String &authConfig) {
  DEBUG_PROV(PSTR("[WiFiProv.onAuthCredetials()]: json: %s\r\n"), authConfig.c_str());
  
  DynamicJsonDocument jsonConfig(2048);
  DeserializationError error = deserializeJson(jsonConfig, authConfig);
  
  if (error) {
    DEBUG_PROV(PSTR("[WiFiProv.onAuthCredetials()]: deserializeJson() failed: %s\r\n"), error.c_str());
    return false;
  } else {
    if (m_configStore.saveJsonConfig(jsonConfig)) {
      DEBUG_PROV(PSTR("[WiFiProv.onAuthCredetials()]: Configuration updated!\r\n"));
      return true;    
    }
    else {
      DEBUG_PROV(PSTR("[WiFiProv.onAuthCredetials()]: Failed to save configuration !\r\n"));
      return false;
    }
  }
}

/**
* @brief Gets called when wifi credentials are recevied via BLE from the app.
* @param wifiConfig
*      WiFi SSID/Password in json format
* @return
*      ok
*/ 
bool WiFiProv::onBleWiFiCredetials(String wifiConfig) {
 StaticJsonDocument<200> doc;
 DeserializationError error = deserializeJson(doc, wifiConfig);
 if (error) {
    DEBUG_PROV(PSTR("[WiFiProv.onBleWiFiCredetials()] deserializeJson() failed: %s"), error.c_str());
    return false;
 }

 ProvState::getInstance()->state = ProvState::MODE_CONNECTING_WIFI;
  
 const char * ssid = doc["ssid"];
 const char * pass = doc["pass"]; 
   
 bool success = ProvUtil::connectToWiFi(ssid, pass);
 return success;
}

/**
* @brief Get called when BLE provisioing is done.
*/ 
void WiFiProv::onBleProvDone() {
  if(m_provDoneCallback) {
      m_provDoneCallback();
  } 
}

/**
* @brief Set the callback to invoke when provisioning done.
* @param cb callback
*/ 
void WiFiProv::onProvDone(ProvDoneCallback cb) {
  m_provDoneCallback = cb;
}

/**
 * @brief Get the device information.
 * @return 
*   Product structure
 */ 
String WiFiProv::onDeviceInfo() {
  String data = getProductStructure();
  DEBUG_PROV(PSTR("[WiFiProv.onDeviceInfo()]: %s\r\n"), data.c_str());  
  return data;
}

/**
 * @brief Start bluetooth provisioning and wait-until timeout.
 * @return ok
 */ 
bool WiFiProv::startBLEConfig() {
  #ifdef ESP32
    DEBUG_PROV(PSTR("[WiFiProv.startBLEConfig()]: Starting AP using BLE \r\n"));
    
    BLEProv.onWiFiCredentials(std::bind(&WiFiProv::onBleWiFiCredetials, this, std::placeholders::_1));
  
    BLEProv.onAuthCredentials(std::bind(&WiFiProv::onAuthCredetials, this, std::placeholders::_1));
  
    BLEProv.onDeviceInfo(std::bind(&WiFiProv::onDeviceInfo, this));
  
    BLEProv.onBleProvDone(std::bind(&WiFiProv::onBleProvDone, this));
    
    String hostName = String();
    hostName.concat(BLE_DEVICE_PREFIX); // DO NOT CHANGE
    hostName.concat(BLE_PRODUCT_PREFIX);
    hostName.concat(String(ProvUtil::getChipId32(), HEX));
    
    BLEProv.begin(hostName);
    DEBUG_PROV(PSTR("[WiFiProv.startBLEConfig()]: Waiting for credentials. BLE Name: [%s]\r\n"), hostName.c_str()); 
 Serial.print(".");
    unsigned long start = millis();
    bool didTimeout = false;
    bool intteruped = false;
#define SW1_RELAY_PIN  33   //Light2
#define SW2_RELAY_PIN  32   //Light5
#define SW3_RELAY_PIN  27    //Light3
#define SW4_RELAY_PIN  12   //Socket
#define SW5_RELAY_PIN  4   //Light4
#define SW6_RELAY_PIN  2 //Light1 or Power Relay
#define SW7_RELAY_PIN  15 //Light1 or Power Relay



unsigned int p;

bool button1PowerState = false;
bool button2PowerState = false;
bool button3PowerState = false;
bool button4PowerState = false;
bool button5PowerState = false;
bool button6PowerState = false;
bool button7PowerState = false;


bool rele1;
bool rele2;
bool rele3;
bool rele4;
bool rele5;
bool rele6;
bool rele7;
 pinMode(SW1_RELAY_PIN, OUTPUT);
  pinMode(SW2_RELAY_PIN, OUTPUT);
  pinMode(SW3_RELAY_PIN, OUTPUT);
  pinMode(SW4_RELAY_PIN, OUTPUT);
  pinMode(SW5_RELAY_PIN, OUTPUT);
  pinMode(SW6_RELAY_PIN, OUTPUT);
 pinMode(SW7_RELAY_PIN, OUTPUT);

 

    touch1();
    while (1) {
     
         delay(5); 
      //Serial.print(".W");
      //digitalWrite(LEDPin,HIGH);
  
 touch1();
  

      if (BLEProv.bleConfigDone()) {

        DEBUG_PROV(PSTR("[WiFiProv.startBLEConfig()]: BLE setup completed!\r\n")); 
        break;
      }
      
      intteruped = (ProvState::getInstance()->state == ProvState::MODE_INTERRUPT);
      didTimeout = (millis() > start + BLE_CONFIG_TIMEOUT);

      if ( intteruped) {
         BLEProv.stop(); 
         delay(1000);         
         DEBUG_PROV(PSTR("[WiFiProv.startBLEConfig()]: BLE config timed out!\r\n"));  
         break;
        } 
    }    
    return ((didTimeout || intteruped) == true ? false : true);
   #endif
}

/**
* @brief Notify the app that WiFi connection is success. For ESP8266 only.
*/ 
void WiFiProv::notifySuccess() {
  WiFiUDP udp;
  IPAddress ipMulti(239, 255, 255, 250);  
  String sendstr = WiFi.localIP().toString() + ";" + ProvUtil::getMacAddress(); 
  DEBUG_PROV(PSTR("[WiFiProv.notifySuccess()]: Notify payload: %s\r\n"), sendstr.c_str());
    
  for(int i = 0; i < 10; i++){     
    #ifdef ESP32
        udp.beginMulticast(ipMulti, SC_NOTIFICATION_PORT);
        udp.beginMulticastPacket();
        udp.print(sendstr);
        udp.endPacket();  
    #else
      udp.beginPacket(ipMulti, SC_NOTIFICATION_PORT);
      udp.print(sendstr);
      udp.endPacket();
    #endif

    delay(500);
  }

  DEBUG_PROV(PSTR("[WiFiProv]: Notify success!\r\n"));
}

/**
 * @brief Start smartconfig and wait-until timeout.
 * @return ok
 */ 
bool WiFiProv::startSmartConfig() {
  #if defined(ESP8266)
    DEBUG_PROV(PSTR("[WiFiProv.startSmartConfig()]: Starting provisioning using SmartConfig\r\n"));  
    WiFi.disconnect(true); delay(1000);
   
    WiFi.mode(WIFI_STA);
    DEBUG_PROV(PSTR("[Util.startSmartConfig()]: Set WiFi sleep mode to non-sleep..\r\n"));
    WiFi.setSleepMode(WIFI_NONE_SLEEP);
    
    m_smartConfigProv.beginSmartConfig();
  
    unsigned long start = millis();
    bool didTimeout = false;
    bool intteruped = false;

      

    while (1) {
      delay(200);

 

      DEBUG_PROV(PSTR(".W"));  
     // serialdata();
      if (m_smartConfigProv.smartConfigDone()){
        delay(1000);
        break;
      }
      
      didTimeout = (millis() > start + SMARTCONFIG_TIMEOUT);
      intteruped = (ProvState::getInstance()->state == ProvState::MODE_INTERRUPT);

      //if (didTimeout || intteruped) {
        if (intteruped) {
         m_smartConfigProv.stopSmartConfig();
         delay(1000);
          
         DEBUG_PROV(PSTR("[WiFiProv.startSmartConfig()]: SmartConfig timed out or intteruped!\r\n"));  
         break;
      }
    }
  
    if (didTimeout || intteruped) {
       return false;
    } else {
      bool isConnected = (WiFi.status() == WL_CONNECTED);
      
      DEBUG_PROV(PSTR("\r\n"));  
      DEBUG_PROV(PSTR("[WiFiProv.startSmartConfig()]: Smartconfig done!\r\n"));   
      DEBUG_PROV(PSTR("WiFi connected? %s, WiFi IP: %s\r\n"), isConnected? "Yes" : "No",  WiFi.localIP().toString().c_str());
      
      if (!WiFi.localIP().isSet()) { // If IP not set, network is not ready. wait.
        DEBUG_PROV(PSTR("[WiFiProv.startSmartConfig()]: Invalid IP detected. Waiting for IP..\r\n"));
  
        while (!WiFi.localIP().isSet()) {
          delay(500); 
        }

        isConnected = true;
      }
       
      if(isConnected) {
        DEBUG_PROV(PSTR("[WiFiProv.startSmartConfig()]: WiFi Connected.\r\n"));                  
        notifySuccess();  
        return true;
      } else {
        DEBUG_PROV(PSTR("[WiFiProv.startSmartConfig()]: Invalid IP address. Erase the ESP and restarting...!\r\n"));  
        WiFi.disconnect(true);   
        WiFi.begin("0","0"); // adding this effectively seems to erase the previous stored SSID/PW
        restart();
      }
    }
  #else
    DEBUG_PROV(PSTR("[WiFiProv.startSmartConfig()]: ESP32 not supported...!\r\n")); 
    return false;
  #endif
}


/**
 * @brief Restart the ESP module
 */
void WiFiProv::restart() {
  DEBUG_PROV(PSTR("[WiFiProv.restart()]: Restarting ESP ..\r\n"));
  ESP.restart();
  while(1){}  
}
