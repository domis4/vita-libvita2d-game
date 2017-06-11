#pragma once
#include <vita2d.h>
#include <vector>
#include "../sprite/sprite.h"
#include "entities/titlescreen-entity.h"
#include "entities/titlescreen-selector-entity.h"

class TitlescreenModule {
    private:
        Sprite imgTitlescreen;
        Entity TitleScreenBackground;
        TitlescreenEntity right0Entity;
        TitlescreenEntity right1Entity;
        TitlescreenEntity right2Entity;
        TitlescreenEntity listEntity;
        TitlescreenSelectorEntity selectorEntity;
    public:
        void init();
        void render();
        void update();
};