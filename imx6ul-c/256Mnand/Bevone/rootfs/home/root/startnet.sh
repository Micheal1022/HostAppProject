#!/bin/bash
set -e
#me909s
#/home/root/me909s/setup_model2g.sh
#/home/root/me909s/setup_model3g.sh
/home/root/me909s/setup_model4g.sh
#/home/root/me909s/setup_modelauto.sh
#dc and ac use the one script to get ttyUSBX
#find ttyusbx
boardname=`cat /proc/boardname | awk '{print $2}'`
echo $boardname
boardc3="OKMX6UL-C3"

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
	if [ "$boardname" = "$boardc3" ]
	then
		/home/root/me909s/rild-c3 -d $devstr -t 0 &
	else
		/home/root/me909s/rild-c1 -d $devstr -t 0 &
	fi
fi
#eth
#/home/root/eth/startupeth0.sh
#/home/root/eth/startupeth1.sh
#sim900a-800a
#/home/root/sim900a/startup_sim900a.sh 
