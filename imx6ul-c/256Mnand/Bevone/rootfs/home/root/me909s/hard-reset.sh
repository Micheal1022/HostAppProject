#!/bin/bash
set -e
echo 1 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio1/direction
echo 1 > /sys/class/gpio/gpio1/value      
sleep 60                            
echo 0 > /sys/class/gpio/gpio1/value
sleep 60                            
echo 1 > /sys/class/gpio/unexport

