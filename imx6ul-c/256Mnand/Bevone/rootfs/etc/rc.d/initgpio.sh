#!/bin/bash
# gpio list gpio (bank-1)*32 + nr 
for gpio_out in 117 118 119 120 121 122 123
do
echo $gpio_out> /sys/class/gpio/export
echo out > /sys/class/gpio/gpio$gpio_out/direction
done

for out in 251 252 253 254
do
echo $out> /sys/class/gpio/export
done

for gpio_in in 5 9 18 124
do
echo $gpio_in> /sys/class/gpio/export
echo in > /sys/class/gpio/gpio$gpio_in/direction
done

echo complete 
