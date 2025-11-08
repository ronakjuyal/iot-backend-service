
/*
  Copyright (c) 2019-2021 Sinric Pro

  The copyright in these pages (including without limitation all text, graphics and computer code relating thereto or associated therewith)
  and all other intellectual property and proprietary rights therein belongs to Sinric Pro and all rights are reserved.

  Permission is given for the downloading and temporary storage of one or more of these pages for the sole purpose of viewing them on a stand-alone personal computer or monitor.
  Permanent copying or redistribution, or reproduction of all or part of this library in any form is strictly prohibited without express permission of Sinric Pro.
*/

// Works with ESP8266/ESP32 only  // handle button press comment

// Notes:

//  1. Factory reset PIN is connected to GPIO 0

// Dependencies
//  1. ESP8266 Core   v3.0.2 / ESP32 Core 2.0.1
//  2. WebSockets     v2.3.5 https://github.com/Links2004/arduinoWebSockets
//  3. arduinoJson    v6.18.5 https://github.com/bblanchon/ArduinoJson
//  4. ESP32:         v1.3.7 NimBLE  https://github.com/h2zero/NimBLE-Arduino

// To enable Logs in ESP8266:
//  Tools -> Debug Serial Port -> Serial
//  Tools -> Flash Size -> 4MB (FS:1MB OTA:~1019KB)
//        -> Debug Level -> HTTP_CLIENT ** for AP issues (Optional)
//        -> Debug Level -> HTTP_UPDATE ** for OTA update issues (Optional)
// To enable Logs in ESP32:
//  Tools -> Flash Size -> Minimun SPIFF
//  Tools -> Core Debug Level -> Verbose

#if defined(ESP8266)
//  #define ModuleS1
//  #define ModuleS2
//  #define ModuleP
//  #define ModuleT
//    #define ModuleM2
#elif defined(ESP32)
//  #define ModuleE
//  #define ModuleC

//  #define ModuleM1
#define ModuleU
#endif


#define ENABLE_DEBUG  // Enable Logs.

#if defined(ESP8266)
// Disable SSL on ESP8266 due to memory limitations
#define SINRICPRO_NOSSL
#endif

#ifdef ENABLE_DEBUG
#define DEBUG_ESP_PORT Serial
#define NODEBUG_WEBSOCKETS
#define NDEBUG
#define DEBUG_PROV_LOG  // Print provisioning debug logs
#endif

#include <Arduino.h>

#ifdef ESP32
#include <WiFi.h>
#include <Preferences.h>
#include "SPIFFS.h"
#else
#include <ESP8266WiFi.h>
#endif

#include "Settings.h"  // Must be above SinricPro.h

#include <SinricPro.h>
#include <SinricProConfig.h>
#include <SinricProSwitch.h>
#include <SinricProBlinds.h>
#include <SinricProFanUS.h>
#include "WaterTank.h"
#include <EEPROM.h>
#include <lvgl.h>
#include <Arduino.h>
#define LGFX_USE_V1
#include "ui.h"
#include <LovyanGFX.hpp>

#if !defined(SINRICPRO_VERISON_INT) || (SINRICPRO_VERISON_INT < 2009013)
#error "Requires SinricPro SDK Version 2.9.13 or newer!!!"
#endif

#include "ConfigStore.h"
#include "lib/ProvUtil.h"
#include "lib/WiFiProv.h"
#include "lib/OTAUpdater.h"

#define BAUDRATE 115200
//#define DEVICE_RESET_PIN  0
//#define rst_pin 25

#define SW1_RELAY_PIN 33  //Light2
#define SW2_RELAY_PIN 32  //Light5
#define SW3_RELAY_PIN 27  //Light3
#define SW4_RELAY_PIN 26   //Socket
#define SW5_RELAY_PIN 2   //Light4
#define SW6_RELAY_PIN 5  //Light1 or Power Relay
#define SW7_RELAY_PIN 25  //Light1 or Power Relay



void speed1();
void touch1();
void resetting(void);
//void eeprem(void);
//void eepromupdate(void);

DeviceConfig config;

