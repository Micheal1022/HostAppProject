#!/bin/sh

cd rootfs
tar cjf rootfs.tar.bz2 ./*
mv rootfs.tar.bz2 ../update/target
cd ../update
tar cjf update.tar.bz2 ./*
mv update.tar.bz2 ../createSdcard-qt4
cd ../createSdcard-qt4
./createSdcard.sh
rm update.tar.bz2
echo "!!!!finished!!!!"

