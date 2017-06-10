#pragma once
#include <cmath>
#include "../../entity/entity.h"

class TitlescreenEntity {
    private:
        Sprite sprite;
        bool isGraphical;
        float x = 0;
        float y = 0;
        int mode = 0;
        int range = 60;
        int speed = 1;
    public:
        void init(Sprite _sprite, int _x, int _y);
        void move();
        void setSprite(Sprite _sprite);
        void render();
};