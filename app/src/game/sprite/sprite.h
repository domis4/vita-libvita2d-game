#pragma once
#include <stdio.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <vita2d.h>

class Sprite {
    private:
        std::vector<vita2d_texture *> textures;
        int fps;
    public:
        void init(std::vector<std::string> textures);
        void loadTexture(std::string texture_path);
        void getFps();
        void render(float x, float y);
};