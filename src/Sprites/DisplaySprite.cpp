// #include "DisplaySprite.h"

// DisplaySprite::DisplaySprite(String name) : Sprite(name), display(nullptr), hasText(false) {}

// void DisplaySprite::setDisplay(U8G2* u8g2Display) {
//     display = u8g2Display;
// }

// void DisplaySprite::update() {
//     // Можно добавить логику анимации
// }

// void DisplaySprite::draw() {
//     if (visible && hasText && display) {
//         display->setCursor(x, y);
//         display->print(text);
//     }
// }

// void DisplaySprite::say(String newText) {
//     text = newText;
//     hasText = true;
// }

// void DisplaySprite::clear() {
//     text = "";
//     hasText = false;
// }