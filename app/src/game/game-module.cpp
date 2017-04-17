#include "game-module.h"

void GameModule::init() {
    rad = 0.0f;
    vita2d_init();
    vita2d_set_clear_color(RGBA8(255, 255, 255, 255));
	pgf = vita2d_load_default_pgf();
    image = vita2d_load_PNG_file("app0:assets/image.png");
    TitlescreenModule titlescreen;
    titlescreen.init();
}

void GameModule::update() {
    rad += 0.1f;
}

void GameModule::initRender() {
    while(1) {
        render();
        update();
    }
}
void GameModule::render() {
    vita2d_start_drawing();
    vita2d_clear_screen();

    titlescreen.render();

    vita2d_pgf_draw_text(pgf, 16, 16, RGBA8(0, 0, 0, 255), 1.0f, "fps" );
    vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);

    vita2d_end_drawing();
    vita2d_swap_buffers();
}

void GameModule::end() {
    vita2d_fini();
	vita2d_free_texture(image);
	vita2d_free_pgf(pgf);
	vita2d_free_pvf(pvf);

	sceKernelExitProcess(0);
}