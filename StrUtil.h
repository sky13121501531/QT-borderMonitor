#ifndef STRUTIL_H
#define STRUTIL_H

#include <cstring>
#include <time.h>
#include <stdlib.h>
#include "externType.h"
using namespace std;

class StrUtil
{
public:

static string RoundFloat(double fOriginal,int nSaveBits);

static int Str2Int(string Str);
static string Int2Str(int integer);

static long Str2Long(string Str);
static string Long2Str(long value);

static long CiFang(long baseInt,long numCF);

static float Str2Float(string str);
static float Str2FloatForFMFreq(string str);
static string Float2Str(float floater);
static string Float2Str1(float floater);//四舍五入保留一位小数

static int GetStrPixelLength(char* str, int font);

static string GetStrNumID(string strip);
static void GetIPNumID(string strip,string &ChassisID,string &SlotID);
/*
 ********************************
 * 注  | 模拟电视及调频广播板卡流设置指令
 *     |in----MONITERPARAMSET，结构体
 *     |out---流设置指令，格式xml,类型string
 ********************************
*/
static string MonitorCardTs_paramset(moniter_paramset m_paramset);
/*
 ********************************
 * 注  | 模拟电视及调频广播板卡频道扫描指令
 *     |in----moniter_channelscan，结构体
 *     |out---频道扫描指令，格式xml,类型string
 ********************************
*/
static string MonitorCardTs_ChannelScan(moniter_channelscan m_channelscan);
/*
 ********************************
 * 注  | 模拟电视及调频广播板卡校时指令
 *     | 校时时间往后提前2S
 ********************************
*/
static string MonitorCardTs_TimeSet();
};
#endif //STRUTIL_H

