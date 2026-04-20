#include "src/game/envfx_snow.h"

const GeoLayout giant_fan_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, giant_fan_giant_fan_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, giant_fan_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
