#include "sprite.h"

void Sprite::loadTexture(std::string texture_path) {
    vita2d_texture* tmp = vita2d_load_PNG_file(texture_path.c_str());
    textures.push_back(tmp);
}

void Sprite::init(std::vector<std::string> textures_paths) {
    for (auto texture_path : textures_paths) {  
        loadTexture(texture_path);
    }
}

void Sprite::render() {
    for (auto texture : textures) {  
        vita2d_draw_texture(texture, 0, 0);
    }
}