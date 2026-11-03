#include "src/game/envfx_snow.h"

const GeoLayout door_hallway_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, door_hallway_door_hallway_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, door_hallway_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
