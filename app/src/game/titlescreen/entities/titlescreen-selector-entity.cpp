#include "titlescreen-selector-entity.h"

void TitlescreenSelectorEntity::init(Sprite _sprite, int _x, int _y) {
    sprite = _sprite;
    x = _x;
    y = _y;
    memset(&pad, 0, sizeof(pad));
}

void TitlescreenSelectorEntity::setSprite(Sprite _sprite) {
    sprite = _sprite;
}

void TitlescreenSelectorEntity::update() {
    sceCtrlPeekBufferPositive(0, &pad, 1);
    navigateMenu();

}
void TitlescreenSelectorEntity::render() {
    sprite.render(positions[index][0], positions[index][1]);
}

void TitlescreenSelectorEntity::navigateMenu() {
    button_is_pressed = button_is_pressed && pad.buttons;
    if (pad.buttons & SCE_CTRL_DOWN && !button_is_pressed) {
        if (index < 3) {
            index++;
        } else {
            index = 0;
        }
        button_is_pressed = true;
    }
    if (pad.buttons & SCE_CTRL_UP && !button_is_pressed) {
        if (index > 0) {
            index--;
        } else {
            index = 3;
        }
        button_is_pressed = true;
    }
}