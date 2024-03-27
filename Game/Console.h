#pragma once

#ifndef CONSOLE_H
#define CONSOLE_H

#include <SFML/Graphics.hpp>
#include <deque>
#include <string>

class Console {
public:
    Console(float width, float height);

    void addMessage(const std::string& message);
    void setPosition(float x, float y);
    void setSize(float width, float height);

    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape background;
    sf::Font font;
    std::deque<std::string> messages;
    sf::Text text;

    void updateText();
};

#endif // CONSOLE_H