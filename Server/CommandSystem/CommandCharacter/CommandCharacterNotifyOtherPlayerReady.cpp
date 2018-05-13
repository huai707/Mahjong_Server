﻿#include "CommandHeader.h"
#include "CharacterPlayer.h"
#include "NetServer.h"
#include "PacketHeader.h"

void CommandCharacterNotifyOtherPlayerReady::execute()
{
	CharacterPlayer* player = static_cast<CharacterPlayer*>(mReceiver);
	// 鍙戦€佹湁鐜╁鍑嗗鐨勬秷鎭?
	SCOtherPlayerReady* playerReady = static_cast<SCOtherPlayerReady*>(mNetServer->createPacket(PT_SC_OTHER_PLAYER_READY));
	playerReady->mPlayerGUID = mPlayerGUID;
	playerReady->mReady = mReady;
	mNetServer->sendMessage(playerReady, player->getClientGUID());
}

std::string CommandCharacterNotifyOtherPlayerReady::showDebugInfo()
{
	COMMAND_DEBUG("ready : %s, player id : %d", mReady ? "true" : "false", (int)mPlayerGUID);
}
