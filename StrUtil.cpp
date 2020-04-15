#pragma warning(disable:4996)
#include <math.h>
#include "StrUtil.h"

static unsigned char ascii_hei_40_width_data[128] = 
{	
	30,30,30,30,30,30,30,30,30,30,30,30,30,
	30,30,30,30,30,30,30,30,30,30,30,30,30,
	30,30,30,30,30,30,30,12,16,26,25,38,31,
	10,16,16,18,26,11,16,12,15,25,19,25,25,
	25,25,25,25,25,25,11,11,26,26,26,25,45,
	31,29,32,32,29,27,34,30,11,21,31,25,35,
	30,34,30,35,33,29,28,30,31,43,31,31,28,
	14,15,12,22,27,13,25,25,24,24,25,17,24,
	24,10,10,24,10,36,24,25,25,24,18,23,15,
	24,24,33,24,24,24,17,11,16,26,30
}; 

static unsigned char ascii_hei_20_width_data[128] = 
{
	0, 16, 16, 16, 16, 10,  0, 24,  10,  0, 11,  0,  0,  6,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	6,  5,  7, 12, 11, 15, 15,  5,  8,  7, 12, 10,  5, 11,  5,  6,
	10, 10, 10, 10, 10, 10, 10, 10, 10, 10,  8,  7, 11, 10, 11, 10,
	18, 14, 14, 14, 14, 13, 12, 14, 14,  5, 10, 15, 11, 16, 14, 15,
	13, 15, 14, 13, 12, 14, 14, 17, 13, 14, 12,  7,  6,  6, 11, 11,
	5, 12, 12, 11, 12, 11,  8, 12, 11,  5,  5, 11,  5, 17, 11, 12,
	12, 12,  8, 11,  7, 11, 10, 16, 11, 11, 10,  9,  6,  8, 11, 16
};

string StrUtil::RoundFloat(double fOriginal,int nSaveBits)
{
    static const int DECIMAL_BASE = 10;    
    unsigned int n,scale;
    double fEnd;
    char sEnd[100] = {0};
    string retValue;

    n = 0;
    scale = 1;
    double fOriginal_f = fabs(fOriginal);
    for (int i=0;i<nSaveBits;i++)  
        scale *= DECIMAL_BASE;
    scale *= 2;
    n = (int)(fOriginal_f * scale); 

    n += (n % 2);
    fEnd = ((double)n /scale);
    if(fOriginal < 0)
        sprintf(sEnd,"-%0.2f",fEnd);
    else
        sprintf(sEnd,"%0.2f",fEnd);
    retValue = string(sEnd);
    return retValue;
}

int StrUtil::Str2Int(string Str)
{
    if (!Str.empty())
        return atoi(Str.c_str());
    else return 0;
}

string StrUtil::Int2Str(int integer)
{
    char ret[64] = {0};
    ::sprintf(ret,"%d",integer);
    return ret;
}

long StrUtil::Str2Long(string Str)
{
    if (!Str.empty())
        return atol(Str.c_str());
    else return 0;
}

string StrUtil::Long2Str(long value)
{
    char ret[64] = {0};
    	::sprintf(ret,"%d",value);
    return ret;
}

long StrUtil::CiFang(long baseInt,long numCF)
{  
    if (0 ==numCF) return 1;
    long result = baseInt;
    for ( int i = 2 ; i <= numCF; i ++)
        result = result * baseInt;
    return result;
}

float StrUtil::Str2Float(string str)
{
    if (str.empty() || str.size() == 0) 
		str="0";
    return (float)atof(str.c_str());
}
float StrUtil::Str2FloatForFMFreq(string str)
{
	if (str.empty() || str.size() == 0) 
		str="0";
	return (float)atof(str.c_str()) + 0.0001F;
}

string StrUtil::Float2Str(float floater)
{
    string ret = RoundFloat((double)floater,2);

    return ret;
}
std::string StrUtil::Float2Str1( float floater )
{
	char result[100];
	double dOrginaData=(double)floater*10;
	int iOrginalData=(int)dOrginaData;
	double subRes=dOrginaData-(double)iOrginalData;
	int iLeft=(int)(subRes*2.0);

	int iEnd=dOrginaData;
	iEnd+=iLeft;
	double dResult=(double)iEnd/10;

	sprintf(result,"%0.1f",dResult);

	string strResult=string(result);
	return strResult;
}

