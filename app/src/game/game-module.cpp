#include "game-module.h"

void GameModule::init() {
    rad = 0.0f;

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

    pgf = vita2d_load_default_pgf();
    pvf = vita2d_load_default_pvf();
    
    image = vita2d_load_PNG_file("app0:assets/image.png");
}

void GameModule::update() {

}

void GameModule::render() {
    vita2d_start_drawing();
    vita2d_clear_screen();

    vita2d_draw_rectangle(20, 20, 400, 250, RGBA8(255, 0, 0, 255));
    vita2d_draw_rectangle(680, 350, 100, 150, RGBA8(0, 0, 255, 255));
    vita2d_draw_fill_circle(200, 420, 100, RGBA8(0, 255,0 ,255));

    vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);

    vita2d_draw_line(500, 30, 800, 300, RGBA8(255, 0, 255, 255));

    vita2d_pgf_draw_text(pgf, 700, 30, RGBA8(0,255,0,255), 1.0f, "PGF Font sample!");

    vita2d_pvf_draw_text(pvf, 700, 80, RGBA8(0,255,0,255), 1.0f, "PVF Font sample!");

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