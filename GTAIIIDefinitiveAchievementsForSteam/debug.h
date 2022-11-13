#pragma once
#include "CHud.h"
#include "CTimer.h"
#include "AchievementManager.h"

static int debugNextPrintTime;

//TODO: could add more useful printing methods but at this point I've dealt with using these
static void DebugHelpPrint(int achievementID)
{
    if (DEBUG)
    {
        const char* unlockmessage = AchievementManager::achievementList[achievementID].name.c_str();
        wchar_t* wtestmessage = new wchar_t[strlen(unlockmessage) + 1];
        mbstowcs_s(NULL, wtestmessage, strlen(unlockmessage) + 1, unlockmessage, strlen(unlockmessage));
        CHud::SetHelpMessage(wtestmessage, false);
    }
}

static void DebugHelpPrint(char* message)
{
    if (DEBUG && CTimer::m_snTimeInMilliseconds >= debugNextPrintTime) //TODO: this doesn't reset on new/load game, so it breaks 
    {
        wchar_t* wtestmessage = new wchar_t[strlen(message) + 1];
        mbstowcs_s(NULL, wtestmessage, strlen(message) + 1, message, strlen(message));
        CHud::SetHelpMessage(wtestmessage, false);
        debugNextPrintTime = CTimer::m_snTimeInMilliseconds + 1000;
    }
}