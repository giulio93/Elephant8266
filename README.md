# Elephant8266
Elephant8266 devices/beacon scanner + HC05 Bluetooth devices inquiry

This project is based on : based on mini-sniff by Ray Burnette http://www.hackster.io/rayburne/projects.

The poject exploit a software serial in order to use HC05 in AT programming mode and do the inquiry procedure.
In this way we are allow to read MAC bluetooth adress , RSSI and class device type.

It use an NODE-MCU ESP-12 and a bluetooth HC05 connected to the software serial.

This project is based on Arduino core for ESP8266 WiFi chip : https://github.com/esp8266/Arduino
