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
    void setExpanded(bool expanded);

private:
    enum ButtonState { IDLE, HOVER, ACTIVE, EXPANDED };
    ButtonState buttonState;
    bool expanded;
    bool mouseHeld; // Variable pour suivre si le bouton de la souris est enfoncé

    sf::RectangleShape shape;
    sf::Color idleColor_, hoverColor_, activeColor_;
};

#endif
