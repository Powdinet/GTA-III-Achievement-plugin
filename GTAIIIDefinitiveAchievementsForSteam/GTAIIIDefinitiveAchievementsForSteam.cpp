#include "plugin.h"
#include "PluginBase.h"
#include "AchievementManager.h"
#include "AchievementUnlockPopupManager.h"

#include "CHud.h" //TODO DELETE
#include "CTimer.h" //TODO DELETE
#include "CWorld.h" //TODO DELETE
#include "CCheat.h" //TODO DELETE
#include "CTxdStore.h" //TODO DELETE
#include "CSprite2d.h" //TODO DELETE
#include "debug.h"
#include "common.h"


using namespace plugin;

class GTAIIIDefinitiveAchievementsForSteam {

public:

    GTAIIIDefinitiveAchievementsForSteam()
    {
        static CSprite2d mySprite;
        // plugin start point

        //TODO: fill Achievements data
        AchievementManager::Init();
        AchievementUnlockPopupManager::Init();
        //TODO: hack in the menu
        //AchievementMenuManager.Init();
        //TODO: init popup stuff if needed
        //AchievementUnlockPopupManager.Init();

        //TODO: something to detect new game/loaded save and reset/read helper variables

        //TODO: Events::gameProcessEvent += AchievementManager::HandleNewGameAndLoads;
        Events::initRwEvent += AchievementManager::SetupTXDStore;
        Events::gameProcessEvent += AchievementManager::CheckAchievements;
        Events::gameProcessEvent += AchievementUnlockPopupManager::ProcessAchievementUnlockPopups;
        Events::drawingEvent += AchievementUnlockPopupManager::DrawPopups;
        Events::shutdownRwEvent += AchievementManager::RemoveTXDStore;

        //TODO: remove, just fortesting
        /*Events::initRwEvent += []
        {
            int txd = CTxdStore::AddTxdSlot("achievements");
            CTxdStore::LoadTxd(txd, "Achievement plugin data\\images\\achievements.txd");
            CTxdStore::AddRef(txd);
            CTxdStore::PushCurrentTxd();
            CTxdStore::SetCurrentTxd(txd);
            mySprite.SetTexture("T_GTA3_FirstDay_BC");
            CTxdStore::PopCurrentTxd();
        };

        Events::shutdownRwEvent += []
        {
            mySprite.Delete();
            CTxdStore::RemoveTxdSlot(CTxdStore::FindTxdSlot("achievements"));
        };

        Events::drawingEvent += []
        {

            mySprite.Draw(20.0f, 20.0f, 256.0f, 256.0f, CRGBA(255, 255, 255, 255));
        };

        Events::drawingEvent += []
        {
            if (mySprite.mCurrentSprite)
                plugin::gamefont::Print(
                    "Yes!", 200, 200, FONT_DEFAULT, 0.75f, 0.75f, CRGBA(255, 255, 255),
                    plugin::gamefont::AlignRight, 0, CRGBA(0, 0, 0), true, 400.0f, true, false, plugin::gamefont::RightBottom);
            else
                plugin::gamefont::Print(
                    "No...", 200, 200, FONT_DEFAULT, 0.75f, 0.75f, CRGBA(255, 255, 255),
                    plugin::gamefont::AlignRight, 0, CRGBA(0, 0, 0), true, 400.0f, true, false, plugin::gamefont::RightBottom);
        };*/

    }

} gTAIIIDefinitiveAchievementsForSteam;