int StrUtil::Str2IntForQam(string str)
{
	if(!strcmp(str.c_str(),"QAM16"))
	{
		return 0;
	}
	else if(!strcmp(str.c_str(),"QAM32"))
	{
		return 1;
	}
	else if(!strcmp(str.c_str(),"QAM64"))
	{
		return 2;
	}
	else if(!strcmp(str.c_str(),"QAM128"))
	{
		return 3;
	}
	else if(!strcmp(str.c_str(),"QAM256"))
	{
		return 4;
	}
	else if(!strcmp(str.c_str(),"QAM4"))
	{
		return 5;
	}
	else
	{
		return Str2Int(str);
	}
}
int StrUtil::GetStrPixelLength(char* hz, int font)
{
	int i = 0;
	int iDistance = 0;
	char ascBuf[3] = {0, 0, 0};
	int Width = 0;
	unsigned const char* pixelArr;
	unsigned char AscOdd, AscEven;

	char tmpStrArr[128] = {0};
	memcpy(tmpStrArr, hz, strlen(hz));


	if(font == 40)
		pixelArr = ascii_hei_40_width_data;
	else
		pixelArr = ascii_hei_20_width_data;
	for (i = 0; (i < 128) && ('\0' != hz[i]); i++)
	{
		//printf("a       hz[i] =%x\n",hz[i] );
		if(hz[i] & 0x80)
		{
			//	printf("hz[i] =%x\n",hz[i] );
			memcpy(ascBuf, &(hz[i]), 2);
			i++;
		}
		else
		{
			ascBuf[0] = hz[i];
			ascBuf[1] = '\0';
		}
		Width=0;
		{
			/*以下代码取字模*/
			AscOdd = *ascBuf;
			if(AscOdd & 0x80)
			{

				AscEven = *(ascBuf + 1);
				if(AscEven & 0x80)
				{

					//   asc = (unsigned char*)(pFontAttr->gFonthzData) + rec;
					//	printf("asc=%d\n",asc);
					Width = font;
				}
				else
				{
					//AscEven = 0xa0;
					//asc = NULL;
					if (AscEven == /*中文空格*/0xa0)
					{
						Width = font;
					}
				}
			}
			else
			{

				if(AscOdd > 0x20)/*可见字符 0X20 asc空格*/
				{
					//asc = (unsigned char *)(pFontAttr->gAsciiData + rec);
					Width =  (int)pixelArr[AscOdd];
				}
				else if(0X9 == AscOdd)/*tab键处理*/
				{
					//asc = NULL;
					Width = (int)pixelArr[AscOdd];
				}
				else if(0X6 == AscOdd)/*for jinshi*/
				{
					//asc = NULL;
					Width = (int)pixelArr[AscOdd];
				}
				else
				{
					AscOdd = ' ';
					//asc = NULL;

					if (AscOdd == /*asc空格*/0x20)
					{
						Width = (int)pixelArr[AscOdd];
					}
				}
			}
			iDistance +=  Width;
		}

	}

	memset(hz, 0, 128);
	int addNum = 16 - iDistance%16;
	
	if(addNum > 2)
	{
		addNum -= 2;
	}

	for(int i = 0; i < addNum; i++)
		hz[i] = 0x6;

	memcpy(hz+addNum, tmpStrArr, strlen(tmpStrArr));

	return iDistance + 16 - iDistance%16;
}

