#pragma once 
 
#include <ArduinoJson.h>
#include "lib/ProvUtil.h"
 
// Adjust accordingly
#define FIRMWARE_VERSION                "1.1.4"         // Firmware version.

#define AP_HOSTNAME                     "PROV_"         // SoftAP perfix.
#define SMARTCONFIG_TIMEOUT             60000 * 10      // SmartConfig wait timeout. Afterwards fallback to AP mode setup
#define BLE_CONFIG_TIMEOUT              60000 * 10      // BLE config wait timeout. Afterwards fallback to AP mode setup
#define BLE_PRODUCT_PREFIX              ""              // BLE device prefix.

#define OTA_CHECK_INTERVAL              60000 * 60 * 2 // Default: Once a day!. Do not change to lower values unless for testing
//#define OTA_ENABLE
//#define ENABLE_LED_INDICATOR                          // Enable LED indicator. 
//#define ENABLE_RESET_BUTTON                           // Enable Reset button during provisioning.

#if defined(ENABLE_LED_INDICATOR)
  //#define BOARD_LED_PIN               16        // Set LED pin - if you have a single-color LED attached
  //#define BOARD_LED_PIN_R             21        // Set R,G,B pins - if your LED is PWM RGB 
  //#define BOARD_LED_PIN_G             22
  //#define BOARD_LED_PIN_B             23
  //#define BOARD_LED_PIN_WS2812          8         // Set if your LED is WS2812 RGB
  
  #define BOARD_LED_INVERSE             false     // true if LED is common anode, false if common cathode
  #define BOARD_LED_BRIGHTNESS          64        // 0..255 brightness control  
  #define BOARD_PWM_MAX                 1023

  #if defined(ESP32)
    #define LEDC_CHANNEL_1              1
    #define LEDC_CHANNEL_2              2
    #define LEDC_CHANNEL_3              3
    #define LEDC_TIMER_BITS             10
    #define LEDC_BASE_FREQ              12000
  #endif
  
  #define USE_TICKER // Use Ticker library for animations
#endif

#if defined(ENABLE_RESET_BUTTON)
  #define BOARD_BUTTON_PIN            0     // Pin where user button is attached
  #define BOARD_BUTTON_ACTIVE_LOW     true  // true if button is "active-low"
  #define BUTTON_HOLD_TIME_INDICATION 3000 // hold-wait time to change the indicator. (going to take an action)
  #define BUTTON_HOLD_TIME_ACTION     5000 // hold time to take the action (since above indication). 
  #define BUTTON_INTERRUPT_PRESS_COUNT   3 // press 3 times to exit the current provisionig (SmartConfig or BLE) mode to enter AP mode. 
#endif

// DO NOT CHANGE ! 
#define PROV_VERSION                  "13"                  // Sketch version. DO NOT CHANGE
#define API_HOST                      "api.marvinno.in"  
#define OTA_HOST                      "ota.marvinno.in"
#define OTA_SERVER_PORT               80
#define OTA_HTTP_TIMEOUT              30000                 // OTA HTTP connect timeout.
#define HTTP_SERVER_PORT              80                    // HTTP Server port for AP mode
#define BLE_DEVICE_PREFIX             "PROV_"               // Must start with PROV_ 
#define SC_CONFIG_FILE                "/pconfig.json"       // product configuration file 
#define SC_NOTIFICATION_PORT          1982                  // Port to notify back to app.
#define STATIC_IP                     { 192, 168, 4,   1 }  // SoftAP mode IP
#define GATEWAY                       { 192, 168, 4,   1 }
#define SUBNET                        { 255, 255, 255, 0 }
#define PROV_HTTP_REQUEST_SECRET      "7075746120"          // Used to sign auto configure http requests
#define OTA_SECRET                    "7075746120"          // Used to answer challenge
//#define OTA_ENABLE                    

#if defined(ESP32)
  #if defined(OTA_ENABLE)
    #define SECURE_OTA // Enable HTTPS OTA updates on ESP32
  #endif
#elif defined(ESP8266)
  #define UNSECURE_API                true // AP mode API calls to server over http for ESP8266.
  #define API_UNSECURE_PORT           80   // HTTP API Port.
#endif

// for SmartConfig WiFi password decryption.
static const uint8_t SMARTCONFIG_CIPHER_KEY [16] = {0x06, 0xa9, 0x21, 0x40, 0x36, 0xb8, 0xa1, 0x5b, 0x51, 0x2e, 0x03, 0xd5, 0x34, 0x12, 0x00, 0x06};
static const uint8_t SMARTCONFIG_CIPHER_IV  [16] = {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01};

