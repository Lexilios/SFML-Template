#pragma once

#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>

class ButtonManager {
public:
    void addButton(Button button);
    void update(const sf::Vector2f& mousePos);
    void draw(sf::RenderWindow& window);
    void moveButtons(sf::Vector2f offset, unsigned int startIndex);

private:
    std::vector<Button> buttons;
};

#endif // BUTTON_MANAGER_H
