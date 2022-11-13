#include "CTimer.h"
#include "common.h"
#include "CFont.h"
#include "extensions/FontPrint.h"
#include "AchievementUnlockPopupManager.h"
#include "CHud.h"
#include "CCamera.h"
#include "AchievementManager.h"
#include "CTxdStore.h"
#include "debug.h"

AchievementUnlockPopup *AchievementUnlockPopupManager::popups_standby[STANDBY_ARRAY_LENGTH];
AchievementUnlockPopup *AchievementUnlockPopupManager::popups_currently_active[MAX_ACTIVE_POPUPS];
int AchievementUnlockPopupManager::popup_current_search_index = 0;
int AchievementUnlockPopupManager::popup_current_add_index = 0;

void AchievementUnlockPopupManager::Init()
{
    popup_current_search_index = 0;
    popup_current_add_index = 0;
}

void AchievementUnlockPopupManager::ProcessAchievementUnlockPopups()
{
    if (!TheCamera.GetScreenFadeStatus())
    {
        for (int i = 0; i < MAX_ACTIVE_POPUPS; i++)
        {
            if (popups_currently_active[i])
            {
                switch (popups_currently_active[i]->state)
                {
                    //going up, still, going down
                    //when fully down, terminate this thing's existence
                    //TODO: change so it comes from the left instead
                case POPUP_INIT:
                    popups_currently_active[i]->state = POPUP_GOING_RIGHT;
                    break;
                case POPUP_GOING_RIGHT:
                    popups_currently_active[i]->x += CTimer::ms_fTimeStep * MOVE_RATE;
                    if (popups_currently_active[i]->x >= TARGET_X)
                    {
                        popups_currently_active[i]->x = TARGET_X;
                        popups_currently_active[i]->state = POPUP_WAITING;
                    }
                    //TODO
                    break;
                case POPUP_WAITING:
                    popups_currently_active[i]->time_waited += CTimer::ms_fTimeStep;
                    if (popups_currently_active[i]->time_waited >= TIME_TO_WAIT)
                    {
                        popups_currently_active[i]->state = POPUP_GOING_LEFT;
                    }
                    break;
                case POPUP_GOING_LEFT:
                    popups_currently_active[i]->x -= CTimer::ms_fTimeStep * MOVE_RATE;
                    if (popups_currently_active[i]->x <= START_X)
                    {
                        popups_currently_active[i]->state = POPUP_FINISHED;
                    }
                    //TODO
                    break;
                case POPUP_FINISHED:
                    //look for a new achievement to put in this slot
                    if (popups_standby[popup_current_search_index])
                    {
                        delete popups_currently_active[i];
                        popups_currently_active[i] = popups_standby[popup_current_search_index];
                        popup_current_search_index++;
                    }
                    break;
                }
            }
            else
            {
                //look for the first achievement to put in this slot
                if (popups_standby[popup_current_search_index])
                {
                    popups_currently_active[i] = popups_standby[popup_current_search_index];
                    popup_current_search_index++;
                }
            }
        }
    }
}

void AchievementUnlockPopupManager::NewAchievementUnlock(uint32_t achievementID)
{
    popups_standby[popup_current_add_index] = new AchievementUnlockPopup(achievementID);
    popup_current_add_index = (popup_current_add_index + 1) % STANDBY_ARRAY_LENGTH;
}

void AchievementUnlockPopupManager::DrawPopups()
{
    if (AchievementManager::achievementList[FIRST_DAY_ON_THE_JOB].spriteData)
    {
        AchievementManager::achievementList[FIRST_DAY_ON_THE_JOB].spriteData->Draw(20.0f, 20.0f, 256.0f, 256.0f, CRGBA(255, 255, 255, 255));
        plugin::gamefont::Print(
            "Yes!", 200, 200, FONT_DEFAULT, 0.75f, 0.75f, CRGBA(255, 255, 255),
            plugin::gamefont::AlignRight, 0, CRGBA(0, 0, 0), true, 400.0f, true, false, plugin::gamefont::RightBottom);
    }
    else
        plugin::gamefont::Print(
            "No...", 200, 200, FONT_DEFAULT, 0.75f, 0.75f, CRGBA(255, 255, 255),
            plugin::gamefont::AlignRight, 0, CRGBA(0, 0, 0), true, 400.0f, true, false, plugin::gamefont::RightBottom);
    //AchievementManager::achievementList[popups_currently_active[1]->achievementid].spriteData->Draw(20.0f, 20.0f, 256.0f, 256.0f, CRGBA(255, 255, 255, 255));
    //AchievementManager::achievementList[popups_currently_active[2]->achievementid].spriteData->Draw(20.0f, 20.0f, 256.0f, 256.0f, CRGBA(255, 255, 255, 255));
    if (!TheCamera.GetScreenFadeStatus())
    {
        for (int i = 0; i < MAX_ACTIVE_POPUPS; i++)
        {
            if (popups_currently_active[i])
            {
                if (popups_currently_active[i]->state > POPUP_INIT &&
                    popups_currently_active[i]->state < POPUP_FINISHED)
                {
                    if (AchievementManager::achievementList[popups_currently_active[i]->achievementid].spriteData)
                    {
                        //TODO: coordinates
                        AchievementManager::achievementList[popups_currently_active[i]->achievementid].spriteData->Draw(20.0f, 20.0f, 256.0f, 256.0f, CRGBA(255, 255, 255, 255));
                    }
                    plugin::gamefont::Print(
                        AchievementManager::achievementList[popups_currently_active[i]->achievementid].name,
                        popups_currently_active[i]->x, START_Y + (BOX_SIZE_Y*i), FONT_DEFAULT, 0.75f, 0.75f, CRGBA(255, 255, 255),
                        plugin::gamefont::AlignLeft, 0, CRGBA(0, 0, 0), true, 400.0f, true, false, plugin::gamefont::LeftTop);
                }
            }
        }
    }  
}