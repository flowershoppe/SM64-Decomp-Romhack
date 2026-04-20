#include "src/game/envfx_snow.h"

const GeoLayout magic_platform_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, magic_platform_magic_platform_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, magic_platform_magic_platform_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, magic_platform_final_revert_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, magic_platform_magic_platform_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, magic_platform_final_revert_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, magic_platform_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
