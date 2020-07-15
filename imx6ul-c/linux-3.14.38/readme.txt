1.emmc 编译方法
make linux_imx6ul_emmc_defconfig
make zImage -j${CPUS}               //arch/arm/boot/zImage
make dtbs -j${CPUS}                 //arch/arm/boot/dts/imx6ul-14x14-evk*.dtb
make modules -j${CPUS}
2.nand 编译方法
make linux_imx6ul_nand_defconfig
make zImage -j${CPUS}               //arch/arm/boot/zImage
make dtbs -j${CPUS}                 //arch/arm/boot/dts/imx6ul-14x14-evk-gpmi*.dtb
make modules -j${CPUS}
3.设备树说明
arch/arm/boot/dts/imx6ul-14x14-evk-gpmi.dts 中#include "imx6ul-14x14-evk.dts"，也是说，是在arch/arm/boot/dts/imx6ul-14x14-evk.dts的基础上修改qspi usdhc2 gpmi的状态得到的。如果想要修改arch/arm/boot/dts/imx6ul-14x14-evk-gpmi.dts，修改arch/arm/boot/dts/imx6ul-14x14-evk.dts文件即可。
-gpmi-			代表nand的设备树
-gpmi-1g-		代表1G nandflash 的设备树
-c2-			代表底板为OKMX6UL-C2的设备树
-iomuxc- -gpio-		代表底板为OKMX6UL-C3的设备树
-8-r			代表8吋电阻屏
-7-800x480		代表7吋800x480分辨率电阻电容屏
-7-1024x600		代表7吋1024x600分辨率电阻电容屏
-5.6-r			代表5.6吋电阻屏
-10.4-r			代表10.4吋电阻屏
-4.3-r			代表4.3吋电阻屏		
可随机组合。

比如：
OKMX6UL-C1 EMMC设备树
imx6ul-14x14-evk.dtb 对应源码arch/arm/boot/dts/imx6ul-14x14-evk.dts，7吋800x480分辨率电阻电容屏
imx6ul-14x14-evk-4.3-r.dtb 对应源码 arch/arm/boot/dts/imx6ul-14x14-evk-4.3-r.dts，4.3吋电阻屏
imx6ul-14x14-evk-7-800x480.dtb 对应源码arch/arm/boot/dts/imx6ul-14x14-evk-7-800x480.dts，7吋800x480分辨率电阻电容屏
imx6ul-14x14-evk-7-1024x600.dtb 对应源码arch/arm/boot/dts/imx6ul-14x14-evk-7-1024x600.dts，7吋1024x600分辨率电阻电容屏
imx6ul-14x14-evk-5.6-r.dtb 对应源码arch/arm/boot/dts/imx6ul-14x14-evk-5.6-r.dts，5.6吋电阻屏
imx6ul-14x14-evk-8-r.dtb 对应 源码arch/arm/boot/dts/imx6ul-14x14-evk-8-r.dts，8吋电阻屏
imx6ul-14x14-evk-10.4-r.dtb 对应源码 arch/arm/boot/dts/imx6ul-14x14-evk-10.4-r.dts，10.4吋电阻屏
imx6ul-14x14-evk-sdio.dtb 对应源码 arch/arm/boot/dts/imx6ul-14x14-evk-sdio.dts，支持sdio wifi或者sd卡非热插拔，7吋800x480电阻电容屏(非出厂标准镜像)
imx6ul-14x14-evk-adc.dtb 对应源码 arch/arm/boot/dts/imx6ul-14x14-evk-adc.dts，GPIO1_IO01-IO04用作ADC（非出厂标准镜像）
imx6ul-14x14-evk-ecspi.dtb 对应源码 arch/arm/boot/dts/imx6ul-14x14-evk-ecspi.dts，2路SPI（非出厂标准镜像）
imx6ul-14x14-evk-vga.dtb 对应源码 arch/arm/boot/dts/imx6ul-14x14-evk-vga.dts，支持800x600 VGA输出（非出厂标准镜像）

当前ov9650.c暂不开源。


&tsc {
	  pinctrl-names = "default";
	  pinctrl-0 = <&pinctrl_tsc>;
	  status = "okay";              //将okay->disabled 不支持电阻触摸
	  xnur-gpio = <&gpio1 3 0>;
	  measure_delay_time = <0xffff>;
	  pre_charge_time = <0xfff>;
};                            //支持电阻触摸功能


edt_ft5x06@38{
          compatible = "edt,edt-ft5x06";
          reg = <0x38>;
          pinctrl-names = "default";
          status = "okay";                 //将okay->disabled
          pinctrl-0 = <&pinctrl_edt_ft5x06>;
          interrupt-parent = <&gpio5>;
          interrupts = <1 2>;
};                            //为电容触摸功能

