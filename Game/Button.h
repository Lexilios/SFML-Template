#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    void update(const sf::Vector2f& mousePos);
    void draw(sf::RenderWindow& window);
    bool isActive() const;
    void move(sf::Vector2f offset);
    sf::Vector2f getPosition() const;

private:
    enum ButtonState { IDLE, HOVER, ACTIVE };
    ButtonState buttonState;

    sf::RectangleShape shape;
    sf::Color idleColor_, hoverColor_, activeColor_;
};

#endif
