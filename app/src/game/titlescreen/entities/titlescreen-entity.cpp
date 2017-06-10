#include "titlescreen-entity.h"
#define PI 3.14159265
void TitlescreenEntity::init(Sprite _sprite, int _x, int _y) {
    sprite = _sprite;
    x = _x;
    y = _y;
}

void TitlescreenEntity::setSprite(Sprite _sprite) {
    sprite = _sprite;
}

void TitlescreenEntity::move() {
    
    if (mode == 0) {
        float xadd = (range - x + 1) / 100;
        xadd = xadd < 0.1 ? 0.1 : xadd;
        if (x < range) {
            x = x + (xadd*speed);
        } else {
            mode = 1;
        }
    } else {
        float xadd = (range - -1*(x  + 1)) / 100;
        xadd = xadd < 0.1 ? 0.1 : xadd;
        if (x > -range) {
            x = x - (xadd*speed);
        } else {
            mode = 0;
        }
    }
}

void TitlescreenEntity::render() {
    sprite.render(x, y);
}