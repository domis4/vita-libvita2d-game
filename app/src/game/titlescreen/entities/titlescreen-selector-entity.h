#pragma once
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>

#include "../../entity/entity.h"

class TitlescreenSelectorEntity {
    private:
        Sprite sprite;
        bool isGraphical;
        float x = 0;
        float y = 0;
        SceCtrlData pad;
        bool button_is_pressed = false;
        int positions [4][2] = {
            {557, -22},
            {557, 38},
            {557, 96},
            {557, 153}
        };
        int index = 0;
    public:
        void init(Sprite _sprite, int _x, int _y);
        void update();
        void setSprite(Sprite _sprite);
        void render();
        void navigateMenu();
};