#include <plugin.h>
#include "CWorld.h"
#include "CPickups.h"
#include "CStats.h"
#include "eWeaponType.h"
#include "AchievementManager.h"

//achievement list
AchievementDefinition AchievementManager::achievementList[NUM_ACHIEVEMENTS];

//helper variables
uint8_t AchievementManager::bribes_pickedup;
uint8_t AchievementManager::portland_criminals;
uint8_t AchievementManager::staunton_criminals;
uint8_t AchievementManager::firefighter_criminals;
uint8_t AchievementManager::portland_fires;
uint8_t AchievementManager::staunton_fires;
uint8_t AchievementManager::firefighter_fires;

void AchievementManager::Init()
{
    //TODO: add images, have to look how to do that
    //TODO: could probably read this information from a file and just load it in with a loop
    achievementList[FIRST_DAY_ON_THE_JOB].name = "First Day on the Job";
    achievementList[FIRST_DAY_ON_THE_JOB].description = "Complete \"Luigi's Girls\"";

    achievementList[WITHOUT_A_SCRATCH].name = "Without a Scratch";
    achievementList[WITHOUT_A_SCRATCH].description = "Deliver Mike Lips' car without a scratch on the first attempt";

    achievementList[ESCAPE_ARTIST].name = "Escape Artist";
    achievementList[ESCAPE_ARTIST].description = "Use 20 police bribes";

    achievementList[DISPOSTING_OF_THE_EVIDENCE].name = "Disposing of the Evidence";
    achievementList[DISPOSTING_OF_THE_EVIDENCE].description = "Crush a car at the junkyard";

    achievementList[MOB_BOSS].name = "Mob Boss";
    achievementList[MOB_BOSS].description = "Keep the two mafia members alive during \"Triads and Tribulations\"";

    achievementList[STREET_SWEEPER].name = "Street Sweeper";
    achievementList[STREET_SWEEPER].description = "Waste 100 gang members";

    achievementList[PLANNED_AHEAD].name = "Planned Ahead";
    achievementList[PLANNED_AHEAD].description = "Take out Chunky Lee Chong with a car rigged with a bomb";

    achievementList[GOT_THIS_FIGURED_OUT].name = "Got This Figured Out";
    achievementList[GOT_THIS_FIGURED_OUT].description = "Use a coach to pick up all 8 prostitutes in the mission \"The Fuzz Ball\"";

    achievementList[BY_A_MILE].name = "By a Mile";
    achievementList[BY_A_MILE].description = "Complete the \"Turismo\" race in under 180 seconds";

    achievementList[WRECKLESS_DRIVING].name = "Wreckless Driving";
    achievementList[WRECKLESS_DRIVING].description = "Perform a perfect insane stunt";

    achievementList[WHEELS_UP].name = "Wheels Up";
    achievementList[WHEELS_UP].description = "Complete 20 unique jumps";

    achievementList[COME_OUT_TO_PLAY].name = "Come Out to Play - y - y - y";
    achievementList[COME_OUT_TO_PLAY].description = "Kill 25 gang members with melee weapons / fists";

    achievementList[WHERE_TO].name = "Where To?";
    achievementList[WHERE_TO].description = "Complete 100 taxi fares";

    achievementList[LIBERTY_CITY_MINUTE].name = "Liberty City Minute";
    achievementList[LIBERTY_CITY_MINUTE].description = "Survive with less than 10 hp for 1 minute";

    achievementList[FULL_ARTILLERY].name = "Full Artillery";
    achievementList[FULL_ARTILLERY].description = "Use every weapon in the game at least once";

    achievementList[A_MARKED_MAN].name = "A Marked Man";
    achievementList[A_MARKED_MAN].description = "Complete \"Last Requests\"";

    achievementList[OFFSHORE_DELIVERY].name = "Offshore Delivery";
    achievementList[OFFSHORE_DELIVERY].description = "Complete \"A Drop in the Ocean\"";

    achievementList[NOT_SO_FAST].name = "Not So Fast";
    achievementList[NOT_SO_FAST].description = "Complete \"The Exchange\"";

    achievementList[A_GIFT_FROM_THE_KING].name = "A Gift from the King";
    achievementList[A_GIFT_FROM_THE_KING].description = "Complete the \"Kingdom Come\" mission";

    achievementList[MAN_TOYZ].name = "Man Toyz";
    achievementList[MAN_TOYZ].description = "Complete every RC Toyz mission";

    achievementList[SPLISH_SPLASH].name = "Splish Splash";
    achievementList[SPLISH_SPLASH].description = "Extinguish 15 fires during a single Fire Truck mission";

    achievementList[PLAYING_DOCTOR].name = "Playing Doctor";
    achievementList[PLAYING_DOCTOR].description = "Complete Paramedic level 12";

    achievementList[GOING_ROGUE].name = "Going Rogue";
    achievementList[GOING_ROGUE].description = "Kill 15 criminals during one Vigilante mission";

    achievementList[DIRTY_MONEY].name = "Dirty Money";
    achievementList[DIRTY_MONEY].description = "Amass a fortune of $1,000,000";

    achievementList[RIGHT_HAND_MAN].name = "Right-hand Man";
    achievementList[RIGHT_HAND_MAN].description = "Earn a criminal rating of 2,500";

    achievementList[FURIOUS_FIRST_RESPONDER].name = "Furious First Responder";
    achievementList[FURIOUS_FIRST_RESPONDER].description = "Complete Paramedic, Firefighter, Vigilante";

    achievementList[LIBERTY_CITY_SECRETS].name = "Liberty City Secrets";
    achievementList[LIBERTY_CITY_SECRETS].description = "Collect 100 hidden packages";

    achievementList[IS_THAT_ALL_YOUVE_GOT].name = "Is That All You've Got?";
    achievementList[IS_THAT_ALL_YOUVE_GOT].description = "Achieve 100% completion";

    achievementList[KING_OF_LIBERTY_CITY].name = "King of Liberty City";
    achievementList[KING_OF_LIBERTY_CITY].description = "Unlock all achievements";

    achievementList[GOT_ANY_STORIES_OLD_MAN].name = "Got Any Stories, Old Man?";
    achievementList[GOT_ANY_STORIES_OLD_MAN].description = "Complete \"Cipriani's Chauffeur\"";

    achievementList[TALKS_A_LOT].name = "Talks a Lot";
    achievementList[TALKS_A_LOT].description = "Complete all phone missions";

    achievementList[BLOOD_IN_THE_STREETS].name = "Blood in the Streets";
    achievementList[BLOOD_IN_THE_STREETS].description = "Pass all 20 Rampages";

    achievementList[INSTIGATOR].name = "Instigator";
    achievementList[INSTIGATOR].description = "Complete 10 Rampages";

    achievementList[CHASING_PAPER].name = "Chasing Paper";
    achievementList[CHASING_PAPER].description = "Amass a fortune of $500, 000";

    achievementList[AM_WALKIN_HERE].name = "Am Walkin' Here";
    achievementList[AM_WALKIN_HERE].description = "Die from being run over";

    achievementList[HUNTING_SEASON].name = "Hunting Season";
    achievementList[HUNTING_SEASON].description = "Destroy five helicopters";

    achievementList[REPEAT_OFFENDER].name = "Repeat Offender";
    achievementList[REPEAT_OFFENDER].description = "Get busted 20 times";

    achievementList[CHEATERS_DO_PROSPER].name = "Cheaters Do Prosper!";
    achievementList[CHEATERS_DO_PROSPER].description = "Blow up 2, 000 cars";

    achievementList[PLAY_FETCH].name = "Play Fetch";
    achievementList[PLAY_FETCH].description = "Complete the Portland Docks and Shoreside Vale import/export car lists";

    achievementList[PEST_CONTROL].name = "Pest Control";
    achievementList[PEST_CONTROL].description = "Deliver all emergency vehicles to the crane at the Portland Docks";

    achievementList[RELIEF_PITCHER].name = "Relief Pitcher";
    achievementList[RELIEF_PITCHER].description = "Extinguish 20 fires during a single Fire Truck mission";

    achievementList[LIKE_A_BOSS].name = "Like a Boss";
    achievementList[LIKE_A_BOSS].description = "Earn a criminal rating of 5,000 or higher";

    achievementList[FARE_GAME].name = "Fare Game";
    achievementList[FARE_GAME].description = "Pick up Curly Bob in a Taxi during \"Cutting the Grass\"";

    achievementList[RECYCLER].name = "Recycler";
    achievementList[RECYCLER].description = "Crush 25 cars";

    for (int i = 0; i < NUM_ACHIEVEMENTS; i++)
    {
        //TODO: read from some saved file if they are unlocked. If file doesn't exist, create it in save game folder
        achievementList[i].unlocked = false;
    }
    //TODO: load in any extra data
    //TODO: could save extra data in unused global variables so they would be attached to the save files.
    //Just need to detect new games / save loads properly and save into those areas whenever the variables are updated
}

