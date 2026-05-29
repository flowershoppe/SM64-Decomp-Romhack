#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_MIO0(0x0A, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x08, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0x05, _group2_mio0SegmentRomStart, _group2_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x01, LEVEL_WF, 0x01, 0x01, WARP_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_1UP, -123, 2768, 1775, 0, 0, 0, 0x00000000, bhv1Up),
		OBJECT(MODEL_BOWLING_BALL, 1887, 1108, 6971, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -2111, 1108, 6971, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_FLYGUY, -1102, 324, 2917, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_GOOMBA, -1512, -65, 2479, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 736, 125, 928, 0, 0, 0, 0x00000000, bhvGoomba),
		MARIO_POS(0x01, 180, -122, 0, 5848),
		OBJECT(MODEL_RED_COIN, 1215, 539, 6721, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -109, 47, 2832, 0, 0, 0, (5 << 16), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, 404, 553, 3888, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -107, 1108, 3127, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_CHUCKYA, -109, 2061, 3141, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_RED_COIN, -109, 1951, 3141, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1408, -301, 3508, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2227, 80, 7, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -144, 1129, 7019, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2799, 232, 4443, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_YELLOW_COIN, 1258, 940, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1258, 690, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1479, 940, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1258, 440, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1258, 190, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1258, -60, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1479, 690, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1479, 440, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1479, 190, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1479, -60, 5213, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 598, 803, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 654, 993, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 760, 1230, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 850, 1474, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 931, 1675, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 1015, 1878, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 1099, 2076, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -104, -286, 4818, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -104, -208, 4616, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -104, -140, 4414, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -105, -102, 2289, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -105, -24, 2088, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -105, 44, 1886, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -1277, 1515, 3096, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1029, 1514, 3096, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 1878, 760, 1230, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_HEART, -123, -254, 6220, 0, 180, 0, 0x00000000, bhvCheckpoint),
		OBJECT(MODEL_NONE, -123, 27, 6604, 0, 180, 0, (0 << 24) | (0x02 << 16), bhvAirborneWarp),
		OBJECT(MODEL_GIANT_FAN_WIDE, 1475, -625, 5100, 0, 0, 0, (20 << 24), bhvRotate),
		OBJECT(MODEL_GIANT_FAN_WIDE, -1550, -625, 5100, 0, 0, 0, (20 << 24), bhvRotate),
		OBJECT(MODEL_NONE, -90, 81, -190, 0, 0, 0, (0 << 24) | (0x01 << 16), bhvWarp),
		OBJECT(MODEL_YELLOW_COIN, -532, 566, 3880, 0, 0, 0, 0x00000000, bhvYellowCoin),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_MENU_FILE_SELECT),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, -122, 0, 5848),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};