#include "plugin.h"
#include "AchievementManager.h"

#include "CHud.h" //TODO DELETE
#include "CTimer.h" //TODO DELETE
#include "CWorld.h" //TODO DELETE
#include "CCheat.h" //TODO DELETE

using namespace plugin;

class GTAIIIDefinitiveAchievementsForSteam {
public:
    GTAIIIDefinitiveAchievementsForSteam()
    {
        // plugin start point

        //TODO: fill Achievements data
        AchievementManager::Init();
        //TODO: hack in the menu
        //AchievementMenuManager.Init();
        //TODO: init popup stuff if needed
        //AchievementUnlockPopupManager.Init();

        //TODO: something to detect new game/loaded save and reset/read helper variables
        
        //TODO: any kind of write makes the game crash

        Events::gameProcessEvent += AchievementManager::CheckAchievements;
        //Events::shutdownRwEvent += AchievementManager::Save;//TODO: is this the game close event?
        
    }

    


} gTAIIIDefinitiveAchievementsForSteam;
