#pragma once
#include <vita2d.h>
#include <vector>
#include "../sprite/sprite.h"
#include "entities/titlescreen-entity.h"

class TitlescreenModule {
    private:
        Sprite imgTitlescreen;
        Entity TitleScreenBackground;
        TitlescreenEntity right0Entity;
        TitlescreenEntity right1Entity;
        TitlescreenEntity right2Entity;
        TitlescreenEntity selectorEntity;
        TitlescreenEntity listEntity;
    public:
        void init();
        void render();
        void update();
};