#ifndef INCLUDES_H
#define INCLUDES_H

#define CANFRAMESIZE 1

#define PF_CAN 29
#define LEAKTYPE 1
#define TEMPTYPE 2
//主机下发命令
#define SCMD_UPDATE 0x02    //实施更新数值
#define SCMD_RESET  0x03    //探测器复位
#define SCMD_CHECK  0x04    //探测器自检
#define SCMD_WORK   0x05    //回路板开始工作
#define SCMD_SALARM 0x08    //设置报警值
#define SCMD_SHAVE  0x09    //设置固有值
#define SCMD_SRATIO 0x0A    //设置变比值
#define SCMD_SCALIB 0x0E    //设置校准
#define SCMD_QALARM 0x0B    //查询／上传报警值
#define SCMD_QHAVE  0x0C    //查询／上传固有值
#define SCMD_QRATIO 0x0D    //查询／上传变比值

//回路板上发命令
#define DEV_STATE   0x01    //节点状态信息
#define DEV_UPDATE  0x02    //实施更新数值
#define DEV_HEART   0x06    //心跳命令
#define DEV_REPLY   0x07    //主机回复



#define DEV_EFMQ  0
#define DEV_PMFE  1

#define MOD_COMB    0x01//组合式
#define MOD_UNIT    0x02//一体式
#define MOD_EARC    0x03//电弧
#define MOD_PYRO    0x04//热解
#define MOD_THER    0x09//热成像
#define MOD_2VA     0x11//三相-两路电压一路电流
#define MOD_VA      0x12//三相-一路电压一路电流
#define MOD_3V      0x13//三相-三路电压
#define MOD_2V      0x14//三相-两路电压
#define MOD_V       0x15//三相-一路电压
#define MOD_6V3A    0x16//单相-六路电压三路电流

/*通道型号*/
#define N_UREG  0x00
#define N_LEAK  0x01
#define N_TEMP  0x02
#define N_ACV3  0x05
#define N_ACV   0x06
#define N_ACI3  0x07
#define N_ACI   0x08
#define N_DCV   0x15
#define N_DCI   0x16
/*探测器状态*/
#define N_NORMAL      0x01//节点正常
#define N_POWERLOST   0x02//电源中断
#define N_OVERVOL     0x03//节点过压
#define N_OVERCUR     0x04//节点过流
#define N_LACKVOL     0x05//节点欠压
#define N_LACKPHA     0x06//节点缺相
#define N_ERRORPHA    0x07//节点错相
#define N_ERROR       0x08//节点故障
#define N_ALARM       0x09//节点报警
#define N_OFFLINE     0x0A//节点掉线
#define N_LOOPERR     0x0B//回路板故障
#define TIMENUM       0x05


/*电流功能*/
#define P_START       0x01
#define P_STOP        0x02
#define P_SET         0x03


/*电压功能*/
#define _DATA   0x00


#define LOOP    0
#define CMD     1
#define TYPE    2
#define STATE   3
#define CANID   4
#define VALUE_1 5
#define VALUE_2 6
#define VALUE_3 7
#define PASS    8
#define PSTATE  9
#define PTYPE   10

#define D_000   0x00
#define D_100   0x01
#define D_150   0x02
#define D_200   0x03
#define D_300   0x04
#define D_500   0x05
#define D_800   0x06













#endif // INCLUDES_H
