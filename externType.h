#ifndef EXTERNTYPE_H
#define EXTERNTYPE_H

#include <string>
using namespace std;

/*

// std::string => QByteArray
QByteArray byteArray(stdString.c_str(), stdString.length());

// QByteArray => std::string
std::string stdString(byteArray.constData(), byteArray.length());

*/
#define MONICARDPORT 8080
#define TIMEOUT 10000;

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

/*
 *********************************
 * 注+TCP通信返回结果
 * if---ERROR_NO,is success,or fail
 *********************************
*/
enum ERROR_RECV
{
    ERROR_NO            = 0,                  /*成功*/
    ERROR_CONNECT       = -1,                 /*连接失败*/
    ERROR_SEND          = -2,                 /*发送失败*/
    ERROR_RECV          = -3,                 /*接收失败*/
    ERROR_RECV_TIMEOUT  = -4,                 /*接收超时*/
};
#endif // EXTERNTYPE_H