#if defined(OTA_ENABLE)
OTAUpdater otaUpdater;
#endif
int check1 = 0;
int p;
int fanState = 0;
bool recState = 0;
bool recRange = 0;
bool button1PowerState = false;
bool button2PowerState = false;
bool button3PowerState = false;
bool button4PowerState = false;
bool button5PowerState = false;
bool button6PowerState = false;
bool button7PowerState = false;
unsigned int fanIndex = 0;
unsigned long lastBtn1Press = 0;
unsigned long lastBtn2Press = 0;
unsigned long lastBtn3Press = 0;
unsigned long lastBtn4Press = 0;
unsigned long lastBtn5Press = 0;
unsigned long lastBtn6Press = 0;
unsigned long lastBtn7Press = 0;

bool relay1;
bool relay2;
bool relay3;
bool relay4;
bool fans;
int roller_index1;
int first_update=1;
bool flag=true;

//////////////////diplay config////////////////


class LGFX : public lgfx::LGFX_Device {
  lgfx::Panel_ST7796 _panel_instance;
  lgfx::Bus_SPI _bus_instance;  
  lgfx::Light_PWM _light_instance;
  lgfx::Touch_FT5x06 _touch_instance;  
public:

  LGFX(void) {
    {
      auto cfg = _bus_instance.config(); 
      cfg.spi_host = VSPI_HOST;          
      cfg.spi_mode = 0;                  
      cfg.freq_write = 40000000;       
      cfg.freq_read = 16000000;           
      cfg.spi_3wire = false;              
      cfg.use_lock = true;               
      cfg.dma_channel = 1;               
    
      cfg.pin_sclk = 14;                       
      cfg.pin_mosi = 13;                      
      cfg.pin_miso = -1;                       
      cfg.pin_dc = 21;                        
      _bus_instance.config(cfg);               
      _panel_instance.setBus(&_bus_instance);  
    }

    {                                      
      auto cfg = _panel_instance.config(); 

      cfg.pin_cs = 15;    
      cfg.pin_rst = 22;  
      cfg.pin_busy = -1;  

      cfg.panel_width = 320;     
      cfg.panel_height = 480;   
      cfg.offset_x = 0;         
      cfg.offset_y = 0;          
      cfg.offset_rotation = 0;   
      cfg.dummy_read_pixel = 8;  
      cfg.dummy_read_bits = 1;  
      cfg.readable = true;      
      cfg.invert = false;        
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = true;

     
      cfg.memory_width = 320;  
      cfg.memory_height = 480;  

      _panel_instance.config(cfg);
    }

   
    {                                       
      auto cfg = _light_instance.config();  

      cfg.pin_bl = 23;      
      cfg.invert = false;   
      cfg.freq = 44100;     
      cfg.pwm_channel = 7;  

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);  
    }

    {
      auto cfg = _touch_instance.config();

      cfg.x_min = 0;  
      cfg.x_max = 319;
      cfg.y_min = 0;
      cfg.y_max = 479;
      cfg.pin_int = -1;
      cfg.bus_shared = true;
      cfg.offset_rotation = 0;

      // I2C
      cfg.i2c_port = 1;     
      cfg.i2c_addr = 0x38;  
      cfg.pin_sda = 18;     
      cfg.pin_scl = 19;     
      cfg.freq = 400000;    

      _touch_instance.config(cfg);
      _panel_instance.setTouch(&_touch_instance); 
    }
    //*/

    setPanel(&_panel_instance);  
  }
};


LGFX tft;

static const uint32_t screenWidth = 480;
static const uint32_t screenHeight = 320;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  //tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
  tft.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  tft.endWrite();

  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  uint16_t touchX, touchY;
  bool touched = tft.getTouch(&touchX, &touchY);
  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;

    //      Serial.print( "Data x " );
    //      Serial.println( touchX );
    //
    //      Serial.print( "Data y " );
    //      Serial.println( touchY );
  }
}

/////////////////////////////////////////////////////////

int period = 5000, m = 0, x = 0;
int period1 = 60000;

unsigned long time_now = 0;

bool onPowerState(const String &deviceId, bool &state) {
  Serial.printf("[main.onPowerState()]: Device: %s, power state changed to %s\r\n", deviceId.c_str(), state ? "on" : "off");

  // Handle your power on/off command with device id. Example for ModuleS
  recState = true;
#if defined(ModuleS1)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?

  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?
  }
