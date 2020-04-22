/************************************************************************
    This file is part of VLCWrapper.
    
    File:    VLCWrapper.cpp
    Desc.:   VLCWrapper Implementation.

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
#pragma execution_character_set("utf-8")
#include "VLCWrapper.h"
#include "VLCWrapperImpl.h"

VLCWrapper::VLCWrapper()
{
	pImpl_ = new VLCWrapperImpl;
}
VLCWrapper::~VLCWrapper()
{
	if(pImpl_!=NULL)
	{
		delete pImpl_;
	}
}
void VLCWrapper::SetOutputWindow(void* pHwnd)
{
    pImpl_->SetOutputWindow(pHwnd);
}
void VLCWrapper::SetEventHandler(VLCEventHandler event, void* pUserData)
{
    pImpl_->SetEventHandler(event,pUserData);
}
void VLCWrapper::Play()
{
    pImpl_->Play();
}

void VLCWrapper::Pause()
{
    pImpl_->Pause();
}

void VLCWrapper::Stop()
{
    pImpl_->Stop();
}

bool VLCWrapper::IsPlaying()
{
    return pImpl_->IsPlaying();
}

void VLCWrapper::FastForward()
{
    pImpl_->FastForward();
}

void VLCWrapper::FastBackward()
{
    pImpl_->FastBackward();
}

int64_t VLCWrapper::GetLength()
{
    return pImpl_->GetLength();
}

int64_t VLCWrapper::GetTime()
{
    return pImpl_->GetTime();
}

void VLCWrapper::SetTime(int64_t newTime)
{
    pImpl_->SetTime(newTime);
}

void VLCWrapper::Mute(bool mute)
{
    pImpl_->Mute(mute);
}
bool VLCWrapper::GetMute()
{
    return pImpl_->GetMute();
}
int  VLCWrapper::GetVolume()
{
    return pImpl_->GetVolume();
}
void VLCWrapper::SetVolume(int volume)
{
    pImpl_->SetVolume(volume);
}
void VLCWrapper::OpenMedia(const char* pMediaPathName)
{
    pImpl_->OpenMedia(pMediaPathName);
}
void VLCWrapper::SetFullScreen(bool isfull)
{
    pImpl_->SetFullScreen(isfull);
}
void VLCWrapper::SetWHScreen( const char *pWH )
{
    pImpl_->SetWHScreen(pWH);
}
float VLCWrapper::Getbit( void )
{
    return pImpl_->Getbit();
}
