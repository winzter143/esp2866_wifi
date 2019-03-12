/*
 * This will deauthenticate some users from the network
 * Pin 13 Port B
 * My modified version of deauthenticate
 */
#include <Arduino.h>

#include <ESP8266WiFi.h>
#include "APScan.h"
#include "ClientScan.h"

//#include <ESP8266WebServer.h>
//ESP8266WebServer server(80);

#define BUILTIN_LED 2
// Scan in 15 sec
#define CLIENT_SCAN_TIME 15

#define ATTACK_TIME 

/**
 * Constant Declaration
 */
 /**
  * List Of client to deauthenticate
  */
const String clientList = {
   
};

/**
 * List of AP to authenticate
 */
const String apList = {
     
};


const bool debug = true;

/**
 * scan time on idel
 */
const int clientScanTime = 15; 
int clientScanCounter = 0; 
bool is_found = false;
/**
 * Attac
 */
const int attackTime = 20; // Attacking time
int attackTimeCounter = 0;
const int attackCount = 3; // after this will go to idle again
int attackCountCounter = 0; // after this will go to idle again
const int attackIdle = 10; // after this will go to idle again
int attackIdleCounter = 0; // after this will go to idle again




 


/**
 * Object Initialization
 */
APScan apScan;
ClientScan clientScan;



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
  digitalWrite(BUILTIN_LED, LOW);

  delay(2000); // Delay 2 secs
  //clientScan.start(clientScanTime);
  digitalWrite(BUILTIN_LED, HIGH);
}


/**
 * The main process from
 */
void loop() {
  // Pure Attack Algirithm
  delay(1000); // delay for 1 sec
  int _time = millis();
  Serial.println("LOOOOOOP:"+ (String)_time);
  
  
  if (is_found == true) {
    
    delay(1000); // delay for 1 sec
    _time = millis();
    //Serial.println("SCAN STARt: "  + (String)_time);
    
  
      
      //const int attackTime = 20; // Attacking time
      //int attackTimeCounter = 0;

    if (attackIdleCounter >= attackIdle){

      // DO the attack here Start attack here
      Serial.println("Attack Idle count: " + (String) attackIdleCounter);

      if (attackTimeCounter >= attackTime){
        Serial.println("Attack count: " + (String) attackTimeCounter);
        
        if (attackCountCounter  >= attackCount){
          Serial.println("RESET attack counter: ");
          attackCountCounter = 0;
          clientScanCounter = 0;
          
          is_found = false; // Back to scan again
          attackTimeCounter = 0;
        }else{
          Serial.println("RESET attack counter: " + (String)attackCountCounter);
        }
        
        attackCountCounter++;
        attackTimeCounter=0;
        attackIdleCounter=0;
       
      }// if (attackTimeCounter >= attackTime){
      
      attackTimeCounter++;
    } // if (attackIdleCounter >= attackIdle){
    else{
       Serial.println("\nIDLE Attack count: " + (String) attackIdleCounter);
    }
    
    attackIdleCounter++;
    
      
    //clientScanTime=0
  }else{
    if (clientScanCounter >= clientScanTime){
      _time = millis();
      //Serial.println("START SCAN Client(%i): %i");//, clientScanCounter, _time);
      
      // Dont Scan APs again since already scan in the boot.
      // START Scan Client in AP
  
      // Do The scan Client here
      is_found=true;
      if (is_found == true){
         //Serial.println("Scan Found  Cleint: %i");//, _time);
      }else{
         //Serial.println("SCAN reset to idlea: %i");//, _time);
        clientScanCounter = 0;
      }
    }
  }
   
  clientScanCounter++;
  Serial.print("-");
   Serial.println(clientScanCounter);
}

void startClientScan() {
  //if (server.hasArg("time") && apScan.getFirstTarget() > -1 && !clientScan.sniffing) {
   // server.send(200, "text/json", "true");
    //clientScan.start(100000);
    //attack.stopAll();
  //} else {
  //  server.send( 200, "text/json", "Error: no selected access point");
  //}
}
