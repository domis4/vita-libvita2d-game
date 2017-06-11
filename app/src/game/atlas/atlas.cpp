#include "atlas.h"

void Atlas::init() {

}

bool Atlas::isInMainMenu() {
    return inMainMenu;
}

void Atlas::leaveMainMenu() {
    inMainMenu = false;
}