void AchievementManager::Save()
{
    //TODO: Saves achievements and helper data (any extra variables needed that aren't in the stats/saved in the savefile
}

/*
    Checks achievements based on game stats (15)
*/
void AchievementManager::CheckStatBasedAchievements()
{
    if (!achievementList[DISPOSTING_OF_THE_EVIDENCE].unlocked &&
        CStats::CarsCrushed >= 1)
    {
        achievementList[DISPOSTING_OF_THE_EVIDENCE].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[BY_A_MILE].unlocked &&
        CStats::ElBurroTime < 180)
    {
        achievementList[BY_A_MILE].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[WRECKLESS_DRIVING].unlocked &&
        CStats::BestStuntJump > 0 && CStats::BestStuntJump % 2 == 0) //Perfect Stunts all have even values
    {
        achievementList[WRECKLESS_DRIVING].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[WHEELS_UP].unlocked &&
        CStats::NumberOfUniqueJumpsFound >= 20) //For some reason the variable is called "found", but it's completion
    {
        achievementList[WHEELS_UP].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[WHERE_TO].unlocked &&
        CStats::PassengersDroppedOffWithTaxi >= 100) //For some reason the variable is called "found", but it's completion
    {
        achievementList[WHERE_TO].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[MAN_TOYZ].unlocked &&
        CStats::HighestScores[1] >= 1 && //Diablo Destruction
        CStats::HighestScores[2] >= 1 && //Mafia Massacre
        CStats::HighestScores[3] >= 1 && //Rumpo Rampage
        CStats::HighestScores[4] >= 1) //Casino Calamity
    {
        achievementList[MAN_TOYZ].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }
    
    if (!achievementList[PLAYING_DOCTOR].unlocked &&
        CStats::HighestLevelAmbulanceMission >= 12)
    {
        achievementList[PLAYING_DOCTOR].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    int rating = CStats::FindCriminalRatingNumber();
    if (!achievementList[RIGHT_HAND_MAN].unlocked &&
        rating >= 2500)
    {
        achievementList[RIGHT_HAND_MAN].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }
    
    if (!achievementList[IS_THAT_ALL_YOUVE_GOT].unlocked)
    {
        CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
        if (player->m_nCollectablesCollected >= 100)
        {
            achievementList[IS_THAT_ALL_YOUVE_GOT].unlocked = true;
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }

    if (!achievementList[IS_THAT_ALL_YOUVE_GOT].unlocked &&
        CStats::ProgressMade >= CStats::TotalProgressInGame)
    {
        achievementList[IS_THAT_ALL_YOUVE_GOT].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }
    
    if (!achievementList[HUNTING_SEASON].unlocked &&
        CStats::HelisDestroyed >= 5)
    {
        achievementList[HUNTING_SEASON].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[REPEAT_OFFENDER].unlocked &&
        CStats::TimesArrested >= 20)
    {
        achievementList[REPEAT_OFFENDER].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[CHEATERS_DO_PROSPER].unlocked &&
        CStats::CarsExploded >= 2000)
    {
        achievementList[CHEATERS_DO_PROSPER].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[LIKE_A_BOSS].unlocked &&
        rating >= 5000)
    {
        achievementList[LIKE_A_BOSS].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[RECYCLER].unlocked &&
        CStats::CarsCrushed >= 25)
    {
        achievementList[RECYCLER].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

}

/*
    Checks achievements that unlock on mission complete (6)
*/
void AchievementManager::CheckMissionCompleteAchievements()
{
    //Different check from Definitive, based on REGISTER_MISSION_PASSED strings
    //TODO: First Day on the Job (Luigi's Girls)
    //TODO: A Marked Man (Last Requests)
    //TODO: Offshore Delivery (A Drop in the Ocean)
    //TODO: Not So Fast (The Exchange)
    //TODO: A Gift From the King (Kingdom Come)
    //TODO: Got Any Stories, Old Man? (Cipriani's Chaffeur)

}

/*
    Checks achievements that unlock when certain conditions are met during missions (4)
*/
void AchievementManager::CheckSpecialMissionAchievements()
{
    //TODO: Without a Scratch (Mike Lips)
    //TODO: Mob Boss (Triads and Tribulations)
    //TODO: Planned Ahead (Farewell Chunky Lee Chong)
    //TODO: Got This Figured Out (Fuzz Ball)
}

/*
    Counts bribes and checks for the bribe achievement (1)
*/
void AchievementManager::CheckBribeAchievement()
{
    if (!achievementList[ESCAPE_ARTIST].unlocked)
    {
        //this is ugly
        for (int i = 0; i < 336; i++)
        {
            if (CPickups::aPickUps[i].m_nModelIndex == BRIBE_MODEL_ID)
            {
                //this next function is only supposed to be used via script
                //but I'm a bad boy so I'm going to use it here
                //hopefully it works
                if (CPickups::IsPickUpPickedUp(CPickups::GetActualPickupIndex(CPickups::aPickUps[i].m_nReferenceIndex)))//TODO test this abomination
                {
                    bribes_pickedup++;

                    if (bribes_pickedup >= 20)
                    {
                        achievementList[ESCAPE_ARTIST].unlocked = true;
                        //TODO add to list of achievements to pop up somehow (events?)
                    }
                }
            }
        }
    }
}

/*
    Checks for the money achievements (2)
*/
void AchievementManager::CheckMoneyAchievements()
{
    CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
    if (!achievementList[CHASING_PAPER].unlocked &&
        player->m_nMoney >= 500000)
    {
        achievementList[CHASING_PAPER].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[DIRTY_MONEY].unlocked &&
        player->m_nMoney >= 1000000)
    {
        achievementList[DIRTY_MONEY].unlocked = true;
        //TODO add to list of achievements to pop up somehow (events?)
    }
}

/*
    Checks for the phone missions achievement (1)
*/
void AchievementManager::CheckPhoneAchievement()
{
    //TODO Check completion flags in the script, as intended 
}

/*
    Checks the rampage completion achievements (2)
*/
void AchievementManager::CheckRampageAchievements()
{
    //TODO Check counter in the script
}

/*
    Checks the fires extinguished in a single session achievements (2)
*/
void AchievementManager::CheckFiresInARow()
{
    //TODO Check counter in the script
}

/*
    Checks the criminals killed in a single session achievements (2)
*/
void AchievementManager::CheckCriminalsInARow()
{
    //TODO Check counter in the script
}

/*
    Checks for Furious First Responder (1)
*/
void AchievementManager::CheckFuriousFirstResponder()
{
    //TODO count and check levels
}

/*
    Checks for the export garages and emergency crane achievements (2)
*/
void AchievementManager::CheckExportAchievements()
{
    //TODO:
}

/*
    Counts gang members kills and checks for the achievements (2)
*/
void AchievementManager::CheckGangsKillsAchievements()
{
    //TODO: count them somehow
    //Bat and Street Sweeper
}

/*
    Checks time player has been under 10HP and unlocks that achievement (1)
*/
void AchievementManager::CheckLibertyCityMinute()
{
    //TODO: check player health and just count the time. Note: when player is dead the timer doesn't continue. Obviously, timer resets when health is above 10
}

/*
    Checks run over achievement (1)
*/
void AchievementManager::CheckRoadkillAchievement()
{
    if (!achievementList[AM_WALKIN_HERE].unlocked)
    {
        CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
        if (player->m_nPlayerState == PLAYERSTATE_HASDIED)
        {
            if (player->m_pPed->m_nLastWepDam == WEAPONTYPE_RUNOVERBYCAR ||
                player->m_pPed->m_nLastWepDam == WEAPONTYPE_RAMMEDBYCAR)
            {
                achievementList[AM_WALKIN_HERE].unlocked = true;
                //TODO add to list of achievements to pop up somehow (events?)
            }
        }
    }
}

/*
    Checks every weapon used achievement (1)
*/
void AchievementManager::CheckFullArtilleryAchievement()
{
    if (!achievementList[FULL_ARTILLERY].unlocked)
    {
        //TODO
    }
}

/*
    Checks if all achievements have been completed to unlock King of Liberty (1)
*/
void AchievementManager::CheckAllAchievementsComplete()
{
    if (!achievementList[KING_OF_LIBERTY_CITY].unlocked)
        for (int i = 0; i < NUM_ACHIEVEMENTS; i++)
            if (i != KING_OF_LIBERTY_CITY)
                if (!achievementList[i].unlocked)
                    return;
    achievementList[KING_OF_LIBERTY_CITY].unlocked = true;
    //TODO add to list of achievements to pop up somehow (events?)
}