std::string StrUtil::GetStrNumID(string strip)
{
    string tmpNumID;
    if(strip!="")
    {
        int ipos = 0;
        while(ipos<3)
        {
            int npos = strip.find(".");
            tmpNumID = strip.substr(0,npos);
            strip = strip.substr(++npos,strip.length());
            ipos++;
        }
    }
    return tmpNumID;
}
void StrUtil::GetIPNumID(string strip,string &ChassisID,string &SlotID)
{
    string tmpNumID;
    if(strip!="")
    {
        int ipos = 0;
        while(ipos<3)
        {
            int npos = strip.find(".");
            tmpNumID = strip.substr(0,npos);
            strip = strip.substr(++npos,strip.length());
            if(ipos==1)
            {
                ChassisID = tmpNumID;
            }
            if(ipos==2)
            {
                SlotID = tmpNumID;
            }
            ipos++;
        }
    }
}
string StrUtil::MonitorCardTs_paramset(moniter_paramset m_paramset)
{
    string strDeviceSrcXml ="<?xml version=\"1.0\" encoding=\"GB2312\" standalone=\"yes\"?>\
            <Msg Version=\"1.0\" MsgID=\"";
    strDeviceSrcXml += StrUtil::Long2Str(time(0));
    strDeviceSrcXml += "\"><Type>ChangeProgramInfo</Type>\
            <Data>\
            <Channel>";
    strDeviceSrcXml += m_paramset.Channel;
    strDeviceSrcXml += "</Channel>\
            <Tuner>\
            <TunerType>";
    strDeviceSrcXml += m_paramset.Type;
    strDeviceSrcXml += "</TunerType>\
            <Frequency>";
    strDeviceSrcXml += m_paramset.Frequency;
    strDeviceSrcXml += "</Frequency>\
            <ModulationType>";
    strDeviceSrcXml += m_paramset.Frequency;
    strDeviceSrcXml += "</ModulationType>\
            </Tuner>\
            <Encoder>\
            <VideoBitrate>";
    strDeviceSrcXml += m_paramset.VideoBitrate;
    strDeviceSrcXml +="</VideoBitrate>\
            <TsIP>";
    strDeviceSrcXml += m_paramset.TsIP;
    strDeviceSrcXml +="</TsIP>\
            <TsPort>";
    strDeviceSrcXml += m_paramset.TsPort;
    strDeviceSrcXml += "</TsPort>\
            <Stop>1</Stop>\
            </Encoder>\
            <OSD>\
            <Text>";
    strDeviceSrcXml += m_paramset.text;
    strDeviceSrcXml +=  "</Text>\
            <PositionX>100</PositionX>\
            <PositionY>1</PositionY>\
            <Align>RIGHT</Align>\
            </OSD>\
            <TimeStamp>\
            <Enable>1</Enable>\
            <PositionX>464</PositionX>\
            <PositionY>40</PositionY>\
            <Align>RIGHT</Align>\
            </TimeStamp>\
            <Volume>\
            <Enable>1</Enable>\
            </Volume>\
            </Data>\
            </Msg>";
            return strDeviceSrcXml;
}

string StrUtil::MonitorCardTs_ChannelScan(moniter_channelscan m_channelscan)
{
    string strDeviceSrcXml;
    if(m_channelscan.Type == "TV")
    {
        strDeviceSrcXml ="<?xml version=\"1.0\" encoding=\"GB2312\" standalone=\"yes\"?>\
                <Msg Version=\"1.0\" MsgID=\"10000\" SrcUrl=\"http://172.16.10.250:11111\">\
                <Type>ATVChannelScanQuery</Type>\
                <Data>\
                <Channel>";
        strDeviceSrcXml += m_channelscan.Channel;
        strDeviceSrcXml += "</Channel>\
                <ScanParam>\
                <ScanType>STANDARD</ScanType>\
                </ScanParam>\
                </Data>\
                </Msg>";
    }
    else if(m_channelscan.Type == "RADIO")
    {
        strDeviceSrcXml ="<?xml version=\"1.0\" encoding=\"GB2312\" standalone=\"yes\"?>\
                <Msg Version=\"1.0\" MsgID=\"10000\" SrcUrl=\"http://172.16.10.250:11111\">\
                <Type>RadioChannelScanQuery</Type>\
                <Data>\
                <Channel>";
        strDeviceSrcXml += m_channelscan.Channel;
        strDeviceSrcXml +="</Channel>\
                <ScanParam>\
                <ScanType>BAND</ScanType>\
                <StartFrequency>87600</StartFrequency>\
                <EndFrequency>108000</EndFrequency>\
                <StepSize>100</StepSize>\
                </ScanParam>\
                </Data>\
                </Msg>";
    }
    return strDeviceSrcXml;
}
string StrUtil::MonitorCardTs_TimeSet()
{
    string strSrcXml;
    strSrcXml = "<?xml version=\"1.0\" encoding=\"GB2312\"?>\
            <Msg Version=\"1.0\" MsgID=\"10000\" SrcUrl=\"http://172.17.6.5:1000\">\
            <Type>SetSystemTimeInfo</Type>\
            <Data>\
            <Time>";
    strSrcXml +=  StrUtil::Long2Str(time(0) + 2);
    strSrcXml += "</Time>\
            </Data>\
            </Msg>";
    return strSrcXml;
}
