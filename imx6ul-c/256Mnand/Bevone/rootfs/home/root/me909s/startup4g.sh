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
  echo "ATE0" > $devstr
  sleep 1
  echo "AT^LEDCTRL=1"> $devstr
  sleep 1
  echo "AT^NDISDUP=1,1,\"cmnet\"" > $devstr
  sleep 1
  ifconfig eth0 down
  ifconfig eth1 down
  ifconfig usb0 up
  udhcpc -iusb0 -q -n
  ifconfig eth0 up
  ifconfig eth1 up
  echo "4g ttyUSB exist"
else
  echo "4g ttyUSB not exist"
fi
