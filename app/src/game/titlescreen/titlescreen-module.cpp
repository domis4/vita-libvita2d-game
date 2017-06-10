#include "titlescreen-module.h"

void TitlescreenModule::init() {
    std::vector<std::string> temp;
    temp.push_back("app0:assets/titlescreen/titlescreen.png");
    imgTitlescreen.init(temp);
    TitleScreenBackground.init(imgTitlescreen);

    std::vector<std::string> right0;
    right0.push_back("app0:assets/titlescreen/right0.png");
    Sprite right0Sprite;
    right0Sprite.init(right0);
    right0Entity.init(right0Sprite, 30, 0);

    std::vector<std::string> right1;
    right1.push_back("app0:assets/titlescreen/right1.png");
    Sprite right1Sprite;
    right1Sprite.init(right1);
    right1Entity.init(right1Sprite, 60, 0);

    std::vector<std::string> right2;
    right2.push_back("app0:assets/titlescreen/right2.png");
    Sprite right2Sprite;
    right2Sprite.init(right2);
    right2Entity.init(right2Sprite, 15, 0);

    std::vector<std::string> selector;
    selector.push_back("app0:assets/titlescreen/selector.png");
    Sprite selectorSprite;
    selectorSprite.init(selector);
    selectorEntity.init(selectorSprite, 0, 0);

    std::vector<std::string> list;
    list.push_back("app0:assets/titlescreen/list.png");
    Sprite listSprite;
    listSprite.init(list);
    listEntity.init(listSprite, 0, 0);

    // imgRight0 = vita2d_load_PNG_file("app0:assets/titlescreen/right0.png");
    // imgRight1 = vita2d_load_PNG_file("app0:assets/titlescreen/right1.png");
    // imgRight2 = vita2d_load_PNG_file("app0:assets/titlescreen/right2.png");
    // imgSelector = vita2d_load_PNG_file("app0:assets/titlescreen/selector.png");
    // imgList = vita2d_load_PNG_file("app0:assets/titlescreen/list.png");
}

void TitlescreenModule::render() {
    TitleScreenBackground.render();
    right0Entity.render();
    right1Entity.render();
    right2Entity.render();
    selectorEntity.render();
    listEntity.render();
}

void TitlescreenModule::update() {
    right0Entity.move();
    right1Entity.move();
    right2Entity.move();
}