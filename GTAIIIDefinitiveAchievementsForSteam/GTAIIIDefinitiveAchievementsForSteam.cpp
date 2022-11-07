#include "plugin.h"
#include "AchievementManager.h"

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

        Events::gameProcessEvent.Add(AchievementManager::CheckStatBasedAchievements);
        Events::gameProcessEvent.Add(AchievementManager::CheckMissionCompleteAchievements);
        Events::gameProcessEvent.Add(AchievementManager::CheckSpecialMissionAchievements);
        Events::gameProcessEvent.Add(AchievementManager::CheckBribeAchievement);
        Events::gameProcessEvent.Add(AchievementManager::CheckMoneyAchievements);
        Events::gameProcessEvent.Add(AchievementManager::CheckAllAchievementsComplete);

        Events::shutdownRwEvent.Add(AchievementManager::Save);//TODO: is this the game close event?
        
    }

    


} gTAIIIDefinitiveAchievementsForSteam;
