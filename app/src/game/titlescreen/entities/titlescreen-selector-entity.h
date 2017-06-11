#pragma once
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>

#include "../../entity/entity.h"
#include "../../atlas/atlas.h"

class TitlescreenSelectorEntity {
    private:
        Sprite sprite;
        bool isGraphical;
        float x = 0;
        float y = 0;
        SceCtrlData pad;
        bool button_is_pressed = false;
        int positions [4][2] = {
            {0, 0},
            {0, 51},
            {0, 98},
            {0, 150}
        };
        int index = 0;
    public:
        void init(Sprite _sprite, int _x, int _y);
        void update();
        void setSprite(Sprite _sprite);
        void render();
        void navigateMenu();
};