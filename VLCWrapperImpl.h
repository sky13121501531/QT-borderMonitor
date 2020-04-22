/************************************************************************
    This file is part of VLCWrapper.
    
    File:   VLCWrapperImpl.h
    Desc.:  Private Implementation of VLCWrapper.

	Author:  Alex Skoruppa
	Date:    08/10/2009
	Updated: 03/12/2012
	eM@il:   alex.skoruppa@googlemail.com

	Updated by luxiaoxun
	Date: 2013.11.29
	email: luxiaoxun001@qq.com

	VLCWrapper is distributed under the Code Project Open License (CPOL).

	You should have received a copy of the Code Project Open License
	along with VLCWrapper.  If not, see <http://www.codeproject.com/info/cpol10.aspx>.
************************************************************************/
#ifndef VLCWRAPPERIMPL_H
#define VLCWRAPPERIMPL_H

#include "VLCWrapper.h"
#include <QObject>
#include <string>
using namespace std;
struct libvlc_instance_t;
struct libvlc_media_player_t;
struct libvlc_media_t;
struct libvlc_event_manager_t;
struct libvlc_exception_t;
class VLCWrapperImpl : public QObject
{
    libvlc_exception_t*      m_libvlc_ex; 
    libvlc_instance_t*       pVLCInstance_;        ///< The VLC instance.
	libvlc_media_player_t*   pMediaPlayer_;        ///< The VLC media player object.
	libvlc_media_t*          pMedia_;              ///< The media played by the media player.
    libvlc_event_manager_t*  pEventManager_;       ///< The event manger for the loaded media file.    
    VLCEventHandler          eventHandler;         ///< An event handler for the media player.   
	void *                   pHwnd_;

public:
	VLCWrapperImpl(void);
	~VLCWrapperImpl(void);
    void SetOutputWindow(void* pHwnd);    
	void SetEventHandler(VLCEventHandler event, void* pUserData); 
    void Play();
    void Pause();
    void Stop();
	bool IsPlaying();
	void FastForward();
	void FastBackward();
    int64_t GetLength();
    int64_t GetTime();
	void SetTime(int64_t newTime);
	void Mute(bool mute = true);
    bool GetMute();
    int  GetVolume();
	void SetVolume(int volume);
    void OpenMedia(const char* pMediaPathName);	
	void SetFullScreen(bool isfull);
    void SetWHScreen(const char *pWH);
    float Getbit(void);
};

#endif // VLCWRAPPERIMPL_H