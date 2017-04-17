#pragma once
#include <vita2d.h>

class TitlescreenModule {
    private:
        vita2d_texture *imgTitlescreen;
    public:
        void init();
        void render();
};