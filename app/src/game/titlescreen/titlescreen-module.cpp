#include "titlescreen-module.h"

void TitlescreenModule::init() {
    imgTitlescreen = vita2d_load_PNG_file("app0:assets/titlescreen/titlescreen.png");
    /*imgRight0 = vita2d_load_PNG_file("app0:assets/titlescreen/right0.png");
    imgRight1 = vita2d_load_PNG_file("app0:assets/titlescreen/right1.png");
    imgRight2 = vita2d_load_PNG_file("app0:assets/titlescreen/right2.png");
    imgSelector = vita2d_load_PNG_file("app0:assets/titlescreen/selector.png");
    imgList = vita2d_load_PNG_file("app0:assets/titlescreen/list.png");*/
}

void TitlescreenModule::render() {
    vita2d_draw_texture(imgTitlescreen, 0, 0);
/*    vita2d_draw_texture(imgRight0, 0, 0);
    vita2d_draw_texture(imgRight1, 0, 0);
    vita2d_draw_texture(imgRight2, 0, 0);
    vita2d_draw_texture(imgSelector, 0, 0);
    vita2d_draw_texture(imgList, 0, 0);*/
}