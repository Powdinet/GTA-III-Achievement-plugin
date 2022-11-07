#pragma once
#include <string>

#define NUM_ACHIEVEMENTS 44
#define BRIBE_MODEL_ID 115 //TODO: hope this works
//TODO #define ACH_SAVE_FILE some_string

struct AchievementDefinition {
	//TODO:
	std::string name;
	std::string description;
	std::string image; //TODO: probably raw image file imported at start of plugin
	bool unlocked;
};

enum AchievementID {
	FIRST_DAY_ON_THE_JOB = 0,
	WITHOUT_A_SCRATCH = 1,
	ESCAPE_ARTIST = 2,
	DISPOSTING_OF_THE_EVIDENCE = 3,
	MOB_BOSS = 4,
	STREET_SWEEPER = 5,
	PLANNED_AHEAD = 6,
	GOT_THIS_FIGURED_OUT = 7,
	BY_A_MILE = 8,
	WRECKLESS_DRIVING = 9,
	WHEELS_UP = 10,
	COME_OUT_TO_PLAY = 11,
	WHERE_TO = 12,
	LIBERTY_CITY_MINUTE = 13,
	FULL_ARTILLERY = 14,
	A_MARKED_MAN = 15,
	OFFSHORE_DELIVERY = 16,
	NOT_SO_FAST = 17,
	A_GIFT_FROM_THE_KING = 18,
	MAN_TOYZ = 19,
	SPLISH_SPLASH = 20,
	PLAYING_DOCTOR = 21,
	GOING_ROGUE = 22,
	DIRTY_MONEY = 23,
	RIGHT_HAND_MAN = 24,
	FURIOUS_FIRST_RESPONDER = 25,
	LIBERTY_CITY_SECRETS = 26,
	IS_THAT_ALL_YOUVE_GOT = 27,
	KING_OF_LIBERTY_CITY = 28,
	GOT_ANY_STORIES_OLD_MAN = 29,
	TALKS_A_LOT = 30,
	BLOOD_IN_THE_STREETS = 31,
	INSTIGATOR = 32,
	CHASING_PAPER = 33,
	AM_WALKIN_HERE = 34,
	HUNTING_SEASON = 35,
	REPEAT_OFFENDER = 36,
	CHEATERS_DO_PROSPER = 37,
	PLAY_FETCH = 38,
	PEST_CONTROL = 39,
	RELIEF_PITCHER = 40,
	LIKE_A_BOSS = 41,
	FARE_GAME = 42,
	RECYCLER = 43
};

class AchievementManager
{
public:
	//achievement list
	static AchievementDefinition achievementList[NUM_ACHIEVEMENTS];

	//helper variables
	static uint8_t bribes_pickedup;
	static uint8_t portland_criminals;
	static uint8_t staunton_criminals;
	static uint8_t firefighter_criminals;
	static uint8_t portland_fires;
	static uint8_t staunton_fires;
	static uint8_t firefighter_fires;

	//functions
	static void Init();
	static void Save();
	static void CheckStatBasedAchievements(); //15
	static void CheckMissionCompleteAchievements(); //6
	static void CheckSpecialMissionAchievements(); //4
	static void CheckBribeAchievement(); //1
	static void CheckMoneyAchievements(); //2
	static void CheckPhoneAchievement(); //1
	static void CheckRampageAchievements(); //2
	static void CheckFiresInARow(); //2
	static void CheckCriminalsInARow(); //2
	static void CheckFuriousFirstResponder(); //1
	static void CheckExportAchievements(); //2
	static void CheckGangsKillsAchievements(); //2
	static void CheckLibertyCityMinute(); //1
	static void CheckRoadkillAchievement(); //1
	static void CheckFullArtilleryAchievement(); //1
	static void CheckAllAchievementsComplete(); //1
};