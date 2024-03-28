#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {
    buttonState = IDLE;
    expanded = false;
    mouseHeld = false; // Initialisation de la variable mouseHeld

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));

    idleColor_ = idleColor;
    hoverColor_ = hoverColor;
    activeColor_ = activeColor;

    shape.setFillColor(idleColor_);
}

Button::~Button() {}

void Button::update(const sf::Vector2f& mousePos) {
    // Vérifier si le pointeur de la souris est sur le bouton
    if (shape.getGlobalBounds().contains(mousePos)) {
        // Si le bouton de la souris est enfoncé, mettre à jour l'état
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!mouseHeld) {
                // Inverser l'état de déploiement à chaque clic
                expanded = !expanded;
                mouseHeld = true; // Indiquer que le bouton de la souris est enfoncé
            }
        }
        else {
            mouseHeld = false; // Indiquer que le bouton de la souris n'est plus enfoncé
        }

        // Mettre à jour l'état du bouton
        if (expanded)
            buttonState = ACTIVE;
        else
            buttonState = HOVER;
    }
    else {
        buttonState = IDLE;
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

    
    if (expanded) {
        sf::RectangleShape contentRect(sf::Vector2f(400.f, 400.f)); 
        contentRect.setFillColor(sf::Color(174,174,174));
        contentRect.setPosition(shape.getPosition().x, shape.getPosition().y + shape.getSize().y); 

        window.draw(contentRect);
    }
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

void Button::setExpanded(bool expanded) {
    this->expanded = expanded;
}

