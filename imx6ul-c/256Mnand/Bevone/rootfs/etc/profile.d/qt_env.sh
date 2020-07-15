#!/bin/sh
##tslib
TOUCHSCREEN=/dev/input/ts2
#ts2 is gt9xx
#ts1 is ft5x06
#ts0 is tsc
if [ -e /dev/input/ts2 ]; then
	TOUCHSCREEN=/dev/input/ts2   	
elif [ -e /dev/input/ts1 ]; then
	TOUCHSCREEN=/dev/input/ts1    	
elif [ -e /dev/input/ts0 ]; then
	TOUCHSCREEN=/dev/input/ts0 	
fi

export TSLIB_ROOT=/usr/local/tslib
export TSLIB_TSDEVICE=$TOUCHSCREEN
export TSLIB_TSEVENTTYPE=input
export TSLIB_CONSOLEDEVICE=none
export TSLIB_CALIBFILE=/etc/pointercal
export TSLIB_CONFFILE=$TSLIB_ROOT/etc/ts.conf
export TSLIB_PLUGINDIR=$TSLIB_ROOT/lib/ts
export TSLIB_FBDEVICE=/dev/fb0
export PATH=$TSLIB_ROOT/bin:$PATH
export LD_LIBRARY_PATH=$TSLIB_ROOT/lib:$LD_LIBRARY_PATH
##tslib
if grep -q "calibrate=n" /proc/cmdline
then
echo "Pass Calibrating..."
elif [ -f /etc/pointercal ];then
echo "calibrated"
else
/usr/local/tslib/bin/ts_calibrate
sync
fi
FB_SIZE=$(cat /sys/class/graphics/fb0/virtual_size)
##tslib
##QTE-4.8.6
export QTDIR=/root/QTE-4.8.6
export PATH=$QTDIR/bin:$PATH
export LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH
export QT_PLUGIN_PATH=$QTDIR/plugins
export QT_QWS_FONTDIR=$QTDIR/lib/fonts
                      
export QWS_MOUSE_PROTO="tslib:$TOUCHSCREEN mouseman:/dev/input/mice"
export QWS_DISPLAY="linuxfb:mmWidth50:mmHeight130:0"
export QWS_SIZE=1024x600

