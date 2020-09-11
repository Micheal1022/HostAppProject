#ifndef INCLUDES
#define INCLUDES
#include <QTimer>
#include <QDebug>
#include <QLabel>
#include <time.h>
#include <QProcess>
#include <QDateTime>
#include <QSerialPort>
#include <QButtonGroup>
#include <QGraphicsDropShadowEffect>
#include "SQLite/mysqlite.h"
#include "MsgBox/msgbox.h"

#define TIMEOUT     1000


#define GETDATA     0X01
#define SETDATA     0X02
#define GETCONF     0X03
#define REPLAY      0X04

#define DATA_AA     0
#define DATA_00     1
#define DATA_CMD    2
#define DATA_LEN    3
#define DATA_MODE   4
#define DATA_P1_H   5
#define DATA_P1_L   6
#define DATA_P2_H   7
#define DATA_P2_L   8
#define DATA_T_1    9
#define DATA_T_2    10
#define DATA_T_3    11
#define DATA_T_4    12
#define DATA_T_5    13
#define DATA_T_6    14
#define DATA_V_CP   15
#define DATA_STATE  16
#define DATA_ERROR  17
#define DATA_CRC_L  18
#define DATA_CRC_H  19

#define MANUALMODE  0x01
#define AUTOMODE    0x02
#define REPAIRMODE  0x03

#define MODE        0x00
#define P_1         0x01
#define P_2         0x02
#define T_1         0x03
#define T_2         0x04
#define T_3         0x05
#define T_4         0x06
#define T_5         0x07
#define T_6         0x08
#define CPV         0x09

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


#define DATA_PH    5
#define DATA_PL    6
#define DATA_LS    7
#define DATA_MS    8
#define DATA_HS    9
#define DATA_MT    10
#define DATA_ST    11
#define DATA_RT    12

#define CONF_MODE  0
#define CONF_PH    1
#define CONF_PL    2
#define CONF_LS    3
#define CONF_MS    4
#define CONF_HS    5
#define CONF_MT    6
#define CONF_ST    7
#define CONF_RT    8



#endif // INCLUDES

