#include "src/game/envfx_snow.h"

const GeoLayout small_fan_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, small_fan_small_fan_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, small_fan_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
