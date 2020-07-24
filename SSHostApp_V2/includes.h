#ifndef INCLUDES_H
#define INCLUDES_H


#define CANFRAMESIZE 16//数据包大小
#define PF_CAN 29   //设备编号
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

#define SYSTIME     500    //系统时间
#define HEARTTIME   2000//心跳时间
#define MAXNUM      100000   //数据库最大记录

/*设备类型*/
#define DEV_EFMQ      0//电气火灾
#define DEV_PMFE      1//电源监控
#define CANDINUM      255//最大ID地址255


#define N_LOOP        0//节点回路地址
#define N_NODEID      1//节点ID地址
#define N_AREA        3//节点安装区域
/*上传数据链表位置类型*/
#define LOOP          0
#define CMD           1
#define TYPE          2
#define STATE         3
#define CANID         4
#define VALUE_1       5
#define VALUE_2       6
#define VALUE_3       7
#define PASS          8
#define PSTATE        9
#define PTYPE         10
#define L_STATE       2//报警/故障链表状态
#define L_CANID       3//报警/故障链表ID

/*用户级别*/
#define USERS   0
#define ADMIN   1
#define SUPER   2
/*历史记录*/
#define R_LOOP    0//回路
#define R_CANID   1//地址
#define R_PASS    2//通道
#define R_TYPE    3//通道的类型
#define R_STATE   4//状态
#define R_VALUE   5//报警值
#define R_TIME    6//报警时间
#define R_AREA    7//安装位置

#define ROWMUN    10//每页记录的数目

/*通道数据位*/
#define N_PASS        0x00//通道编号
#define N_TYPE        0x01//通道类型
#define N_STATE       0x02//通道状态
#define N_VALUE_1     0x03//通道数值1
#define N_VALUE_2     0x04//通道数值2
#define N_VALUE_3     0x05//通道数值3

/*通道型号*/
#define N_LEAK  0x01
#define N_TEMP  0x02
#define N_ACV3  0x05
#define N_ACV   0x06
#define N_ACI3  0x07
#define N_ACI   0x08
#define N_THER  0x09
#define N_DCV   0x15
#define N_DCI   0x16
#define N_HOST  0x1A//主机
#define N_EXTE  0x1B//分机

#define COLUMNSIZE      8  //每列节点数目
#define PAGESTEP        490//每页步长
#define NODECOUNT       56 //每页节点总数
#define LOOPERROR       10 //回路心跳丢失次数

/*探测器型号*/
#define MOD_UREG        0x00
#define MOD_L1T4        0x01//组合式
#define MOD_L12T4       0x02//一体式
#define MOD_EARC        0x03//电弧
#define MOD_PYRO        0x04//热解
#define MOD_THER        0x09//热成像
#define MOD_2VA         0x11//三相-两路电压一路电流
#define MOD_VA          0x12//三相-一路电压一路电流
#define MOD_A           0x13//三相-一路电流
#define MOD_3V          0x14//三相-三路电压
#define MOD_2V          0x15//三相-两路电压
#define MOD_V           0x16//三相-一路电压
#define MOD_6V3A        0x17//单相-六路电压三路电流
#define MOD_6V          0x18//单相-六路电压三路电流
#define MOD_3A          0x19//单相-六路电压三路电流

/*探测器状态*/
#define N_NOMAL         0x01//通讯正常
#define N_LOSTPOWER     0x02//电源中断
#define N_OVERVOL       0x03//过压故障
#define N_OVERCUR       0x04//过流故障
#define N_UNDERVOL      0x05//欠压故障
#define N_LOSTPHASE     0x06//错相故障
#define N_ERRORPHASE    0x07//缺相故障
#define N_ERROR         0x08//传感器故障
#define N_ALARM         0x09//通道报警
#define N_OFFLINE       0x0A//通讯故障
#define N_COVER         0x0B//遮挡
#define N_DISCON        0x0C//断网
#define N_COVDIS        0x0D//遮挡+断网

/*探测器状态*/
#define N_NORMAL        0x01//节点正常
#define N_POWERLOST     0x02//电源中断
#define N_OVERVOL       0x03//节点过压
#define N_OVERCUR       0x04//节点过流
#define N_LACKVOL       0x05//节点欠压
#define N_LACKPHA       0x06//节点缺相
#define N_ERRORPHA      0x07//节点错相
#define N_ERROR         0x08//节点故障
#define N_ALARM         0x09//节点报警
#define N_OFFLINE       0x0A//节点掉线
#define N_LOOPERR       0x0B//回路板故障

#define TIMER           500//系统时间

/*移动位置坐标*/
#define X_POS   210
#define Y_POS   190
/*故障记录列表*/
#define INFO_LOOP    0
#define INFO_TYPE    1
#define INFO_STATE   2
#define INFO_ID      3
#define INFO_VALUE   4
#define INFO_TIME    5
#define INFO_AREA    6

/*主备电故障检测，声音，指示灯*/
#define TESTTIMES   30
#define N_HOST      0x1A//主机
#define N_EXTE      0x1B//分机
#define N_MAINPOW   0xAA//主电故障
#define N_BACKPOW   0xBB//备电故障
#define N_RESET     0xCC//复位操作
#define N_MUTE      0xDD//静音操作

#define MPOWERSTATE     1
#define BPOWERSTATE     2
#define RESETBTNSTATE   3

#define S_NORAML  1
#define S_ERROR   2
#define S_ALARM   3
#define MPOWERNORMAL    1 //主电正常
#define MPOWERERROR     2 //主电故障
#define BPOWERNORMAL    3 //备电正常
#define BPOWERERROR     4 //备电故障
#define CANBUS_ON       5 //通讯灯-开
#define CANBUS_OFF      6 //通讯灯-关
#define BUZZ_ON         7 //蜂鸣器-开
#define BUZZ_OFF        8 //蜂鸣器-关
#define ERRORLED_ON     9 //故障声音-开
#define ERRORLED_OFF    10//故障声音-关
#define ALARMLED_ON     11//报警声音-开
#define ALARMLED_OFF    12//报警声音-关
#define ERRORBUZZ       13//故障声音
#define ALARMBUZZ       14//报警声音
#define RELAY_1_ON      15//继电器1-开
#define RELAY_1_OFF     16//继电器1-关
#define RELAY_2_ON      17//继电器2-开
#define RELAY_2_OFF     18//继电器2-关
#define SYSTEM_ON       19//系统故障灯-亮
#define SYSTEM_OFF      20//系统故障灯-灭

/*探测器状态信息记录*/
#define N_NORMAL      0x01//节点正常
#define N_LOSTPOW     0x02//电源中断
#define N_OVERVOL     0x03//节点过压
#define N_OVERCUR     0x04//节点过流
#define N_LACKVOL     0x05//节点欠压
#define N_LACKPHA     0x06//节点缺相
#define N_ERRORPHA    0x07//节点错相
#define N_ERROR       0x08//节点故障
#define N_ALARM       0x09//节点报警
#define N_OFFLINE     0x0A//节点掉线
#define N_MAINPOW     0xAA//主电故障
#define N_BACKPOW     0xBB//备电故障
#define N_RESET       0xCC//复位操作
#define N_MUTE        0xDD//静音操作
#define N_EXTEERROR   0xEE//分机故障

#endif // INCLUDES_H
