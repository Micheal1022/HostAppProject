#!/bin/sh
set -e
#dc and ac use the one script to get ttyUSBX
#find ttyusbx
count=0
devstr="/dev/ttyUSB6"
cur=`pwd`
stroption1=/sys/bus/usb-serial/drivers/option1
echo $cur
#find ttyusbX
cd $stroption1
list=`ls -d ttyUSB*`
exist=$?
echo $exist
cd $cur
for dev_str in $list
do
   echo "the value is : $dev_str"
   if [ $count = 2 ]; then
      devstr=$dev_str
      break
   fi
   count=$(($count+1))
done
echo "$devstr"
devstr="/dev/"$devstr
#find ttyusbx
#devstr="/dev/ttyUSB6"
if [ $exist = 0 ]; then
  echo "AT^RESET" > $devstr
  echo "4g module hot reset"
fi
