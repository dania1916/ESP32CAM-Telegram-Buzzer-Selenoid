#include <Arduino.h>

#include <ArduinoJson.h>
#include "self_gpio.h"
#include "self_sdcard.h"
#include "soc/soc.h"             
#include "soc/rtc_cntl_reg.h"
#include "camera_pins.h"

#include "camera_server.h"
//#include "tele.h"
#include "self_wifi.h"
//#include "send2tele.h"
#include <WiFiClientSecure.h>

#define PHOTO 12 //emg g dipasang
//#define BUZZER 2
//#define LOCK 14 //kyknya relay
//int IRSensor = 15;

void setup() {
    pinMode(12, INPUT_PULLUP);
    //pinMode (IRSensor, INPUT);
    //pinMode(LOCK,OUTPUT);
    //pinMode(BUZZER,OUTPUT);
    //digitalWrite(BUZZER,LOW);
    //digitalWrite(LOCK,LOW);
    Serial.begin(115200);
    Serial.setDebugOutput(true);  
    Serial.println();

    //gpio_init_system();
    wifi_init_system();
    // sdmmc_init_system();
//    startTele();
    camera_init_system();

    // testing
    camera_set_server(START_CAMERA_SERVER);
//    sendMessage2Telegram(BOT_TOKEN, CHAT_ID, "Cobain bisa ga ya?");
 //sendCapturedImage2Telegram(BOT_TOKEN, CHAT_ID);
}

void loop() {
//int sensorStatus = digitalRead(IRSensor);
//
//if(controlState==true && activateRelay==false)
//{
// activateRelay=true;
// digitalWrite(LOCK,LOW);
// //gpio_init_system();
// Serial.println("Valid Masuk, aja");
// prevMillis=millis();
// }
//
//if (controlState == true && millis()-prevMillis > interval)
// {
// activateRelay=false;
// controlState=false;
// digitalWrite(LOCK,LOW);
// }
//
//
//if (sensorStatus == 0){
//  digitalWrite(BUZZER, HIGH);
//  bot.sendMessage(CHAT_ID, "Hati-hati ada objek mencurigakan");
//  Serial.println("Objek Terdeteksi!!");
//  sendCapturedImage2Telegram(BOT_TOKEN, CHAT_ID);
//  }
//  if (sensorStatus == 1){
//  digitalWrite(BUZZER, LOW);
//  }
//  if (digitalRead(PHOTO) == HIGH){
//  Serial.println("Capture Photo");
//  takePhoto();
//  sendCapturedImage2Telegram(BOT_TOKEN, CHAT_ID);
//  }
//  if(digitalRead(LOCK) == HIGH){
//  bot.sendMessage(CHAT_ID, "Oalah ternyata kamu si pemilik rumah");
//  digitalWrite(BUZZER, LOW);
// }
}
