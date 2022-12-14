#pragma once
using namespace std;
#include <string.h>
#include "CSprite2d.h"

#define DEBUG true
#define NUM_ACHIEVEMENTS 44
#define BRIBE_MODEL_ID 1383 //TODO: hope this works

//TODO #define ACH_SAVE_FILE some_string

struct AchievementDefinition {
	string name;
	string description;
	string image;
	bool unlocked;
	CSprite2d *spriteData;

	AchievementDefinition()
	{
		unlocked = false;
		spriteData = nullptr;
	}
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

enum PlannedAheadState
{
	PA_WAITING_FOR_CHUNKY_TO_EXIST,
	PA_WAITING_FOR_CHUNKY_IN_ARMED_CAR,
	PA_WAITING_FOR_BOOM,
	PA_COMPLETE
};

//these can't be #defined because they need to be &ed to read from script
static uint32_t VIGILANTE_PORTLAND_KILLS_GLOBAL_INDEX = 1075 * 4;
static uint32_t VIGILANTE_STAUNTON_KILLS_GLOBAL_INDEX = 1076 * 4;
static uint32_t VIGILANTE_SHORESIDE_KILLS_GLOBAL_INDEX = 1077 * 4;
static uint32_t FIREFIGHTER_PORTLAND_FIRES_GLOBAL_INDEX = 1083 * 4;
static uint32_t FIREFIGHTER_STAUNTON_FIRES_GLOBAL_INDEX = 1084 * 4;
static uint32_t FIREFIGHTER_SHORESIDE_FIRES_GLOBAL_INDEX = 1085 * 4;
static uint32_t VIGILANTE_KILLS_IN_ROW_GLOBAL_INDEX = 1409 * 4;
static uint32_t FIREFIGHTER_FIRES_IN_ROW_GLOBAL_INDEX = 1371 * 4;
static uint32_t TOTAL_RAMPAGES_PASSED = 841 * 4;
static uint32_t LUIGIS_GIRLS_COMPLETED = 245 * 4;
static uint32_t LAST_REQUESTS_COMPLETED = 271 * 4;
static uint32_t DROP_IN_THE_OCEAN_COMPLETED = 337 * 4;
static uint32_t THE_EXCHANGE_COMPLETED = 368 * 4;
static uint32_t KINGDOM_COME_COMPLETED = 342 * 4;
static uint32_t CIPRIANIS_CHAUFFEUR_COMPLETED = 257 * 4;
static uint32_t MARTY_CHONKS_1_COMPLETED = 289 * 4;
static uint32_t MARTY_CHONKS_2_COMPLETED = 290 * 4;
static uint32_t MARTY_CHONKS_3_COMPLETED = 291 * 4;
static uint32_t MARTY_CHONKS_4_COMPLETED = 292 * 4;
static uint32_t EL_BURRO_1_COMPLETED = 300 * 4;//this is already an assist variable, "passed_before", perfect for me
static uint32_t EL_BURRO_2_COMPLETED = 279 * 4;
static uint32_t EL_BURRO_3_COMPLETED = 280 * 4;
static uint32_t EL_BURRO_4_COMPLETED = 281 * 4;
static uint32_t KING_COURTNEY_1_COMPLETED = 339 * 4;
static uint32_t KING_COURTNEY_2_COMPLETED = 340 * 4;
static uint32_t KING_COURTNEY_3_COMPLETED = 341 * 4;
static uint32_t KING_COURTNEY_4_COMPLETED = 342 * 4;
static uint32_t D_ICE_1_COMPLETED = 359 * 4;
static uint32_t D_ICE_2_COMPLETED = 360 * 4;
static uint32_t D_ICE_3_COMPLETED = 361 * 4;
static uint32_t D_ICE_4_COMPLETED = 362 * 4;
static uint32_t D_ICE_5_COMPLETED = 363 * 4;
static uint32_t CURLY_BOB_LEAVING_PLAYER_CAR_FLAG = 2104 * 4;
static uint32_t CURLY_BOB_PED = 2082 * 4;
static uint32_t FUZZ_BALL_CAR = 1664 * 4;
static uint32_t FUZZ_BALL_PROSTITUTE[8] = { 1683 * 4, 1684 * 4, 1685 * 4, 1686 * 4, 1687 * 4, 1688 * 4, 1689 * 4, 1690 * 4 };
static uint32_t CHUNKY_PED = 142 * 4;
static uint32_t CHUNKY_CAR1 = 1765 * 4;
static uint32_t CHUNKY_CAR2 = 1766 * 4;
static uint32_t TRIBULATIONS_MAFIA1 = 1955 * 4;
static uint32_t TRIBULATIONS_MAFIA2 = 1956 * 4;
static uint32_t TRIBULATIONS_TRIADSDEAD = 1945 * 4;
static uint32_t MIKE_LIPS_CAR = 1754 * 4;
static uint32_t MIKE_LIPS_PED = 141 * 4;
static uint32_t WITHOUT_A_SCRATCH_BLOCKED = 1760 * 4;
static uint32_t KING_COURTNEY_1_ASSIST = 343 * 4;
static uint32_t BRIBES_ASSIST = 285 * 4;
static uint32_t CHEAT_ASSIST = 286 * 4;
static uint32_t FULLARTILLERY_ASSIST = 287 * 4;
static uint32_t COMEOUTTOPLAY_ASSIST = 288 * 4;
static uint32_t LCM_STATE = 293 * 4;
static uint32_t LCM_START_TIME = 294 * 4;
static uint32_t COTP_GANG_MEMBERS_KILLED_LAST_FRAME = 295 * 4;
static uint32_t PA_STATE = 296 * 4;
static uint32_t PA_WHICH_CAR = 297 * 4;

bool isShooting(CPed* ped);
bool isGangMember(CPed* ped);
bool isCarArmedWithBomb(CVehicle* car);

//cheat variables
static char* cheat0 = "cheat";
static char* cheat1 = "Cheat";
static char* cheatmessage = "Games in which cheats have been activated cannot unlock achievements.";
static wchar_t* wcheat0 = new wchar_t[strlen(cheat0) + 1];
static wchar_t* wcheat1 = new wchar_t[strlen(cheat1) + 1];
static wchar_t* wcheatmessage = new wchar_t[strlen(cheatmessage) + 1];

//read values from script
static int32_t Read4BytesFromScript(uint32_t* pIp);
static int16_t Read2BytesFromScript(uint32_t* pIp);
static int8_t Read1ByteFromScript(uint32_t* pIp);
static float ReadFloatFromScript(uint32_t* pIp);
static void Write4BytesToScript(uint32_t* pIp, int32_t value);

class AchievementManager
{
public:
	//achievement list
	static AchievementDefinition achievementList[NUM_ACHIEVEMENTS];

	//functions
	static void Init();
	static void SetupTXDStore();
	static void RemoveTXDStore();
	static void SaveAchievements();
	static void ResetAchievements();
	static void CheckAchievements();
	static void CheckStatBasedAchievements(); //15
	static void CheckMissionCompleteAchievements(); //7
	static void CheckSpecialMissionAchievements(); //5
	static void CheckBribeAchievement(); //1
	static void CheckMoneyAchievements(); //2
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
};