cmd_/diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/mtd/.install := perl scripts/headers_install.pl /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/rpm/BUILD/linux-3.0.35/include/mtd /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/mtd arm inftl-user.h mtd-abi.h mtd-user.h nftl-user.h ubi-user.h; perl scripts/headers_install.pl /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/rpm/BUILD/linux-3.0.35/include/mtd /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/mtd arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/mtd/$$F; done; touch /diske1/dongyulong/source/freescale/Linux/L3.0.35_4.1.0_130816_source/source/ltib/tmp/kernel//opt/freescale/rootfs/arm/usr/src/linux/include/mtd/.install
