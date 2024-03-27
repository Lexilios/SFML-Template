#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "ButtonManager.h"
#include "Console.h"

class Window {
public:
    Window();
    void run();

private:
    void drawHierarchy(); // Ajoutez cette m�thode pour dessiner la hi�rarchie

    sf::RenderWindow window;
    ButtonManager buttonManager;
    sf::RectangleShape inspectorRect;
    float scrollSpeed;
    unsigned int scrollStartIndex;
    Console console;
};

#endif // WINDOW_H
