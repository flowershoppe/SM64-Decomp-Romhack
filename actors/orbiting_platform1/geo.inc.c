#include "src/game/envfx_snow.h"

const GeoLayout orbiting_platform1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, orbiting_platform1_orbiting_platform1_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, orbiting_platform1_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