#elif defined(ModuleS2)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?

  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?
  }
#elif defined(ModuleP)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?

  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?
  }
#elif defined(ModuleE)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?

  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?
  }
#elif defined(ModuleC)
  if (strcmp(config.blnd1_id, deviceId.c_str()) == 0) {  // is for blind
  }
#elif defined(ModuleT)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?

  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?
  }
#elif defined(ModuleR)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?

  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?

  } else if (strcmp(config.sw3_id, deviceId.c_str()) == 0) {  // is for switch 3 ?



  } else if (strcmp(config.sw4_id, deviceId.c_str()) == 0) {  // is for switch 4 ?



  } else if (strcmp(config.sw5_id, deviceId.c_str()) == 0) {  // is for switch 5 ?



  } else if (strcmp(config.sw6_id, deviceId.c_str()) == 0) {  // is for switch 6 ?
  }
#elif defined(ModuleU)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?
    //digitalWrite(SW1_RELAY_PIN, state);
    state?lv_obj_add_state(ui_bulb_Button1, LV_STATE_CHECKED):lv_obj_clear_state(ui_bulb_Button1, LV_STATE_CHECKED);
      lv_event_send(ui_bulb_Button1, LV_EVENT_VALUE_CHANGED, NULL);
  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?
    //digitalWrite(SW2_RELAY_PIN, state);
    state?lv_obj_add_state(ui_bulb_Button2, LV_STATE_CHECKED):lv_obj_clear_state(ui_bulb_Button2, LV_STATE_CHECKED);
    lv_event_send(ui_bulb_Button2, LV_EVENT_VALUE_CHANGED, NULL);
  } else if (strcmp(config.sw3_id, deviceId.c_str()) == 0) {  // is for switch 3 ?
    //digitalWrite(SW3_RELAY_PIN, state);
    state?lv_obj_add_state(ui_bulb_Button3, LV_STATE_CHECKED):lv_obj_clear_state(ui_bulb_Button3, LV_STATE_CHECKED);
    lv_event_send(ui_bulb_Button3, LV_EVENT_VALUE_CHANGED, NULL);
  } else if (strcmp(config.sw4_id, deviceId.c_str()) == 0) {  // is for switch 4 ?
    //digitalWrite(SW4_RELAY_PIN, state);
    state?lv_obj_add_state(ui_bulb_Button4, LV_STATE_CHECKED):lv_obj_clear_state(ui_bulb_Button4, LV_STATE_CHECKED);
    lv_event_send(ui_bulb_Button4, LV_EVENT_VALUE_CHANGED, NULL);
  } else if (strcmp(config.fan1_id, deviceId.c_str()) == 0) {  // is for fan ?
    //lv_event_send(ui_Screen1_Button7,LV_EVENT_CLICKED,NULL);
    state?lv_obj_add_state(ui_Button4, LV_STATE_CHECKED):lv_obj_clear_state(ui_Button4, LV_STATE_CHECKED);
    lv_event_send(ui_Button4, LV_EVENT_VALUE_CHANGED, NULL);
  }
  //digitalWrite(SW7_RELAY_PIN, state);
  else {
    recState = false;
    Serial.printf("[main.onPowerState()]: Devie device: %s not found!\r\n", deviceId.c_str());
  }

#elif defined(ModuleM)
  if (strcmp(config.sw1_id, deviceId.c_str()) == 0) {  // is for switch 1 ?

  } else if (strcmp(config.sw2_id, deviceId.c_str()) == 0) {  // is for switch 2 ?

  } else if (strcmp(config.sw3_id, deviceId.c_str()) == 0) {  // is for switch 3 ?

  } else if (strcmp(config.sw4_id, deviceId.c_str()) == 0) {  // is for switch 4 ?

  } else if (strcmp(config.sw5_id, deviceId.c_str()) == 0) {  // is for switch 5 ?

  } else if (strcmp(config.sw6_id, deviceId.c_str()) == 0) {  // is for switch 6 ?

  } else if (strcmp(config.fan1_id, deviceId.c_str()) == 0) {  // is for fan ?
  }
#endif

  return true;  // request handled properly
}

