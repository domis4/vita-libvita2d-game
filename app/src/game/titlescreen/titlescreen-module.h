#pragma once
#include <vita2d.h>
#include "../sprite/sprite.h"

class TitlescreenModule {
    private:
        vita2d_texture *imgTitlescreen;
        vita2d_texture *imgRight0;
        vita2d_texture *imgRight1;
        vita2d_texture *imgRight2;
        vita2d_texture *imgSelector;
        vita2d_texture *imgList;
    public:
        void init();
        void render();
};