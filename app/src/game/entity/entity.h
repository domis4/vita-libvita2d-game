#pragma once
#include "../sprite/sprite.h"

class Entity {
    protected:
        Sprite sprite;
        bool isGraphical;
        float x = 0;
        float y = 0;
    public:
        void init(Sprite sprite);
        void move();
        void setSprite(Sprite sprite);
        void render();
};