bool onRangeValue(const String &deviceId, int &position) {
  Serial.printf("Device %s set position to %d\r\n", deviceId.c_str(), position);
  if(position)
    lv_btnmatrix_set_btn_ctrl(btnm1, (position-1), LV_BTNMATRIX_CTRL_CHECKED);
  
  if (position == 4)  // Maximum Speed
    {
       digitalWrite(SW5_RELAY_PIN, HIGH);
       digitalWrite(SW6_RELAY_PIN, LOW);
       digitalWrite(SW7_RELAY_PIN, LOW);

    } else if (position == 3)  //75%
    {
      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, HIGH);
      digitalWrite(SW7_RELAY_PIN, HIGH);

      //    }
    } else if (position== 2)  // 50%
    {
      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, LOW);
      digitalWrite(SW7_RELAY_PIN, HIGH);
    }

    else if (position== 1)  //25%
    {

      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, HIGH);
      digitalWrite(SW7_RELAY_PIN, LOW);

    }
  

  recRange = true;
#if defined(ModuleU)

#elif defined(ModuleM1)

#elif defined(ModuleM2)

#endif

  return true;  // request handled properly
}

bool onAdjustRangeValue(const String &deviceId, int &positionDelta) {
  Serial.printf("Device %s position changed %i\r\n", deviceId.c_str(), positionDelta);
#if defined(ModuleU)

#elif defined(ModuleM1)

#elif defined(ModuleM2)

#endif

  return true;  // request handled properly
}

void setWiFi(const char *ssid, const char *password) {
  Serial.printf("[main.setWiFi()]: Disconnect from current WiFi.\r\n");
  WiFi.disconnect();
  WiFi.persistent(false);

  Serial.printf("[main.setWiFi()]: Connecting to new WiFi:%s .\r\n", ssid);
  WiFi.begin(ssid, password);

  uint64_t start = millis();
  int timeout = 20 * 1000;  // 20 seconds
  touch1();
  while (WiFi.status() != WL_CONNECTED) {
    delay(10);
    Serial.print(".");
    touch1();
    if (millis() - start > timeout) {
      break;
    }
  }

  Serial.printf("\r\n");

  if (WiFi.status() == WL_CONNECTED) {
    Serial.printf("[main.setWiFi()]: Connect success! Save new WiFi.\r\n");
    WiFi.persistent(true);
    WiFi.setAutoReconnect(true);
  } else {
    Serial.printf("[main.setWiFi()]: Connect failed.. Connect to last known WiFi.\r\n");
    touch1();
    ProvUtil::setupWiFi();  // Connect to Old WiFi..
  }
}

bool onSetSetting(const String &deviceId, const String &settingId, const String &settingValue) {
  Serial.printf("[main.onSetSetting()]: Device: %s, id: %s, value: %s\r\n", deviceId.c_str(), settingId.c_str(), settingValue.c_str());

  if (settingId.equals("setWiFi")) {
    StaticJsonDocument<128> doc;
    DeserializationError error = deserializeJson(doc, settingValue);

    if (error) {
      Serial.print(F("[main.onSetSetting()]: deserializeJson() failed: "));
      Serial.println(error.f_str());
      return false;
    }

    const char *ssid = doc[F("ssid")];          // "wifi"
    const char *password = doc[F("password")];  // "password"
    setWiFi(ssid, password);
  }

  return true;
}

