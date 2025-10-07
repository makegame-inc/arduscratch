#include "Sprite.h"

Sprite::Sprite(String spriteName) : name(spriteName), visible(true) {}

void Sprite::show() { visible = true; }
void Sprite::hide() { visible = false; }
bool Sprite::isVisible() { return visible; }
String Sprite::getName() { return name; }

Sprite::~Sprite() {}