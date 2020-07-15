#!/bin/bash
export CPUS=`grep -c processor /proc/cpuinfo`
export ARCH=arm
export CROSS_COMPILE=/usr/local/ForlinxSDK/fsl-linaro-toolchain/bin/arm-none-linux-gnueabi-
export PATH=/usr/local/ForlinxSDK/fsl-linaro-toolchain/bin:$PATH
export OBJ=imx6ul-14x14-evk-gpmi-c-256m-7-1024x600.dtb
export burnFile=256Mnand
#make distclean
make linux_imx6ul_nand_defconfig
make zImage -j${CPUS}
make dtbs -j${CPUS}
make modules -j${CPUS}

if [ -d ../$burnFile/$@ ]
then
   cp ./arch/arm/boot/zImage ../$burnFile/$@/update/target
   cp ./arch/arm/boot/dts/$OBJ ../$burnFile/$@/update/target
else
   mkdir ../$burnFile/$@
   cp ./arch/arm/boot/zImage ../$burnFile/$@/update/target
   cp ./arch/arm/boot/dts/$OBJ ../$burnFile/$@/update/target
fi