/**
   Setup devices.
*/
void setupSinricPro() {
#if defined(ModuleS1)
  Serial.printf("[setupSinricPro()]: Setup Module S1!\r\n");
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

#elif defined(ModuleS2)
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

#elif defined(ModuleP)
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

#elif defined(ModuleE)
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

  WaterTank &waterTank = SinricPro[config.cd1_id];
  // How to update the water level:
  //  waterTank.sendRangeValueEvent("rangeInstance1", 50); // 50%
  // Alexa, what is the water tank (device name) water level ?

#elif defined(ModuleC)
  SinricProBlinds &myBlinds = SinricPro[config.blnd1_id];
  myBlinds.onPowerState(onPowerState);
  myBlinds.onRangeValue(onRangeValue);
  myBlinds.onAdjustRangeValue(onAdjustRangeValue);

#elif defined(ModuleT)
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

#elif defined(ModuleR)
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch3 = SinricPro[config.sw3_id];
  mySwitch3.onPowerState(onPowerState);
  mySwitch3.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch4 = SinricPro[config.sw4_id];
  mySwitch4.onPowerState(onPowerState);
  mySwitch4.onSetSetting(onSetSetting);


  SinricProSwitch &mySwitch5 = SinricPro[config.sw5_id];
  mySwitch5.onPowerState(onPowerState);
  mySwitch5.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch6 = SinricPro[config.sw6_id];
  mySwitch6.onPowerState(onPowerState);
  mySwitch6.onSetSetting(onSetSetting);

#elif defined(ModuleU)
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch3 = SinricPro[config.sw3_id];
  mySwitch3.onPowerState(onPowerState);
  mySwitch3.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch4 = SinricPro[config.sw4_id];
  mySwitch4.onPowerState(onPowerState);
  mySwitch4.onSetSetting(onSetSetting);

  SinricProFanUS &myFan = SinricPro[config.fan1_id];
  myFan.onPowerState(onPowerState);
  myFan.onRangeValue(onRangeValue);
  myFan.onAdjustRangeValue(onAdjustRangeValue);

#elif defined(ModuleM)
  SinricProSwitch &mySwitch1 = SinricPro[config.sw1_id];
  mySwitch1.onPowerState(onPowerState);
  mySwitch1.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch2 = SinricPro[config.sw2_id];
  mySwitch2.onPowerState(onPowerState);
  mySwitch2.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch3 = SinricPro[config.sw3_id];
  mySwitch3.onPowerState(onPowerState);
  mySwitch3.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch4 = SinricPro[config.sw4_id];
  mySwitch4.onPowerState(onPowerState);
  mySwitch4.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch5 = SinricPro[config.sw5_id];
  mySwitch5.onPowerState(onPowerState);
  mySwitch5.onSetSetting(onSetSetting);

  SinricProSwitch &mySwitch6 = SinricPro[config.sw6_id];
  mySwitch6.onPowerState(onPowerState);
  mySwitch6.onSetSetting(onSetSetting);

  SinricProFanUS &myFan = SinricPro[config.fan1_id];
  myFan.onPowerState(onPowerState);
  myFan.onRangeValue(onRangeValue);
  myFan.onAdjustRangeValue(onAdjustRangeValue);
#else
  DEBUG_PROV(PSTR("ERROR! Module not found! \r\n"));
#endif

  SinricPro.onConnected([]() {
    Serial.printf("[main.setupSinricPro()]: Connected to marvinno\r\n");
  });
  SinricPro.onDisconnected([]() {
    Serial.printf("[main.setupSinricPro()]: Disconnected from marvinno\r\n");
  });
  SinricPro.begin(config.appKey, config.appSecret, "ws.marvinno.in");
}


/**
   Setup PINs for devices.
*/
void setupPins() {
  Serial.printf("[main.setupPins()]: Setup pin definition.\r\n");
  //  pinMode(DEVICE_RESET_PIN, INPUT_PULLUP);

  pinMode(SW1_RELAY_PIN, OUTPUT);
  pinMode(SW2_RELAY_PIN, OUTPUT);
  pinMode(SW3_RELAY_PIN, OUTPUT);
  pinMode(SW4_RELAY_PIN, OUTPUT);
  pinMode(SW5_RELAY_PIN, OUTPUT);
  pinMode(SW6_RELAY_PIN, OUTPUT);
  pinMode(SW7_RELAY_PIN, OUTPUT);
}

