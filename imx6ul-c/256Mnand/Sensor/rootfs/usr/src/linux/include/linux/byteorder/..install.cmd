cmd_/diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/byteorder/.install := perl scripts/headers_install.pl /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/rpm/BUILD/linux-3.0.35/include/linux/byteorder /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/byteorder arm big_endian.h little_endian.h; perl scripts/headers_install.pl /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/rpm/BUILD/linux-3.0.35/include/linux/byteorder /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/byteorder arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/byteorder/$$F; done; touch /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/byteorder/.install