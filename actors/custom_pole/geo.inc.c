#include "src/game/envfx_snow.h"

const GeoLayout custom_pole_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_pole_custom_pole_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, custom_pole_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
