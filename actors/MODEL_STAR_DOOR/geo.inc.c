#include "src/game/envfx_snow.h"

const GeoLayout MODEL_STAR_DOOR_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, MODEL_STAR_DOOR_star_door_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, MODEL_STAR_DOOR_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
