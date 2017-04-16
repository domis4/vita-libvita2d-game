#include "game-module.h"

void GameModule::init() {
    rad = 0.0f;

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0xFF, 0xFF, 0xFF, 0xFF));

    image = vita2d_load_PNG_file("app0:assets/image.png");
}

void GameModule::update() {

}

void GameModule::render() {
    vita2d_start_drawing();
    vita2d_clear_screen();

    vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);

    vita2d_end_drawing();
    vita2d_swap_buffers();

    rad += 0.1f;
}

void GameModule::end() {
    vita2d_fini();
	vita2d_free_texture(image);
	vita2d_free_pgf(pgf);
	vita2d_free_pvf(pvf);

	sceKernelExitProcess(0);
}