#ifndef EXTERNTYPE_H
#define EXTERNTYPE_H

#include <string>
using namespace std;

#define CHANNELSCAN 7
#define ATVMOREPORT 10000
#define ATVAUTOPORT 10500
#define FMMOREPORT 11000
#define FMAUTOPORT 11500
#define AMMOREPORT 12000
#define AMAUTOPORT 12500
/*
 *********************************
 * 注+模拟电视及调频广播板卡流主要参数
 *********************************
*/
typedef struct MONITERPARAMSET
{
    string Type;
    string Frequency;
    string Channel;
    string ModulationType;
    string VideoBitrate;
    string TsIP;
    string TsPort;
    string text;
    string UDPAddr;
}moniter_paramset,*p_moniter_paramset;

/*
 *********************************
 * 注+模拟电视及调频广播板卡频道扫描
 *********************************
*/
typedef struct MONITERCHANNELSCAN
{
    string Type;
    string Channel;
}moniter_channelscan,*p_moniter_channelscan;

#endif // EXTERNTYPE_H
