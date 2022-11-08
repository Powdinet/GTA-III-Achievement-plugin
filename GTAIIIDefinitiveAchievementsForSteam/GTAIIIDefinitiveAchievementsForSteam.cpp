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
        
        //TODO: Events::gameProcessEvent += AchievementManager::HandleNewGameAndLoads;
        Events::gameProcessEvent += AchievementManager::CheckAchievements;
        Events::gameProcessEvent += []
        {   //TODO: for testing, remove
            static unsigned int lastkeypress = 0;
            static char* testmessage = "The Whoop has been Shooped.";
            static wchar_t* wtestmessage = new wchar_t[strlen(testmessage) + 1];
            if (KeyPressed('R') && CTimer::m_snTimeInMilliseconds - lastkeypress > 500)
            {
                lastkeypress = CTimer::m_snTimeInMilliseconds;
                mbstowcs_s(NULL, wtestmessage, strlen(testmessage) + 1, testmessage, strlen(testmessage));
                CHud::SetHelpMessage(wtestmessage, false);
            }
        };
        //Events::shutdownRwEvent += AchievementManager::Save;//TODO: is this the game close event?
        
    }

    


} gTAIIIDefinitiveAchievementsForSteam;