void setup() {

  Serial.begin(BAUDRATE);
  Serial.println();
  delay(1000);
  EEPROM.begin(512);
  uint64_t start = millis();
  int timeout1 = 60 * 60 * 1000;  // 20 seconds
  // eeprem();
  //      digitalWrite(SW5_RELAY_PIN,LOW);
  //      digitalWrite(SW6_RELAY_PIN,LOW);
  tft.begin();
  tft.setRotation(1);
  tft.setBrightness(255);
  //uint16_t calData[] = { 0, 28, 0, 474, 319, 13, 319, 476 };
  //tft.setTouchCalibrate(calData);

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();


  Serial.printf("[main.setup()]: Firmware v:%s, SinricPro SDK v:%s, Prov:v:%s\r\n", FIRMWARE_VERSION, SINRICPRO_VERSION, PROV_VERSION);

  Serial.printf("[main.setup()]: Initialize SPIFFS...\r\n");

#ifdef ESP32
  if (SPIFFS.begin(true)) {
    Serial.println(F("[main.setup()]: done."));
  } else {
    Serial.println(F("[main.setup()]: fail."));
  }
#else
  if (SPIFFS.begin()) {
    Serial.println(F("[main.setup()]: done."));
  } else {
    Serial.println(F("[main.setup()]: fail."));
  }
#endif

  delay(1000);

  WiFiProv prov(config);

  if (!prov.hasProvisioned()) {
    Serial.printf("[main.setup()]: Begin provisioning!\r\n");
    prov.beginProvision();
  } else {
    Serial.printf("[main.setup()]: Already provisioned!\r\n");

    Serial.printf("[main.setup()]: Setup Pins\r\n");
    //digitalWrite(LEDPin,LOW);
    setupPins();

    // Connect to WiFi
    while (!ProvUtil::setupWiFi()) {
      Serial.printf(PSTR("[main.setup()]: Cannot connect to WiFi any longer. WiFi Router down? Waiting 4 Sec to retry.\r\n"));
      delay(50);
      //  ESP.reset();
      touch1();
      //  if(millis() > time_now + period){
      //      time_now = millis();
      //      ESP.reset();
      //  }

      Serial.printf(PSTR("[main.setup()]: Trying again..."));
      if (millis() - start > timeout1) {
        ESP.restart();
      }
    }
  }

  Serial.printf("[main.setup()]: Setup SinricPro!\r\n");
  setupSinricPro();

#if defined(OTA_ENABLE)
  Serial.printf("[main.setup()]: Setup OTA!\r\n");
  otaUpdater.setup();
#endif

  Serial.printf("[main.setup()]: Free Heap: %u\r\n", ESP.getFreeHeap());
  time_now = millis();
}

void handleFullReset() {
  //if (!digitalRead(DEVICE_RESET_PIN)){
  Serial.printf("[main.handleFullReset]: FULL RESET!\r\n");
  Serial.printf("[main.handleFullReset]: DELETING CONFIG!\r\n");

  ConfigStore configStore(config);
  configStore.clear();

  Serial.printf("[main.handleFullReset]: REBOOT\r\n");
  ESP.restart();
  //}
}

