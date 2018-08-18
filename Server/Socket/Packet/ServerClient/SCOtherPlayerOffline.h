﻿#ifndef _SC_OTHER_PLAYER_OFFLINE_H_
#define _SC_OTHER_PLAYER_OFFLINE_H_

#include "Packet.h"

class SCOtherPlayerOffline : public Packet
{
public:
	SCOtherPlayerOffline(PACKET_TYPE type)
		:Packet(type) {}
	virtual void fillParams()
	{
		pushParam(mPlayerID);
	}
	virtual std::string debugInfo()
	{
		PACKET_DEBUG("player id : %d", mPlayerID);
	}
public:
	int mPlayerID;
};

#endif