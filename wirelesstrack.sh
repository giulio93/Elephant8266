#!/bin/bash

iwconfig

airmon-ng start wlan0  1

airodump-ng mon0 -w registrazione-$1
