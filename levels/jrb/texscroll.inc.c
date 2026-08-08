void scroll_jrb_dl__Mesh_mesh_layer_1_vtx_11() {
	int i = 0;
	int count = 5;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl__Mesh_mesh_layer_1_vtx_11);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;
	deltaY = (int)(0.20000000298023224 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_jrb_dl_arch_003_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 82;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_arch_003_mesh_layer_1_vtx_3);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;
	deltaY = (int)(0.20000000298023224 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_jrb_dl_arch_008_mesh_layer_1_vtx_8() {
	int i = 0;
	int count = 7;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_arch_008_mesh_layer_1_vtx_8);

	deltaX = (int)(0.20000000298023224 * 0x20) % width;
	deltaY = (int)(0.20000000298023224 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_jrb() {
	scroll_jrb_dl__Mesh_mesh_layer_1_vtx_11();
	scroll_jrb_dl_arch_003_mesh_layer_1_vtx_3();
	scroll_jrb_dl_arch_008_mesh_layer_1_vtx_8();
};
