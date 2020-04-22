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
static string Float2Str1(float floater);//�������뱣��һλС��

static int GetStrPixelLength(char* str, int font);

static string GetStrNumID(string strip);
static void GetIPNumID(string strip,string &ChassisID,string &SlotID);
/*
 ********************************
 * ע  | ģ����Ӽ���Ƶ�㲥�忨������ָ��
 *     |in----MONITERPARAMSET���ṹ��
 *     |out---������ָ���ʽxml,����string
 ********************************
*/
static string MonitorCardTs_paramset(moniter_paramset m_paramset);
/*
 ********************************
 * ע  | ģ����Ӽ���Ƶ�㲥�忨Ƶ��ɨ��ָ��
 *     |in----moniter_channelscan���ṹ��
 *     |out---Ƶ��ɨ��ָ���ʽxml,����string
 ********************************
*/
static string MonitorCardTs_ChannelScan(moniter_channelscan m_channelscan);
/*
 ********************************
 * ע  | ģ����Ӽ���Ƶ�㲥�忨Уʱָ��
 *     | Уʱʱ��������ǰ2S
 ********************************
*/
static string MonitorCardTs_TimeSet();
};
#endif //STRUTIL_H