#if defined(ModuleS1)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleS1"
#elif defined(ModuleS2)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleS2"
#elif defined(ModuleP)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleP"
#elif defined(ModuleE)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleE"
#elif defined(ModuleC)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleC"
#elif defined(ModuleT)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleT"
#elif defined(ModuleR)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleR"
#elif defined(ModuleU)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleU"
#elif defined(ModuleM1)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleM1"
#elif defined(ModuleM2)
  #define PRODUCT_CODE                  "marvinno.products.types.ModuleM2"
#endif

#define SWITCH_PRODUCT_CODE             "sinric.devices.types.SWITCH" 
#define BLIND_PRODUCT_CODE              "sinric.devices.types.BLIND" 
#define FAN_PRODUCT_CODE                "sinric.devices.types.FAN" 
#define CUSTOM_PRODUCT_CODE             "sinric.devices.types.CUSTOM" 

/**
* @brief Product structure setup.
* @return
*      Product setup
*/
String getProductStructure() { 
  DynamicJsonDocument doc(2048);
  String chipId = String(ProvUtil::getChipId32(), HEX);
    
  JsonObject productInfo = doc.createNestedObject(F("productInfo"));
  productInfo[F("type")] = PRODUCT_CODE;  
  productInfo[F("chipId")] = chipId;
  productInfo[F("bssid")] = ProvUtil::getMacAddress();

  JsonArray devices = doc.createNestedArray(F("devices"));
  
  #if defined(ModuleS1)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;

  #elif defined(ModuleS2)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;
    
  #elif defined(ModuleP)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;
    
  #elif defined(ModuleE)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device3 = devices.createNestedObject();
    device3[F("name")] = "cd1_id"; 
    device3[F("code")] = CUSTOM_PRODUCT_CODE;
    device3[F("productId")] = "6219f3ec888e5fd927f06d16"; 
    
  #elif defined(ModuleC)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "blnd1_id"; 
    device1[F("code")] = BLIND_PRODUCT_CODE;
    
  #elif defined(ModuleT)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;
    
  #elif defined(ModuleR)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device3 = devices.createNestedObject();
    device3[F("name")] = "sw3_id"; 
    device3[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device4 = devices.createNestedObject();
    device4[F("name")] = "sw4_id"; 
    device4[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device5 = devices.createNestedObject();
    device5[F("name")] = "sw5_id"; 
    device5[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device6 = devices.createNestedObject();
    device6[F("name")] = "sw6_id"; 
    device6[F("code")] = SWITCH_PRODUCT_CODE;
    
  #elif defined(ModuleU)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device3 = devices.createNestedObject();
    device3[F("name")] = "sw3_id"; 
    device3[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device4 = devices.createNestedObject();
    device4[F("name")] = "sw4_id"; 
    device4[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device5 = devices.createNestedObject();
    device5[F("name")] = "fan1_id"; 
    device5[F("code")] = FAN_PRODUCT_CODE;
    
  #elif defined(ModuleM1)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device3 = devices.createNestedObject();
    device3[F("name")] = "sw3_id"; 
    device3[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device4 = devices.createNestedObject();
    device4[F("name")] = "sw4_id"; 
    device4[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device5 = devices.createNestedObject();
    device5[F("name")] = "sw5_id"; 
    device5[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device6 = devices.createNestedObject();
    device6[F("name")] = "sw6_id"; 
    device6[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device7 = devices.createNestedObject();
    device7[F("name")] = "fan1_id"; 
    device7[F("code")] = FAN_PRODUCT_CODE;
    
  #elif defined(ModuleM2)
    JsonObject device1 = devices.createNestedObject();
    device1[F("name")] = "sw1_id"; 
    device1[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device2 = devices.createNestedObject();
    device2[F("name")] = "sw2_id"; 
    device2[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device3 = devices.createNestedObject();
    device3[F("name")] = "sw3_id"; 
    device3[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device4 = devices.createNestedObject();
    device4[F("name")] = "sw4_id"; 
    device4[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device5 = devices.createNestedObject();
    device5[F("name")] = "sw5_id"; 
    device5[F("code")] = SWITCH_PRODUCT_CODE;
  
    JsonObject device6 = devices.createNestedObject();
    device6[F("name")] = "sw6_id"; 
    device6[F("code")] = SWITCH_PRODUCT_CODE;

    JsonObject device7 = devices.createNestedObject();
    device7[F("name")] = "fan1_id"; 
    device7[F("code")] = FAN_PRODUCT_CODE;
  #endif
   
  String data = "";
  serializeJson(doc, data);
 
  return data;
}
 
 
