#include "Window.h"

Window::Window() : window(sf::VideoMode(1920, 1080), "Moteur Custom"), console(1920.f, 1080.f) {
    // Ne pas ajouter le premier bouton
    // buttonManager.addButton(Button(1600.f, 0.f, 400.f, 50.f, sf::Color(157, 157, 157), sf::Color(116, 116, 116), sf::Color(42, 42, 42))); // 1er bouton

    for (int i = 0; i < 20; ++i) {
        float posY = 100.f + i * 400.f; // Augmentation de la distance entre les boutons à 100.f
        buttonManager.addButton(Button(1600.f, posY, 400.f, 20.f, sf::Color(116, 116, 116), sf::Color(96, 96, 96), sf::Color(42, 42, 42)));
    }

    inspectorRect.setPosition(1600.f, 0.f);
    inspectorRect.setSize(sf::Vector2f(400.f, 1080.f));
    inspectorRect.setFillColor(sf::Color(163, 163, 163, 100));

    console.setPosition(0.f, 900.f);
    console.setSize(1600.f, 400.f);

    scrollSpeed = 20.f;
    scrollStartIndex = 1;
}
void Window::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.delta > 0) {
                    buttonManager.moveButtons(sf::Vector2f(0.f, scrollSpeed), scrollStartIndex);
                }
                else if (event.mouseWheelScroll.delta < 0) {
                    buttonManager.moveButtons(sf::Vector2f(0.f, -scrollSpeed), scrollStartIndex);
                }
            }
        }

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

        // Mettre à jour les boutons, y compris le premier bouton
        buttonManager.update(mousePos);

        window.clear(sf::Color(222, 236, 255));

        window.draw(inspectorRect);
        buttonManager.draw(window);
        console.draw(window);

        drawHierarchy();

        window.display();
    }
}

void Window::drawHierarchy() {

    sf::RectangleShape hierarchySquare(sf::Vector2f(400.f, 900.f)); 
    hierarchySquare.setPosition(0.f, 0.f);
    hierarchySquare.setFillColor(sf::Color(174, 174, 174)); 

    window.draw(hierarchySquare);
}
