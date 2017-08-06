#pragma once
#include "../sprite/sprite.h"

class Atlas {
    private:
        bool inMainMenu = true;
        Sprite mapAsset1Sprite;
        int map [4][6] = {
            {1, 0, 0, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 0, 0, 1}
        };
    public:
        void init();
        bool isInMainMenu();
        void leaveMainMenu();
        void update();
        void render();
};