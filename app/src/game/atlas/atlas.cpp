#include "atlas.h"

void Atlas::init() {

}

bool Atlas::isInMainMenu() {
    return inMainMenu;
}

void Atlas::leaveMainMenu() {
    inMainMenu = false;
    std::vector<std::string> mapAsset1;
    mapAsset1.push_back("app0:assets/map/1.png");
    Sprite mapAsset1Sprite;
    mapAsset1Sprite.init(mapAsset1);
}

void Atlas::update() {

}

void Atlas::render() {
    mapAsset1Sprite.render(32, 32);
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 5; j++) {
    //         mapAsset1Sprite.render(i*32, j*32);
    //     }
    // }
}