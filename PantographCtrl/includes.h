#ifndef INCLUDES
#define INCLUDES
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include "UserLogin/userlogin.h"
#include "SystemConf/systemconf.h"

#define TIMEOUT     1000


#define GETDATA     0X01
#define SETCONF     0X02
#define GETCONF     0X03
#define REPLAY      0X04

#define DATA_AA     0X00
#define DATA_00     0X01
#define DATA_CMD    0X02
#define DATA_LEN    0X03
#define DATA_MODE   0X04
#define DATA_P1_H   0X05
#define DATA_P1_l   0X06
#define DATA_P2_H   0X07
#define DATA_P2_L   0X08
#define DATA_T_1    0X09
#define DATA_T_2    0X0A
#define DATA_T_3    0X0B
#define DATA_T_4    0X0C
#define DATA_T_5    0X0D
#define DATA_T_6    0X0E
#define DATA_V_CP   0X0F
#define DATA_STATE  0X10
#define DATA_ERROR  0X11
#define DATA_CRC_L  0X12
#define DATA_CRC_H  0X13




#define AUTOMODE    0x00
#define MANUALMODE  0x01
#define REPAIRMODE  0x02

#define P_1         0x01
#define P_2         0x02
#define CP1         0x03
#define T_1         0x04
#define T_2         0x05
#define T_3         0x06
#define T_4         0x07
#define T_5         0x08
#define T_6         0x09

#define STATE       0x00
#define INIT        0x00
#define DROPPING    0x01
#define DROPPED     0x02
#define RISING      0x03
#define RISED       0x04

#define ERROR               0x00
#define UPPERLIMITERROR     0x00
#define LOWERLIMITERROR     0x01
#define SERVOERROR          0x02
#define SUDDENSTOPERROR     0x03
#define TIMEOUTERROR        0x04
#define POWERLOSERROR       0x05
#define PRESSOURERROR_1     0x06
#define PRESSOURERROR_2     0x07
#define TEMPERROR_1         0x08
#define TEMPERROR_2         0x09
#define TEMPERROR_3         0x0A
#define TEMPERROR_4         0x0B
#define TEMPERROR_5         0x0C
#define TEMPERROR_6         0x0D

#endif // INCLUDES

