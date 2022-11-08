#pragma once
using namespace std;
#include <string.h>

#define DEBUG true
#define NUM_ACHIEVEMENTS 44
#define BRIBE_MODEL_ID 115 //TODO: hope this works

//TODO #define ACH_SAVE_FILE some_string

struct AchievementDefinition {
	//TODO:
	string name;
	string description;
	string image; //TODO: probably raw image file imported at start of plugin
	bool unlocked;
};

enum AchievementID {
	FIRST_DAY_ON_THE_JOB = 0,
	WITHOUT_A_SCRATCH = 1,
	ESCAPE_ARTIST = 2,
	DISPOSING_OF_THE_EVIDENCE = 3,
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

enum LibertyCityMinuteState
{
	LCM_WAITING_FOR_10HP,
	LCM_AT_LESS_THAN_10HP,
	LCM_COMPLETE
};
//lcm variables not saved!
static uint8_t lcmState = LCM_WAITING_FOR_10HP;
static uint32_t lcmStartTime;

//these can't be #defined because they need to be &d to read from script
static uint32_t VIGILANTE_PORTLAND_KILLS_GLOBAL_INDEX = 1075 * 4;
static uint32_t VIGILANTE_STAUNTON_KILLS_GLOBAL_INDEX = 1076 * 4;
static uint32_t VIGILANTE_SHORESIDE_KILLS_GLOBAL_INDEX = 1077 * 4;
static uint32_t FIREFIGHTER_PORTLAND_FIRES_GLOBAL_INDEX = 1083 * 4;
static uint32_t FIREFIGHTER_STAUNTON_FIRES_GLOBAL_INDEX = 1084 * 4;
static uint32_t FIREFIGHTER_SHORESIDE_FIRES_GLOBAL_INDEX = 1085 * 4;
static uint32_t VIGILANTE_KILLS_IN_ROW_GLOBAL_INDEX = 1409 * 4;
static uint32_t FIREFIGHTER_FIRES_IN_ROW_GLOBAL_INDEX = 1371 * 4;
static uint32_t TOTAL_RAMPAGES_PASSED = 841 * 4;

bool isShooting(CPed* ped);

//cheat variables
static char* cheat0 = "cheat";
static char* cheat1 = "Cheat";
static char* cheatmessage = "Games in which cheats have been activated cannot unlock achievements.";
static wchar_t* wcheat0 = new wchar_t[strlen(cheat0) + 1];
static wchar_t* wcheat1 = new wchar_t[strlen(cheat1) + 1];
static wchar_t* wcheatmessage = new wchar_t[strlen(cheatmessage) + 1];

//debug print
void DebugHelpPrint(int achievementID);
void DebugHelpPrint(char* message);
static int debugNextPrintTime;

class AchievementManager
{
public:
	//achievement list
	static AchievementDefinition achievementList[NUM_ACHIEVEMENTS];

	//helper variables
	static uint8_t bribes_pickedup;
	static bool cheated;
	static uint16_t fullArtilleryWeaponBitMask;

	//functions
	static void Init();
	static void Save();
	static void CheckAchievements();
	static void CheckStatBasedAchievements(); //15
	static void CheckMissionCompleteAchievements(); //6
	static void CheckSpecialMissionAchievements(); //5
	static void CheckBribeAchievement(); //1
	static void CheckMoneyAchievements(); //2
	static void CheckPhoneAchievement(); //1
	static void CheckRampageAchievements(); //2
	static void CheckFiresInARow(); //2
	static void CheckCriminalsInARow(); //1
	static void CheckFuriousFirstResponder(); //1
	static void CheckExportAchievements(); //2
	static void CheckGangsKillsAchievements(); //2
	static void CheckLibertyCityMinute(); //1
	static void CheckRoadkillAchievement(); //1
	static void CheckFullArtilleryAchievement(); //1
	static void CheckAllAchievementsComplete(); //1
	static void CheckForCheats();
	//TODO: This should be defined via plugin to call the game's function directly
	static int32_t Read4BytesFromScript(uint32_t* pIp);
};