#include <plugin.h>
#include "CWorld.h"
#include "CPickups.h"
#include "CStats.h"
#include "eWeaponType.h"
#include "CTimer.h"
#include "CTheScripts.h"
#include "CReplay.h"
#include "CHud.h"
#include "CGarages.h"
#include "CCranes.h"
#include "AchievementManager.h"

//achievement list
AchievementDefinition AchievementManager::achievementList[NUM_ACHIEVEMENTS];

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

    achievementList[DISPOSING_OF_THE_EVIDENCE].name = "Disposing of the Evidence";
    achievementList[DISPOSING_OF_THE_EVIDENCE].description = "Crush a car at the junkyard";

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
    //Just need to detect new games / save loads properly and save into those areas whenever the variables are updated (need separate functions for detecting new game/load game to load progression achievements correctly + reset helper variables)

    //setup cheat variables
    mbstowcs_s(NULL, wcheat0, strlen(cheat0) + 1, cheat0, strlen(cheat0));
    mbstowcs_s(NULL, wcheat1, strlen(cheat1) + 1, cheat1, strlen(cheat1));
    mbstowcs_s(NULL, wcheatmessage, strlen(cheatmessage) + 1, cheatmessage, strlen(cheatmessage));

    /*if(cheated)//TODO: do this on game loads
        CHud::SetHelpMessage(wcheatmessage, true);*/
}

void AchievementManager::SaveAchievements()
{
    //TODO: Runs every time an achievement is unlocked. Saves all achievements in a achievement data file
    //halper variables are stored in the actual game savefiles by editing the global variable space whenever they're updated, which isn't here
}

/*
    Runs all achievement checkers if the game is in conditions to do so
*/
void AchievementManager::CheckAchievements()
{
    CheckForCheats();
    if (!Read4BytesFromScript(&CHEAT_ASSIST))
    {
        if (!CTimer::m_UserPause && !CTimer::m_CodePause && !CReplay::Mode)
        {
            CheckStatBasedAchievements();
            CheckMissionCompleteAchievements();
            CheckSpecialMissionAchievements();
            CheckBribeAchievement();
            CheckMoneyAchievements();
            CheckRampageAchievements();
            CheckFiresInARow();
            CheckCriminalsInARow();
            CheckFuriousFirstResponder();
            CheckExportAchievements();
            CheckGangsKillsAchievements();
            CheckLibertyCityMinute();
            CheckRoadkillAchievement();
            CheckFullArtilleryAchievement();
            CheckAllAchievementsComplete();
        }
    }
    //DebugHelpPrint((char*)std::to_string(CWorld::Players[CWorld::PlayerInFocus].m_nCollectablesCollected).c_str());//TODO remove
}

