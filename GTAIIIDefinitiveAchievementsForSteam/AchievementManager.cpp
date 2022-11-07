#include <plugin.h>
#include "CWorld.h"
#include "CPickups.h"
#include "AchievementManager.h"



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
}

void AchievementManager::Save()
{
    //TODO: Saves achievements and helper data (any extra variables needed that aren't in the stats/saved in the savefile
}

/*
    Checks achievements based on game stats
*/
void AchievementManager::CheckStatBasedAchievements()
{
    //TODO: Disposing of the Evidence (1 car crushed)
    //TODO: Street Sweeper (100 gang members killed)
    //TODO: By a Mile (Turismo under 180 seconds)
    //TODO: Wreckless Driving (Perfect Insane Stunt)
    //TODO: Wheels Up (20 unique stunt jumps)
    //TODO: Where to? (100 Fares)
    //TODO: Man ToyZ (complete every Toyz)
    //TODO: Playing Doctor (Paramedic level >= 12)
    //TODO: Right-hand Man (>= 2500 criminal rating)
    //TODO: Furious First Responder (Paramedic level >= 12, 20 fires and 20 criminals in each island (these last two don't seem to have the variables needed, might need separate checker)
    //TODO: Liberty City Secrets (100 packages)
    //TODO: Is That All You've Got? (100% completion)
    //TODO: Hunting Season (Destroy 5 helis)
    //TODO: Repeat Offender (20 busts)
    //TODO: Cheaters do Prosper! (2000 vehicles destroyed)
    //TODO: Like a Boss (>= 5000 criminal rating)
    //TODO: Recycler (25 cars crushed)

}

void AchievementManager::CheckMissionCompleteAchievements()
{
    //Different check from Definitive, based on REGISTER_MISSION_PASSED strings
    //TODO:
}

void AchievementManager::CheckSpecialMissionAchievements()
{
    //stuff like Fuzz Ball and Chunky
    //TODO
}

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
    Checks for the money achievements
*/
void AchievementManager::CheckMoneyAchievements()
{
    //TODO:
    CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
    if (!achievementList[CHASING_PAPER].unlocked)
    {
        if (player->m_nMoney >= 500000)
        {
            achievementList[CHASING_PAPER].unlocked = true;
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }

    if (!achievementList[DIRTY_MONEY].unlocked)
    {
        if (player->m_nMoney >= 1000000)
        {
            achievementList[DIRTY_MONEY].unlocked = true;
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }
}

/*
    Checks if all achievements have been completed to unlock King of Liberty
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


