#include "ButtonManager.h"

void ButtonManager::addButton(Button button) {
    buttons.push_back(button);
}

void ButtonManager::update(const sf::Vector2f& mousePos) {
    for (auto& button : buttons) {
        button.update(mousePos);
    }
}

void ButtonManager::draw(sf::RenderWindow& window) {
    for (auto& button : buttons) {
        button.draw(window);
    }
}

void ButtonManager::moveButtons(sf::Vector2f offset, unsigned int startIndex) {
    for (size_t i = startIndex; i < buttons.size(); ++i) {
        buttons[i].move(offset);
    }
}