/*
    Checks achievements based on game stats (15)
*/
void AchievementManager::CheckStatBasedAchievements()
{
    if (!achievementList[DISPOSING_OF_THE_EVIDENCE].unlocked &&
        CStats::CarsCrushed >= 1)
    {
        achievementList[DISPOSING_OF_THE_EVIDENCE].unlocked = true;
        DebugHelpPrint(DISPOSING_OF_THE_EVIDENCE);
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[BY_A_MILE].unlocked &&
        CStats::ElBurroTime < 180 &&
        CStats::ElBurroTime > 0)
    {
        achievementList[BY_A_MILE].unlocked = true;
        DebugHelpPrint(BY_A_MILE);
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[WRECKLESS_DRIVING].unlocked &&
        CStats::BestStuntJump > 0 && CStats::BestStuntJump % 2 == 0) //Perfect Stunts all have even values
    {
        achievementList[WRECKLESS_DRIVING].unlocked = true;
        DebugHelpPrint(WRECKLESS_DRIVING);
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[WHEELS_UP].unlocked &&
        CStats::NumberOfUniqueJumpsFound >= 20) //For some reason the variable is called "found", but it's completion
    {
        achievementList[WHEELS_UP].unlocked = true;
        DebugHelpPrint(WHEELS_UP);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[WHERE_TO].unlocked &&
        CStats::PassengersDroppedOffWithTaxi >= 100)
    {
        achievementList[WHERE_TO].unlocked = true;
        DebugHelpPrint(WHERE_TO);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[MAN_TOYZ].unlocked &&
        CStats::HighestScores[1] >= 1 && //Diablo Destruction
        CStats::HighestScores[2] >= 1 && //Mafia Massacre
        CStats::HighestScores[3] >= 1 && //Rumpo Rampage
        CStats::HighestScores[4] >= 1) //Casino Calamity
    {
        achievementList[MAN_TOYZ].unlocked = true;
        DebugHelpPrint(MAN_TOYZ);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
    
    if (!achievementList[PLAYING_DOCTOR].unlocked &&
        CStats::HighestLevelAmbulanceMission >= 12)
    {
        achievementList[PLAYING_DOCTOR].unlocked = true;
        DebugHelpPrint(PLAYING_DOCTOR);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
        //TODO test
    }

    int rating = CStats::FindCriminalRatingNumber();
    if (!achievementList[RIGHT_HAND_MAN].unlocked &&
        rating >= 2500)
    {
        achievementList[RIGHT_HAND_MAN].unlocked = true;
        DebugHelpPrint(RIGHT_HAND_MAN);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
    
    if (!achievementList[LIBERTY_CITY_SECRETS].unlocked)
    {
        CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
        if (player->m_nCollectablesCollected >= 100)
        {
            achievementList[LIBERTY_CITY_SECRETS].unlocked = true;
            DebugHelpPrint(LIBERTY_CITY_SECRETS);
            SaveAchievements();
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }
    
    if (!achievementList[IS_THAT_ALL_YOUVE_GOT].unlocked &&
        CStats::ProgressMade >= CStats::TotalProgressInGame)
    {
        achievementList[IS_THAT_ALL_YOUVE_GOT].unlocked = true;
        DebugHelpPrint(IS_THAT_ALL_YOUVE_GOT);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
    
    if (!achievementList[HUNTING_SEASON].unlocked &&
        CStats::HelisDestroyed >= 5)
    {
        achievementList[HUNTING_SEASON].unlocked = true;
        DebugHelpPrint(HUNTING_SEASON);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[REPEAT_OFFENDER].unlocked &&
        CStats::TimesArrested >= 20)
    {
        achievementList[REPEAT_OFFENDER].unlocked = true;
        DebugHelpPrint(REPEAT_OFFENDER);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[CHEATERS_DO_PROSPER].unlocked &&
        CStats::CarsExploded >= 2000)
    {
        achievementList[CHEATERS_DO_PROSPER].unlocked = true;
        DebugHelpPrint(CHEATERS_DO_PROSPER);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[LIKE_A_BOSS].unlocked &&
        rating >= 5000)
    {
        achievementList[LIKE_A_BOSS].unlocked = true;
        DebugHelpPrint(LIKE_A_BOSS);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
    
    if (!achievementList[RECYCLER].unlocked &&
        CStats::CarsCrushed >= 25)
    {
        achievementList[RECYCLER].unlocked = true;
        DebugHelpPrint(RECYCLER);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
}

/*
    Checks achievements that unlock on mission complete (7)
*/
void AchievementManager::CheckMissionCompleteAchievements()
{
    //Different check from Definitive, based on mission pass flags

    //First Day on the Job (Luigi's Girls)
    if (!achievementList[FIRST_DAY_ON_THE_JOB].unlocked &&
        Read4BytesFromScript(&LUIGIS_GIRLS_COMPLETED))
    {
        achievementList[FIRST_DAY_ON_THE_JOB].unlocked = true;
        DebugHelpPrint(FIRST_DAY_ON_THE_JOB);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    //A Marked Man (Last Requests)
    if (!achievementList[A_MARKED_MAN].unlocked &&
        Read4BytesFromScript(&LAST_REQUESTS_COMPLETED))
    {
        achievementList[A_MARKED_MAN].unlocked = true;
        DebugHelpPrint(A_MARKED_MAN);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    //Offshore Delivery (A Drop in the Ocean)
    if (!achievementList[OFFSHORE_DELIVERY].unlocked &&
        Read4BytesFromScript(&DROP_IN_THE_OCEAN_COMPLETED))
    {
        achievementList[OFFSHORE_DELIVERY].unlocked = true;
        DebugHelpPrint(OFFSHORE_DELIVERY);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    //Not So Fast (The Exchange)
    if (!achievementList[NOT_SO_FAST].unlocked &&
        Read4BytesFromScript(&THE_EXCHANGE_COMPLETED))
    {
        achievementList[NOT_SO_FAST].unlocked = true;
        DebugHelpPrint(NOT_SO_FAST);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    //A Gift From the King (Kingdom Come)
    if (!achievementList[A_GIFT_FROM_THE_KING].unlocked &&
        Read4BytesFromScript(&KINGDOM_COME_COMPLETED))
    {
        achievementList[A_GIFT_FROM_THE_KING].unlocked = true;
        DebugHelpPrint(A_GIFT_FROM_THE_KING);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    //Got Any Stories, Old Man? (Cipriani's Chaffeur)
    if (!achievementList[GOT_ANY_STORIES_OLD_MAN].unlocked &&
        Read4BytesFromScript(&CIPRIANIS_CHAUFFEUR_COMPLETED))
    {
        achievementList[GOT_ANY_STORIES_OLD_MAN].unlocked = true;
        DebugHelpPrint(GOT_ANY_STORIES_OLD_MAN);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[TALKS_A_LOT].unlocked)
    {
        //Note: Known issue: Bling Bling Scramble won't be marked complete in a save file that 
        //completed Kingdom Come before achievement plugin is installed. Nothing can be done about this.
        if (!Read4BytesFromScript(&KING_COURTNEY_1_ASSIST))
        {
            uint32_t value = Read4BytesFromScript(&KING_COURTNEY_1_COMPLETED);
            if (Read4BytesFromScript(&KING_COURTNEY_1_COMPLETED))
            {
                Write4BytesToScript(&KING_COURTNEY_1_ASSIST, 1);
            }
        }
        uint8_t phone_count =
            Read4BytesFromScript(&MARTY_CHONKS_1_COMPLETED) +
            Read4BytesFromScript(&MARTY_CHONKS_2_COMPLETED) +
            Read4BytesFromScript(&MARTY_CHONKS_3_COMPLETED) +
            Read4BytesFromScript(&MARTY_CHONKS_4_COMPLETED) +
            Read4BytesFromScript(&EL_BURRO_1_COMPLETED) +
            Read4BytesFromScript(&EL_BURRO_2_COMPLETED) +
            Read4BytesFromScript(&EL_BURRO_3_COMPLETED) +
            Read4BytesFromScript(&EL_BURRO_4_COMPLETED) +
            Read4BytesFromScript(&KING_COURTNEY_1_ASSIST) +
            Read4BytesFromScript(&KING_COURTNEY_2_COMPLETED) +
            Read4BytesFromScript(&KING_COURTNEY_3_COMPLETED) +
            Read4BytesFromScript(&KING_COURTNEY_4_COMPLETED) +
            Read4BytesFromScript(&D_ICE_1_COMPLETED) +
            Read4BytesFromScript(&D_ICE_2_COMPLETED) +
            Read4BytesFromScript(&D_ICE_3_COMPLETED) +
            Read4BytesFromScript(&D_ICE_4_COMPLETED) +
            Read4BytesFromScript(&D_ICE_5_COMPLETED);

        if (phone_count >= 17)
        {
            achievementList[TALKS_A_LOT].unlocked = true;
            DebugHelpPrint(TALKS_A_LOT);
            SaveAchievements();
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }
}

/*
    Checks achievements that unlock when certain conditions are met during missions (5)
*/
void AchievementManager::CheckSpecialMissionAchievements()
{
    //TODO: Without a Scratch (Mike Lips)
    if (!achievementList[WITHOUT_A_SCRATCH].unlocked)
    {
        if (!Read4BytesFromScript(&WITHOUT_A_SCRATCH_BLOCKED))
        {
            CVehicle* pCar = CPools::ms_pVehiclePool->GetAtRef(Read4BytesFromScript(&MIKE_LIPS_CAR));
            if (pCar && pCar->m_fHealth > 700 && !pCar->m_nVehicleFlags.bIsDamaged)
            {
                //In order for this mission to fail, the car has to be dead (which makes it eventually despawn)
                //timer has to run out
                //or player dies (which makes the car eventually despawn=
                //So need to check 
                CPed* pPed = CPools::ms_pPedPool->GetAtRef(Read4BytesFromScript(&MIKE_LIPS_PED));
                if (pPed)
                {
                    //If Mike Lips has spawned and we still managed to reach this, the job is done.
                    achievementList[WITHOUT_A_SCRATCH].unlocked = true;
                    DebugHelpPrint(WITHOUT_A_SCRATCH);
                    SaveAchievements();
                    //TODO add to list of achievements to pop up somehow (events?)
                }
            }
            else
            {
                //TODO: if a car with id 0 spawns, this could break. maybe write -1 for this
                //and for every other ped/car needed when a new game is started
                if (Read4BytesFromScript(&MIKE_LIPS_CAR))//check if a car has existed at some point in the past
                {
                    //car has despawned or been damaged, it's over
                    Write4BytesToScript(&WITHOUT_A_SCRATCH_BLOCKED, 1);
                }
            }
        }
    }

    //Mob Boss (Triads and Tribulations)
    if (!achievementList[MOB_BOSS].unlocked)
    {
        CPed* pMafia1 = CPools::ms_pPedPool->GetAtRef(Read4BytesFromScript(&TRIBULATIONS_MAFIA1));
        CPed* pMafia2 = CPools::ms_pPedPool->GetAtRef(Read4BytesFromScript(&TRIBULATIONS_MAFIA2));
        if (Read4BytesFromScript(&TRIBULATIONS_TRIADSDEAD) == 3) //mission pass condition
        {
            if (pMafia1 && pMafia1->m_fHealth > 0.0f &&
                pMafia2 && pMafia2->m_fHealth > 0.0f)
            {
                achievementList[MOB_BOSS].unlocked = true;
                DebugHelpPrint(MOB_BOSS);
                SaveAchievements();
                //TODO add to list of achievements to pop up somehow (events?)
            }
        }
    }

    //Planned Ahead
    if (!achievementList[PLANNED_AHEAD].unlocked)
    {
        //This code is very messy but there was no simple way to check it that worked
        CPed* pPed = CPools::ms_pPedPool->GetAtRef(Read4BytesFromScript(&CHUNKY_PED));
        switch (pa_state)
        {
        case PA_WAITING_FOR_CHUNKY_TO_EXIST:
            if (pPed)
            {
                pa_state = PA_WAITING_FOR_CHUNKY_IN_ARMED_CAR;
            }
            break;
        case PA_WAITING_FOR_CHUNKY_IN_ARMED_CAR:
            if (pPed)
            {
                if (pPed->m_bInVehicle)
                {
                    CVehicle* pCar1 = CPools::ms_pVehiclePool->GetAtRef(Read4BytesFromScript(&CHUNKY_CAR1));
                    CVehicle* pCar2 = CPools::ms_pVehiclePool->GetAtRef(Read4BytesFromScript(&CHUNKY_CAR2));
                    if (pPed->m_pVehicle == pCar1)
                    {
                        if(isCarArmedWithBomb(pCar1))
                            pa_which_car = 1;
                    }
                    else
                    {
                        if (pPed->m_pVehicle == pCar2)
                        {
                            if (isCarArmedWithBomb(pCar2))
                                pa_which_car = 2;
                        }
                    }
                    if (pa_which_car > 0)
                    {
                        pa_state = PA_WAITING_FOR_BOOM;
                    }
                }
            }
            else
            {
                //Chunky is dead before he got into an armed car
                pa_state = PA_WAITING_FOR_CHUNKY_TO_EXIST;
            }
            break;
        case PA_WAITING_FOR_BOOM:
            CVehicle* pCar = NULL;
            if (pa_which_car == 1)
                pCar = CPools::ms_pVehiclePool->GetAtRef(Read4BytesFromScript(&CHUNKY_CAR1));
            if (pa_which_car == 2)
                pCar = CPools::ms_pVehiclePool->GetAtRef(Read4BytesFromScript(&CHUNKY_CAR2));

            if (pCar)
            {
                if (pCar->m_fHealth > 0.0f)
                {
                    //car and Chunky should both still alive
                    CPed* pPed = CPools::ms_pPedPool->GetAtRef(Read4BytesFromScript(&CHUNKY_PED));
                    if (!pPed || pPed->m_fHealth <= 0.0f)
                    {
                        //Chunky dead but car isn't, reset
                        pa_state = PA_WAITING_FOR_CHUNKY_TO_EXIST;
                    }
                }
                else
                {
                    //Car has exploded, if Chunky was inside the car he would be removed instantly
                    //This technically allows player to kill Chunky outside the car and it will still count within the same frame
                    //but to be honest, the chances of that happening are 0.0000001%, and 99.9999999% of those times it would be the car bomb that would kill him anyway
                    if (!pPed || pPed->m_fHealth <= 0.0f)
                    {
                        //Well, he's dead...
                        achievementList[PLANNED_AHEAD].unlocked = true;
                        DebugHelpPrint(PLANNED_AHEAD);
                        SaveAchievements();
                        //TODO add to list of achievements to pop up somehow (events?)
                        pa_state = PA_COMPLETE;
                        
                    }
                    else
                    {
                        //Well, if ain't dead, the car certainly didn't kill him.
                        pa_state = PA_WAITING_FOR_CHUNKY_TO_EXIST;
                    }
                }
            }
            else
            {
                //Does a car explosion kill Chunky if nobody is around to hear it?
                pa_state = PA_WAITING_FOR_CHUNKY_TO_EXIST;
            }
            break;
        }
    }

    //Got This Figured Out
    if (!achievementList[GOT_THIS_FIGURED_OUT].unlocked)
    {
        //Definitive just checks if the number of passengers inside the Coach is 8
        //I'm checking if each prostitute is inside the Coach
        CVehicle* pCar = CPools::ms_pVehiclePool->GetAtRef(Read4BytesFromScript(&FUZZ_BALL_CAR));
        if (pCar)
        {
            if (pCar->m_nMaxPassengers == 8)
            {
                for (int i = 0; i < 8; i++)
                {
                    CPed* pPed = CPools::ms_pPedPool->GetAtRef(Read4BytesFromScript(&FUZZ_BALL_PROSTITUTE[i]));
                    if (!pPed || !pPed->m_bInVehicle || pPed->m_pVehicle != pCar)
                        return;
                }
                achievementList[GOT_THIS_FIGURED_OUT].unlocked = true;
                DebugHelpPrint(GOT_THIS_FIGURED_OUT);
                SaveAchievements();
                //TODO add to list of achievements to pop up somehow (events?)
            }
        }
        else
        {
            //Prevent being able to complete with old references
            //As unlikely as it is for the player to have a car and 8 passengers with the exact same ids as the ones Fuzz Ball set
            Write4BytesToScript(&FUZZ_BALL_CAR, -1);
        }
    }

    //Fare Game
    if (!achievementList[FARE_GAME].unlocked)
    {
        //flag_taxi1_exit_car_fm2
        //This flag is set when Curly Bob is told to leave player's car when it reaches the docks, which is the same as the definitive unlock timing
        //However, the flag is also set in the odd case where the mission fails when the player stays still for over 10000ms
        //The mission fails immediately and also deletes Curly immediately
        //Therefore, if flag_taxi1_exit_car_fm2 is set and if Curly Bob still exists, it is unlocked
        //As an extra condition (different from Definitive), I'm requiring Curly to start leaving the vehicle and not just simply triggering the marker
        //This is because Curly Bob doesn't start exiting (PEDSTATE_EXIT_CAR) right after being given the objective to do so (OBJECTIVE_LEAVE_CAR)
        //Usually this wouldn't matter, but this version has the glitch with pausing on markers to trigger them, so it makes sense to only unlock the achievement once he starts getting out.
        if (Read4BytesFromScript(&CURLY_BOB_LEAVING_PLAYER_CAR_FLAG)) //if Curly Bob told to leave car
        {
            CPed* pPed = CPools::ms_pPedPool->GetAtRef(Read4BytesFromScript(&CURLY_BOB_PED));
            if (pPed)
            {
                if (pPed->m_ePedState == PEDSTATE_EXIT_CAR)
                {
                    achievementList[FARE_GAME].unlocked = true;
                    DebugHelpPrint(FARE_GAME);
                    SaveAchievements();
                    //TODO add to list of achievements to pop up somehow (events?)
                }
            }
            else
            {
                //Variable only reset on mission start
                //Reset it here to prevent a random ped spawning with the same id later on triggering the unlock
                Write4BytesToScript(&CURLY_BOB_LEAVING_PLAYER_CAR_FLAG, -1);
            }
        }
    }


    //in general just mip won't be good because of duping and other manipulations
}

bool isCarArmedWithBomb(CVehicle* car)
{
    return ((CAutomobile*)car)->m_nAutomobileFlags.nBombType == BOMB_IGNITION_ACTIVATED ||
        ((CAutomobile*)car)->m_nAutomobileFlags.nBombType == BOMB_TIMED_ACTIVATED ||
        ((CAutomobile*)car)->m_nAutomobileFlags.nBombType == BOMB_STICKY;

}

/*
    Counts bribes and checks for the bribe achievement (1)
*/
void AchievementManager::CheckBribeAchievement()
{
    if (!achievementList[ESCAPE_ARTIST].unlocked)
    {
        //this is ugly
        for (int i = 0; i < 20; i++)
        {
            if (CPickups::aPickUpsCollected[i])
            {
                //TODO: there's a bug where if a bribe is picked up in a replay this entire thing breaks until the game is closed
                if (CPickups::aPickUps[CPickups::GetActualPickupIndex(CPickups::aPickUpsCollected[i])].m_nModelIndex == BRIBE_MODEL_ID)
                {
                    CPickups::aPickUpsCollected[i] = 0;
                    int32_t bribes_pickedup = Read4BytesFromScript(&BRIBES_ASSIST);
                    bribes_pickedup++;
                    DebugHelpPrint((char*)std::to_string(bribes_pickedup).c_str());
                    Write4BytesToScript(&BRIBES_ASSIST, bribes_pickedup);
                    if (bribes_pickedup >= 20)
                    {
                        achievementList[ESCAPE_ARTIST].unlocked = true;
                        DebugHelpPrint(ESCAPE_ARTIST);
                        SaveAchievements();
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
        DebugHelpPrint(CHASING_PAPER);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[DIRTY_MONEY].unlocked &&
        player->m_nMoney >= 1000000)
    {
        achievementList[DIRTY_MONEY].unlocked = true;
        DebugHelpPrint(DIRTY_MONEY);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
}

/*
    Checks the rampage completion achievements (2)
*/
void AchievementManager::CheckRampageAchievements()
{
    if (!achievementList[INSTIGATOR].unlocked &&
        Read4BytesFromScript(&TOTAL_RAMPAGES_PASSED) >= 10)
    {
        achievementList[INSTIGATOR].unlocked = true;
        DebugHelpPrint(INSTIGATOR);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[BLOOD_IN_THE_STREETS].unlocked &&
        Read4BytesFromScript(&TOTAL_RAMPAGES_PASSED) >= 20)
    {
        achievementList[BLOOD_IN_THE_STREETS].unlocked = true;
        DebugHelpPrint(BLOOD_IN_THE_STREETS);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
}

/*
    Checks the fires extinguished in a single session achievements (2)
*/
void AchievementManager::CheckFiresInARow()
{
    if (!achievementList[SPLISH_SPLASH].unlocked &&
        Read4BytesFromScript(&FIREFIGHTER_FIRES_IN_ROW_GLOBAL_INDEX) >= 15)
    {
        achievementList[SPLISH_SPLASH].unlocked = true;
        DebugHelpPrint(SPLISH_SPLASH);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }

    if (!achievementList[RELIEF_PITCHER].unlocked &&
        Read4BytesFromScript(&FIREFIGHTER_FIRES_IN_ROW_GLOBAL_INDEX) >= 20)
    {
        achievementList[RELIEF_PITCHER].unlocked = true;
        DebugHelpPrint(RELIEF_PITCHER);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
}

/*
    Checks the criminals killed in a single session achievements (1)
*/
void AchievementManager::CheckCriminalsInARow()
{
    if (!achievementList[GOING_ROGUE].unlocked &&
        Read4BytesFromScript(&VIGILANTE_KILLS_IN_ROW_GLOBAL_INDEX) >= 15)
    {
        achievementList[GOING_ROGUE].unlocked = true;
        DebugHelpPrint(GOING_ROGUE);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
    }
}

/*
    Checks for Furious First Responder (1)
*/
void AchievementManager::CheckFuriousFirstResponder()
{
    if (!achievementList[FURIOUS_FIRST_RESPONDER].unlocked &&
        CStats::HighestLevelAmbulanceMission >= 12 &&
        Read4BytesFromScript(&VIGILANTE_PORTLAND_KILLS_GLOBAL_INDEX) >= 20 &&
        Read4BytesFromScript(&VIGILANTE_STAUNTON_KILLS_GLOBAL_INDEX) >= 20 &&
        Read4BytesFromScript(&VIGILANTE_SHORESIDE_KILLS_GLOBAL_INDEX) >= 20 &&
        Read4BytesFromScript(&FIREFIGHTER_PORTLAND_FIRES_GLOBAL_INDEX) >= 20 &&
        Read4BytesFromScript(&FIREFIGHTER_STAUNTON_FIRES_GLOBAL_INDEX) >= 20 &&
        Read4BytesFromScript(&FIREFIGHTER_SHORESIDE_FIRES_GLOBAL_INDEX) >= 20)
    {
        achievementList[FURIOUS_FIRST_RESPONDER].unlocked = true;
        DebugHelpPrint(FURIOUS_FIRST_RESPONDER);
        SaveAchievements();
        //TODO add to list of achievements to pop up somehow (events?)
//TODO: test
    }
}

/*
    Checks for the export garages and emergency crane achievements (2)
*/
void AchievementManager::CheckExportAchievements()
{
    if (!achievementList[PLAY_FETCH].unlocked)
    {
        if (CGarages::CarTypesCollected[0] == 0xFFFF && CGarages::CarTypesCollected[1] == 0xFFFF)
        {
            achievementList[PLAY_FETCH].unlocked = true;
            DebugHelpPrint(PLAY_FETCH);
            SaveAchievements();
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }

    if (!achievementList[PEST_CONTROL].unlocked)
    {
        if (CCranes::CarsCollectedMilitaryCrane == 0x7F)
        {
            achievementList[PEST_CONTROL].unlocked = true;
            DebugHelpPrint(PEST_CONTROL);
            SaveAchievements();
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }
}

/*
    Counts gang members kills and checks for the achievements (2)
*/
void AchievementManager::CheckGangsKillsAchievements()
{
    uint32_t gangKillsThisFrame = CStats::PedsKilledOfThisType[PEDTYPE_GANG9]//TODO: make sure these are defined
        + CStats::PedsKilledOfThisType[PEDTYPE_GANG8] + CStats::PedsKilledOfThisType[PEDTYPE_GANG7]
        + CStats::PedsKilledOfThisType[PEDTYPE_GANG6] + CStats::PedsKilledOfThisType[PEDTYPE_GANG5]
        + CStats::PedsKilledOfThisType[PEDTYPE_GANG4] + CStats::PedsKilledOfThisType[PEDTYPE_GANG3]
        + CStats::PedsKilledOfThisType[PEDTYPE_GANG2] + CStats::PedsKilledOfThisType[PEDTYPE_GANG1];

    if (!achievementList[STREET_SWEEPER].unlocked)
    {
        if (gangKillsThisFrame >= 100)
        {
            achievementList[STREET_SWEEPER].unlocked = true;
            DebugHelpPrint(STREET_SWEEPER);
            SaveAchievements();
            //TODO add to list of achievements to pop up somehow (events?)
        }
    }

    if (!achievementList[COME_OUT_TO_PLAY].unlocked)
    {
        int nPoolSize = CPools::ms_pPedPool->m_nSize;

        //CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
        //for (int32_t i = 0; i < ((CPed*)(player->m_pPed))->m_nNumNearPeds; i++) //doesn't work because nearpeds doesn't mean always the closest peds, so it wasn't registering many kills properly
        for (int i = 0; i < nPoolSize; i++)
        {
            //CPed* victimPed = ((CPed*)(player->m_pPed))->m_apNearPeds[i];
            CPed* victimPed = CPools::ms_pPedPool->GetAt(i);

            if (victimPed)
            {
                if ((victimPed->m_ePedState == PEDSTATE_DEAD || victimPed->m_ePedState == PEDSTATE_DIE) &&
                    isGangMember(victimPed) &&
                    (victimPed->m_nLastWepDam == WEAPONTYPE_UNARMED || victimPed->m_nLastWepDam == WEAPONTYPE_BASEBALLBAT))
                {
                    //Note: can't check directly for who damaged the ped (feature added in VC)
                    //Work around is checking if the number of gangmembers killed by player has increased since last frame
                    //99%+ of the time this will be correct, it's very unlikely for the player to kill someone
                    //with a bat and another weapon in the same frame
                    if (gangKillsThisFrame > cotpGangMembersKilledLastFrame)
                    {
                        Write4BytesToScript(&COMEOUTTOPLAY_ASSIST, Read4BytesFromScript(&COMEOUTTOPLAY_ASSIST) + 1);
                        victimPed->m_nLastWepDam = -1;
                    }
                }
            }
        }
        if (Read4BytesFromScript(&COMEOUTTOPLAY_ASSIST) >= 25)
        {
            achievementList[COME_OUT_TO_PLAY].unlocked = true;
            DebugHelpPrint(COME_OUT_TO_PLAY);
            SaveAchievements();
            //TODO add to list of achievements to pop up somehow (events?)
        }
        cotpGangMembersKilledLastFrame = gangKillsThisFrame;
    }
}

static bool isGangMember(CPed* ped)
{
    return (ped->m_ePedType == PEDTYPE_GANG1 || ped->m_ePedType == PEDTYPE_GANG2 ||
            ped->m_ePedType == PEDTYPE_GANG3 || ped->m_ePedType == PEDTYPE_GANG4 ||
            ped->m_ePedType == PEDTYPE_GANG5 || ped->m_ePedType == PEDTYPE_GANG6 ||
            ped->m_ePedType == PEDTYPE_GANG7 || ped->m_ePedType == PEDTYPE_GANG8 ||
            ped->m_ePedType == PEDTYPE_GANG9);
}

/*
    Checks time player has been under 10HP and unlocks that achievement (1)
*/
void AchievementManager::CheckLibertyCityMinute()
{
    if (!achievementList[LIBERTY_CITY_MINUTE].unlocked)
    {
        CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
        switch (lcmState)
        {
            //I don't know if definitive achievement takes armor into account but it should
        case LCM_WAITING_FOR_10HP:

            if (player->m_nPlayerState == PLAYERSTATE_PLAYING &&
                player->m_pPed->m_fHealth + player->m_pPed->m_fArmour < 10.0f &&
                player->m_pPed->m_fHealth > 0.0f)
            {
                lcmStartTime = CTimer::m_snTimeInMilliseconds;
                lcmState = LCM_AT_LESS_THAN_10HP;
            }
            break;
        case LCM_AT_LESS_THAN_10HP:
            if (player->m_nPlayerState == PLAYERSTATE_PLAYING &&
                (player->m_pPed->m_fHealth) + (player->m_pPed->m_fArmour) < 10.0f &&
                player->m_pPed->m_fHealth > 0.0f)
            {
                if (CTimer::m_snTimeInMilliseconds - lcmStartTime >= 60000)
                {
                    achievementList[LIBERTY_CITY_MINUTE].unlocked = true;
                    DebugHelpPrint(LIBERTY_CITY_MINUTE);
                    SaveAchievements();
                    //TODO add to list of achievements to pop up somehow (events?)
                    lcmState = LCM_COMPLETE;
                }
            }
            else
            {//TODO:test the reset
                lcmState = LCM_WAITING_FOR_10HP;
            }
            //TODO:
            break;
        case LCM_COMPLETE:
            break;
        }
    }
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
                DebugHelpPrint(AM_WALKIN_HERE);
                SaveAchievements();
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
        CPlayerInfo* player = &CWorld::Players[CWorld::PlayerInFocus];
        if (isShooting(player->m_pPed))
        {
            uint32_t fullArtilleryWeaponBitMask = (uint32_t)Read4BytesFromScript(&FULLARTILLERY_ASSIST);
            fullArtilleryWeaponBitMask |= 1 << player->m_pPed->m_nCurrentWeapon;
            Write4BytesToScript(&FULLARTILLERY_ASSIST, fullArtilleryWeaponBitMask);
            if ((fullArtilleryWeaponBitMask & 0x1FFF) == 0xFFF)
            {
                achievementList[FULL_ARTILLERY].unlocked = true;
                DebugHelpPrint(FULL_ARTILLERY);
                SaveAchievements();
                //TODO add to list of achievements to pop up somehow (events?)
            }
        }
    }
}

bool isShooting(CPed* ped)
{
    //TODO: there's a bug where it doesn't count as attacking when player is punching while walking at the same time
    //TODO: there's a bug where after punching the attacking flag is set until something else resets it, so if player switches to bat it still counts even if it isn't used
    return ped->m_nCurrentWeapon > 1  && (ped->m_nPedFlags.bIsShooting) || //on bullet shot/projectile launched 
           ped->m_nCurrentWeapon <= 1 && (ped->m_nPedFlags.bIsAttacking); //on attack
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
    DebugHelpPrint(KING_OF_LIBERTY_CITY);
    SaveAchievements();
    //TODO add to list of achievements to pop up somehow (events?)
    //TODO: test
}

void AchievementManager::CheckForCheats()
{
    if (Read4BytesFromScript(&CHEAT_ASSIST))
        return;
    //This is a hacky solution but I don't think I can do better
    if (wcsstr(CHud::m_HelpMessage, wcheat0)||
        wcsstr(CHud::m_HelpMessage, wcheat1))
    {
        Write4BytesToScript(&CHEAT_ASSIST, 1);
        CHud::SetHelpMessage(wcheatmessage, false);
    }
}

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

int32_t Read4BytesFromScript(uint32_t* pIp) {
    int32_t retval = CTheScripts::ScriptSpace[*pIp + 3] << 24 | CTheScripts::ScriptSpace[*pIp + 2] << 16 | CTheScripts::ScriptSpace[*pIp + 1] << 8 | CTheScripts::ScriptSpace[*pIp];
    return retval;
}
int16_t Read2BytesFromScript(uint32_t* pIp) {
    int16_t retval = CTheScripts::ScriptSpace[*pIp + 1] << 8 | CTheScripts::ScriptSpace[*pIp];
    return retval;
}
int8_t Read1ByteFromScript(uint32_t* pIp) {
    int8_t retval = CTheScripts::ScriptSpace[*pIp];
    return retval;
}
float ReadFloatFromScript(uint32_t* pIp) {
    return Read2BytesFromScript(pIp) / 16.0f;
}

void Write4BytesToScript(uint32_t* pIp, int32_t value)
{
    *(int32_t*)&CTheScripts::ScriptSpace[*pIp] = value;
}
