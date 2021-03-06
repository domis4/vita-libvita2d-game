#include "game-module.h"
#include "atlas/atlas.h"

void GameModule::init() {
    rad = 0.0f;
    vita2d_init();
    vita2d_set_clear_color(RGBA8(255, 255, 255, 255));
	pgf = vita2d_load_default_pgf();
    image = vita2d_load_PNG_file("app0:assets/image.png");
    titlescreen.init();
    fpsLimiter.init(false);
}

void GameModule::update() {
    extern Atlas atlas;
    rad += 0.1f;

    if (atlas.isInMainMenu()) {
        titlescreen.update();
    } else {
        atlas.update();
    }
}

void GameModule::initRender() {
    while(1) {
        render();
        update();
        fpsLimiter.limitFps();
    }
}
void GameModule::render() {
    extern Atlas atlas;
    vita2d_start_drawing();
    vita2d_clear_screen();

    if (atlas.isInMainMenu()) {
        titlescreen.render();
    } else {
        //delete &titlescreen;
        atlas.render();
    }

    //vita2d_draw_texture_rotate(image, 940/2, 544/2, rad);
    showFps();
    showDelta();
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

void GameModule::showFps() {
    char str[128]={0};
    sprintf(str, "FPS: %d", fpsLimiter.getFps());
    vita2d_pgf_draw_text(pgf, 16, 16, RGBA8(0, 0, 0, 255), 1.05f, str);
    vita2d_pgf_draw_text(pgf, 16, 16, RGBA8(255, 255, 255, 255), 1.0f, str);
}

void GameModule::showDelta() {
    char str[128]={0};
    sprintf(str, "Delta: %f", fpsLimiter.getDelta());
    vita2d_pgf_draw_text(pgf, 16, 48, RGBA8(0, 0, 0, 255), 1.05f, str);
    vita2d_pgf_draw_text(pgf, 16, 48, RGBA8(255, 255, 255, 255), 1.0f, str);
}