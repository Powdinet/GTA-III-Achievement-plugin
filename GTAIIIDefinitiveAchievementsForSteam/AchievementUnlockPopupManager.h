#pragma once
#include <plugin.h>
#include "AchievementManager.h"

#define MAX_ACTIVE_POPUPS 3
#define STANDBY_ARRAY_LENGTH NUM_ACHIEVEMENTS
#define MOVE_RATE 3.0f
#define BOX_SIZE_X 300.0f
#define BOX_SIZE_Y 80.0f
#define START_X -BOX_SIZE_X
#define START_Y SCREEN_COORD_MAX_Y / 2 - BOX_SIZE_Y
#define TARGET_X BOX_SIZE_X
#define TIME_TO_WAIT 250 //about 5 seconds (~1.667 timestep at 30fps ==> 1.667*30*5 = 250)


enum PopupState
{
    POPUP_INIT,
    POPUP_GOING_RIGHT,
    POPUP_WAITING,
    POPUP_GOING_LEFT,
    POPUP_FINISHED,
};

class AchievementUnlockPopup
{
    //current ycoordinate
public:
    PopupState state;
    int achievementid;
    float x;
    float time_waited;

    AchievementUnlockPopup(int ID)
    {
        state = POPUP_INIT;
        achievementid = ID;
        x = START_X;
        time_waited = 0.0f;
    }
};

class AchievementUnlockPopupManager
{
public:
    static AchievementUnlockPopup *popups_standby[STANDBY_ARRAY_LENGTH];
    static AchievementUnlockPopup *popups_currently_active[MAX_ACTIVE_POPUPS];
    static int popup_current_search_index;
    static int popup_current_add_index;

    static void Init();
    static void ProcessAchievementUnlockPopups();
    static void NewAchievementUnlock(uint32_t achievementID);
    static void DrawPopups();
};