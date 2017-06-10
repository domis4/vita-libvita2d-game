#include "entity.h"

void Entity::init(Sprite _sprite) {
    sprite = _sprite;
}

void Entity::setSprite(Sprite _sprite) {
    sprite = _sprite;
}

void Entity::move() {}

void Entity::render() {
    sprite.render(0, 0);
}