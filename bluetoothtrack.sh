#!/bin/bash


hciconfig

hciconfig hci0 up
 

hcitool spinq

hcidump | grep -e bdaddr  -e name

