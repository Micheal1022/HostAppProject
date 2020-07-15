#!/bin/sh
while true
do
  sleep 5
  ps -fe | grep ssApp | grep -v grep
  #如果不存在进程运行,则需要点亮系统故障灯
  if [ $? -ne 0 ]
  then
  echo  1 > /sys/class/gpio/gpio119/value
  else
  echo  0 > /sys/class/gpio/gpio119/value
  fi 
done