&lcdif {
	pinctrl-names = "default";
	pinctrl-0 = <&pinctrl_lcdif_dat
		     &pinctrl_lcdif_ctrl>;
	display = <&display0>;
	status = "okay";

	display0: display {
		bits-per-pixel = <24>;
		bus-width = <24>;

		display-timings {
			native-mode = <&timing0>;
/*		timing0: timing0 {
			clock-frequency = <9200000>;
			hactive = <480>;
			vactive = <272>;
			hfront-porch = <8>;
			hback-porch = <4>;
			hsync-len = <41>;
			vback-porch = <2>;
			vfront-porch = <4>;
			vsync-len = <10>;

			hsync-active = <0>;
			vsync-active = <0>;
			de-active = <1>;
			pixelclk-active = <0>;
			};*/                                  /*4.3*/

		timing0: timing0 {
			clock-frequency = <33000000>;
			hactive = <800>;
			vactive = <480>;
			hfront-porch = <121>;
			hback-porch = <88>;
			hsync-len = <48>;
			vback-porch = <39>;
			vfront-porch = <21>;
			vsync-len = <3>;

			hsync-active = <0>;
			vsync-active = <0>;
			de-active = <1>;
			pixelclk-active = <0>;
			};                                   /*7.0-800x480*/
/*		timing0: 7_1024x600 {
                       clock-frequency = <51200000>;
                       hactive = <1024>;
                       vactive = <600>;
                       hfront-porch = <160>;
                       hback-porch = <320>;
                       hsync-len = <1>;
                       vback-porch = <35>;
                       vfront-porch = <12>;
                       vsync-len = <1>;

                       hsync-active = <0>;
                       vsync-active = <0>;
                       de-active = <1>;
                       pixelclk-active = <0>;

                        };   */                                  /*7.0-1024x600*/
/*		timing0: timing0 {
			clock-frequency = <30000000>;
			hactive = <800>;
			vactive = <600>;
			hfront-porch = <112>;
			hback-porch = <88>;
			hsync-len = <48>;
			vback-porch = <39>;
			vfront-porch = <21>;
			vsync-len = <3>;
			hsync-active = <0>;
			vsync-active = <0>;
			de-active = <1>;
			pixelclk-active = <0>;
		}; */                                    /*8.0*/
/*		timing0: timing0 {
			clock-frequency = <40000000>;
			hactive = <800>;
			vactive = <600>;
			hfront-porch = <112>;
			hback-porch = <88>;
			hsync-len = <48>;
			vback-porch = <39>;
			vfront-porch = <21>;
			vsync-len = <3>;
			hsync-active = <0>;
			vsync-active = <0>;
			de-active = <1>;
			pixelclk-active = <0>;
		}; */                                       /*10.4*/
		};
	};
};


&usdhc1 {
	pinctrl-names = "default", "state_100mhz", "state_200mhz";
	pinctrl-0 = <&pinctrl_usdhc1>;
	pinctrl-1 = <&pinctrl_usdhc1_100mhz>;
	pinctrl-2 = <&pinctrl_usdhc1_200mhz>;
/*	cd-gpios = <&gpio1 19 0>;*/                 //sd 卡
	nonremovable;                    //sdio      注意：sd卡与sdio不能同时用。
	keep-power-in-suspend;
	enable-sdio-wakeup;
	vmmc-supply = <&reg_sd1_vmmc>;
	status = "okay";
};


/* ov9650 需要将csi 设置为okay,ov9650 为okay, sim2为disabled */ 
&csi {
	status = "okay";
};

&ov9650 {
	status = "okay";
};

&sim2 {
	status = "disabled";
};

/* 将esam功能打开需要将csi 设置为disabled,ov9650 为disabled, sim2为okay */ 
&csi {
	status = "disabled";
};

&ov9650 {
	status = "diasbled";
};
&sim2 {
      //pinctrl-assert-gpios = <&gpio4 23 GPIO_ACTIVE_LOW>; //注掉该配置
	status = "okay";

};
pinctrl_sim2_1: sim2grp-1 {
	fsl,pins = <
		//MX6UL_PAD_CSI_DATA03__SIM2_PORT1_PD		0xb808//注掉该配置
				
		//MX6UL_PAD_CSI_DATA06__SIM2_PORT1_SVEN		0xb808//注掉该配置
				
		/*	MX6UL_PAD_CSI_DATA02__GPIO4_IO23        0x3008  */
		>;
		};




/*nand的需要将qspi 设置为disabled,usdhc2设置为disabled,gpmi 设置为okay*/
&qspi{
	status = "disabled";
};

&usdhc2 {
	status = "disabled";
};

&gpmi {
	status = "okay";
};

