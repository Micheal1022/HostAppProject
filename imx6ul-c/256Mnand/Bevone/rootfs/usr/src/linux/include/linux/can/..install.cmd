cmd_/diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/can/.install := perl scripts/headers_install.pl /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/rpm/BUILD/linux-3.0.35/include/linux/can /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/can arm bcm.h error.h netlink.h raw.h; perl scripts/headers_install.pl /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/rpm/BUILD/linux-3.0.35/include/linux/can /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/can arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/can/$$F; done; touch /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/linux/can/.install