void eprom() {
  relay1 = EEPROM.read(0);
  if (relay1) {
    lv_obj_add_state(ui_bulb_Button1, LV_STATE_CHECKED);
    lv_event_send(ui_bulb_Button1, LV_EVENT_VALUE_CHANGED, NULL);
  }
  relay2 = EEPROM.read(1);
  if (relay2) {
    lv_obj_add_state(ui_bulb_Button2, LV_STATE_CHECKED);
    lv_event_send(ui_bulb_Button2, LV_EVENT_VALUE_CHANGED, NULL);
  }
  relay3 = EEPROM.read(2);
  if (relay3) {
    lv_obj_add_state(ui_bulb_Button3, LV_STATE_CHECKED);
    lv_event_send(ui_bulb_Button3, LV_EVENT_VALUE_CHANGED, NULL);
  }
  relay4 = EEPROM.read(3);
  if (relay4) {
    lv_obj_add_state(ui_bulb_Button4, LV_STATE_CHECKED);
    lv_event_send(ui_bulb_Button4, LV_EVENT_VALUE_CHANGED, NULL);
  }
   fans = EEPROM.read(4);
  if (fans) {
    lv_obj_add_state(ui_Button4, LV_STATE_CHECKED);
    lv_event_send(ui_Button4, LV_EVENT_VALUE_CHANGED, NULL);
  }
  roller_index1=  EEPROM.read(5);
}
void touch1() {
   if (first_update) {
    first_update = false;
     eprom();
   }
  get_states();
  lv_timer_handler();
  //Serial.printf("%d %d \n",(int)states.led1,(int)states.led2);
  if (button1PowerState != states.led1) {  // is button pressed (inverted logic! button pressed = LOW) and debounced?
    button1PowerState = states.led1;
    digitalWrite(SW1_RELAY_PIN, button1PowerState ? HIGH : LOW);  // if myPowerState indicates device turned on: turn on led (builtin led uses inverted logic: LOW = LED ON / HIGH = LED OFF)
    EEPROM.write(0, button1PowerState);
    EEPROM.commit();

    //   get Switch device back
    SinricProSwitch &mySwitch = SinricPro[config.sw1_id];
    //   send powerstate event
    if (!recState) mySwitch.sendPowerStateEvent(button1PowerState);  // send the new powerState to SinricPro server
    Serial.printf("Device %s turned %s (manually via flashbutton Light 2)\r\n", mySwitch.getDeviceId().c_str(), button1PowerState ? "on" : "off");
  }


  //unsigned long actualMillis = millis(); // get actual millis() and keep it in variable actualMillis

  if (button2PowerState != states.led2) {  // is button pressed (inverted logic! button pressed = LOW) and debounced?
    button2PowerState = states.led2;

    digitalWrite(SW2_RELAY_PIN, button2PowerState ? HIGH : LOW);  // if myPowerState indicates device turned on: turn on led (builtin led uses inverted logic: LOW = LED ON / HIGH = LED OFF)
    EEPROM.write(1, button2PowerState);
    EEPROM.commit();
    // get Switch device back
    SinricProSwitch &mySwitch = SinricPro[config.sw2_id];
    // send powerstate event
    if (!recState) mySwitch.sendPowerStateEvent(button2PowerState);  // send the new powerState to SinricPro server
    Serial.printf("Device %s turned %s (manually via flashbutton Light_5)\r\n", mySwitch.getDeviceId().c_str(), button2PowerState ? "on" : "off");
  }

  if (button3PowerState != states.led3) {  // is button pressed (inverted logic! button pressed = LOW) and debounced?
    button3PowerState = states.led3;
    digitalWrite(SW3_RELAY_PIN, button3PowerState ? HIGH : LOW);  // if myPowerState indicates device turned on: turn on led (builtin led uses inverted logic: LOW = LED ON / HIGH = LED OFF)
    EEPROM.write(2, button3PowerState);
    EEPROM.commit();
    // get Switch device back
    SinricProSwitch &mySwitch = SinricPro[config.sw3_id];
    //  send powerstate event
    if (!recState) mySwitch.sendPowerStateEvent(button3PowerState);  // send the new powerState to SinricPro server
    Serial.printf("Device %s turned %s (manually via flashbutton Light 3)\r\n", mySwitch.getDeviceId().c_str(), button3PowerState ? "on" : "off");
  }
  if (button4PowerState != states.led4) {  // is button pressed (inverted logic! button pressed = LOW) and debounced?
    button4PowerState = states.led4;
    digitalWrite(SW4_RELAY_PIN, button4PowerState ? HIGH : LOW);  // if myPowerState indicates device turned on: turn on led (builtin led uses inverted logic: LOW = LED ON / HIGH = LED OFF)
    EEPROM.write(3, button4PowerState);
    EEPROM.commit();
    // get Switch device back
    SinricProSwitch &mySwitch = SinricPro[config.sw4_id];
    //     send powerstate event
    if (!recState) mySwitch.sendPowerStateEvent(button4PowerState);  // send the new powerState to SinricPro server
    Serial.printf("Device %s turned %s (manually via flashbutton Socket 3)\r\n", mySwitch.getDeviceId().c_str(), button4PowerState ? "on" : "off");


    /*
    while (digitalRead(button4) == HIGH)
    {
      m = m + 1;
      delay(1000);
      Serial.print("In Reset Loop");
      if (digitalRead(button4) == LOW)
      {
        break;
      }
    }
    if (m > 5) {
      Serial.print("hard reset");
      delay(1000);
      digitalWrite(SW4_RELAY_PIN, HIGH);
      delay(500);
      digitalWrite(SW4_RELAY_PIN, LOW);
      delay(500);
      handleFullReset();
      ESP.restart();
    }
    m = 0;
    */
  }

  if (states.fan) {
    Serial.println(states.fan_speed);
    SinricProFanUS &myFan = SinricPro[config.fan1_id];  // is button pressed (inverted logic! button pressed = LOW) and debounced?
    if (button5PowerState != states.fan) {
      button5PowerState = states.fan;
      Serial.print(".................................clicked here...........");
      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, LOW);
      digitalWrite(SW7_RELAY_PIN, HIGH);
      lv_btnmatrix_set_btn_ctrl(btnm1, 1, LV_BTNMATRIX_CTRL_CHECKED);
      if (!recState) {
        myFan.sendPowerStateEvent(button5PowerState);
        EEPROM.write(4, button5PowerState);
        EEPROM.commit();
      }
      myFan.sendRangeValueEvent(button5PowerState ? 2 : 0);
    }
    if (fanIndex != states.fan_speed) {
      Serial.print(".................................clicked here fan speed...........");

      fanIndex = states.fan_speed;
      if (fanIndex == 4)  // Maximum Speed
    {
       digitalWrite(SW5_RELAY_PIN, HIGH);
       digitalWrite(SW6_RELAY_PIN, LOW);
       digitalWrite(SW7_RELAY_PIN, LOW);

    } else if (fanIndex == 3)  //75%
    {
      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, HIGH);
      digitalWrite(SW7_RELAY_PIN, HIGH);

      //    }
    } else if (fanIndex== 2)  // 50%
    {
      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, LOW);
      digitalWrite(SW7_RELAY_PIN, HIGH);
    }

    else if (fanIndex== 1)  //25%
    {

      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, HIGH);
      digitalWrite(SW7_RELAY_PIN, LOW);

    }
    else if (fanIndex== 0) // 0%
    {

      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, LOW);
      digitalWrite(SW7_RELAY_PIN, LOW);

    }
    EEPROM.write(5, fanIndex);
    EEPROM.commit();
      if (!recRange) myFan.sendRangeValueEvent(fanIndex);
    }  // send the new powerState to SinricPro server
       //Serial.printf("Device %s turned %s (manually via flashbutton Socket 3)\r\n", myFan.getDeviceId().c_str(), button5PowerState ? "on" : "off");
  } else {
    if (button5PowerState != states.fan) {
      digitalWrite(SW5_RELAY_PIN, LOW);
      digitalWrite(SW6_RELAY_PIN, LOW);
      digitalWrite(SW7_RELAY_PIN, LOW);      
      button5PowerState = states.fan;
      SinricProFanUS &myFan = SinricPro[config.fan1_id];
      if (!recState) {
        myFan.sendPowerStateEvent(0);
        EEPROM.write(4, button5PowerState);
        EEPROM.commit();
      }
    }
  }
  //  if (states.fan)  {
  //     if(fanState!=states.fan_speed){
  //       fanState=states.fan_speed;
  //     }
  //   } // is button pressed (inverted logic! button pressed = LOW) and debounced?



  //    SinricProFanUS &myFan = SinricPro[config.fan1_id];


  //     Serial.printf("Device %s turned %s (manually via flashbutton Light_4)\r\n", myFan.getDeviceId().c_str(), button5PowerState ? "on" : "off");
  //     Serial.println("FAN DOWN");

  //        if(p==128)
  //    {
  //    p=128;
  //    }
  //    else
  //    {
  //     p=p+32;
  //     check1=0;


  //    }
  //   speed1();
  //   }
  recState = false;
  recRange = false;
}


void loop() {

  touch1();

  SinricPro.handle();
  if (WiFi.status() != WL_CONNECTED) {

    ESP.restart();
  }

#if defined(OTA_ENABLE)
  otaUpdater.handleCheckAndUpdate();
#endif

  if (millis() > time_now + period) {
    time_now = millis();
    Serial.printf("[main.loop]: Free Heap: %u\r\n", ESP.getFreeHeap());
  }
}


// void loop()
// {
//   if(lv_disp_get_inactive_time(NULL) > 15000 and !sleep_flag) {
//     sleep_flag=1;
//     lv_obj_add_state(ui_bulb_Button1, LV_STATE_CHECKED);
//     lv_event_send(ui_bulb_Button1, LV_EVENT_VALUE_CHANGED, NULL);
// 	  //lv_disp_load_scr(ui_Screen3);
//     }
//     else sleep_flag=0;
//     lv_timer_handler(); /* let the GUI do its work */
//     delay(5);
// }
