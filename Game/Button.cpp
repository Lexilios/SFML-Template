#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {
    buttonState = IDLE;

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));

    idleColor_ = idleColor;
    hoverColor_ = hoverColor;
    activeColor_ = activeColor;

    shape.setFillColor(idleColor_);
}

Button::~Button() {}

void Button::update(const sf::Vector2f& mousePos) {
    buttonState = IDLE;

    if (shape.getGlobalBounds().contains(mousePos)) {
        buttonState = HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            buttonState = ACTIVE;
    }

    switch (buttonState) {
    case IDLE:
        shape.setFillColor(idleColor_);
        break;
    case HOVER:
        shape.setFillColor(hoverColor_);
        break;
    case ACTIVE:
        shape.setFillColor(activeColor_);
        break;
    }
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Button::isActive() const {
    return buttonState == ACTIVE;
}

void Button::move(sf::Vector2f offset) {
    shape.move(offset);
}

sf::Vector2f Button::getPosition() const {
    return shape.getPosition();
}
