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
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		MARIO_POS(0x01, -90, 2094, 300, 0),
		OBJECT(MODEL_CUSTOM_PEACH, 1027, 0, -300, 0, 0, 0, (109 << 16), bhvCustomPeach),
		OBJECT(MODEL_BUTTERFLY, -993, 231, 177, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -1543, 231, -2460, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -1227, 231, 1901, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -852, 231, -186, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -1779, 231, -2094, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_BUTTERFLY, -1070, 231, -2535, 0, 0, 0, 0x00000000, bhvButterfly),
		OBJECT(MODEL_OWL, -6057, 1732, -221, 0, 0, 0, (23 << 16), bhvOwl),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -501, 0, 1743, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -537, 0, -1289, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, 1934, 0, -3003, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -1880, 0, 2690, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -6069, 1701, 394, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_MIST, -3377, -1301, -2987, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, -2987, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, -3387, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, -2587, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, -3787, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, -4187, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, -4587, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, 4713, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, 4313, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, 4313, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, 3913, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, 3513, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, 3113, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3377, -1301, 2713, 0, 141, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -3977, -1301, 2586, 0, -169, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -4283, -1301, 2329, 0, -169, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -4283, -1301, 2329, 0, -169, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -4590, -1301, 2072, 0, -169, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -4896, -1301, 1815, 0, -169, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5203, -1301, 1558, 0, -169, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -6137, -1301, -1789, 0, 71, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5761, -1301, -1926, 0, 71, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5761, -1301, -1926, 0, 71, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5385, -1301, -2062, 0, 71, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -5009, -1301, -2199, 0, 71, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -4633, -1301, -2336, 0, 71, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_MIST, -4257, -1301, -2473, 0, 71, 0, 0x00000000, bhvWaterMist2),
		OBJECT(MODEL_NONE, -7388, -801, -285, 0, 88, 0, 0x00000000, bhvWaterfallSoundLoop),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_INSIDE_CASTLE),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -90, 2094, 300, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};