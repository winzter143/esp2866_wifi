/*
 * This will deauthenticate some users from the network
 * Pin 13 Port B
 */
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include "APScan.h"

//#include <ESP8266WebServer.h>
//ESP8266WebServer server(80);

#define BUILTIN_LED 2
const bool debug = true;
APScan apScan;


const String clientList = {
   
};

void ledOFF(){
  digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH  
}


void ledON(){
  digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
}


void setup() {
    pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
    ////EEPROM.begin(4096);
    Serial.begin(115200);

    //WiFi.mode(WIFI_STA);
    //wifi_set_promiscuous_rx_cb(sniffer);
    //WiFi.begin(ssid, password);

//    WiFi.softAP(
//      ssid,     // (const char*)settings.ssid.c_str(),
//      password, // (const char*)settings.password.c_str(),
//      1,        // settings.apChannel,
//      false     // settings.ssidHidden
//    ); //for an open network without a password change to:  WiFi.softAP(ssid);

  delay(1000);
  
  apScan.start(); // Working Already
  digitalWrite(BUILTIN_LED, HIGH);
}
void loop() {

  // Pure Attack Algirithm
}




