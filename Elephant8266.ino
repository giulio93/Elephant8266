// by Ray Burnette 20161013 compiled on Linux 16.3 using Arduino 1.6.12

#include <ESP8266WiFi.h>
#include "./functions.h"

#define disable 0
#define enable  1
// uint8_t channel = 1;
unsigned int channel = 1;

//BLUETOOTH

#include <SoftwareSerial.h>     //IDE >= 1.0
//#include <NewSoftSerial.h>    //IDE <= 0023
const int rxPin = 14;
const int txPin = 12;
const int atPin = 13;
SoftwareSerial bluetooth(rxPin, txPin, false, 256);
unsigned long previousMillis = 0; 
const long interval = 5000;
int a = 1;
//SoftwareSerial bluetooth(rxPin, txPin);  //IDE >= 1.0
//NewSoftSerial bluetooth(rxPin, txPin);   //IDE <= 0023

//BLUETOOTH

void setup() {
 
  //BLUETOOTH
  Serial.begin(115200);
  bluetooth.begin(115200);
  pinMode(atPin, OUTPUT);
  Serial.println("Seriali attive...");
  digitalWrite(atPin, HIGH);
  //BLUETOOTH
   //Serial.begin(57600);
  Serial.printf("\n\nSDK version:%s\n\r", system_get_sdk_version());
  Serial.println(F("ESP8266 mini-sniff by Ray Burnette http://www.hackster.io/rayburne/projects"));
  Serial.println(F("Type:   /-------MAC------/-----WiFi Access Point SSID-----/  /----MAC---/  Chnl  RSSI"));

  wifi_set_opmode(STATION_MODE);            // Promiscuous works only with station mode
  wifi_set_channel(channel);
  wifi_promiscuous_enable(disable);
  wifi_set_promiscuous_rx_cb(promisc_cb);   // Set up promiscuous callback
  wifi_promiscuous_enable(enable);
}

void loop() {
  channel = 1;
  wifi_set_channel(channel);
  while (true) {
    nothing_new++;                          // Array is not finite, check bounds and adjust if required
    if (nothing_new > 200) {
      nothing_new = 0;
      channel++;
      if (channel == 15) break;             // Only scan channels 1 to 14
      wifi_set_channel(channel);
    }
    delay(1);  // critical processing timeslice for NONOS SDK! No delay(0) yield()
    // Press keyboard ENTER in console with NL active to repaint the screen
    if ((Serial.available() > 0) && (Serial.read() == '\n')) {
      Serial.println("\n-------------------------------------------------------------------------------------\n");
      for (int u = 0; u < clients_known_count; u++) print_client(clients_known[u]);
      for (int u = 0; u < aps_known_count; u++) print_beacon(aps_known[u]);
      Serial.println("\n-------------------------------------------------------------------------------------\n");
    }

    unsigned long currentMillis = millis();
  if (bluetooth.available()) {  
    Serial.write(bluetooth.read());
  }
 
  if (Serial.available()) {
    bluetooth.write(Serial.read());
  }
   
   if (currentMillis - previousMillis >= interval) {
    // Serial.write("Bluetooth Scan Restart..");
    // save the last time you blinked the LED
    previousMillis = currentMillis;
      if(a == 0)
      {
      a=1;
      digitalWrite(atPin, LOW);
      }
      else if (a==1)
      {
        a=0;
        digitalWrite(atPin, HIGH);
      }
        
    }
    
  }
}

