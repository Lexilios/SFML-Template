#include "Console.h"

Console::Console(float width, float height) {
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(36, 36, 36));

    font.loadFromFile("arial.ttf"); // Charger la police de votre choix

    text.setFont(font);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);
    text.setPosition(10.f, height - 20.f); // Positionner le texte en bas de la console
}

void Console::addMessage(const std::string& message) {
    messages.push_back(message);
    updateText();
}

void Console::draw(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(text);
}

void Console::updateText() {
    std::string displayedText;
    for (const auto& message : messages) {
        displayedText += message + "\n";
    }
    text.setString(displayedText);
}

void Console::setPosition(float x, float y) {
    background.setPosition(x, y);
    text.setPosition(x + 10.f, y + background.getSize().y - 20.f);
}

void Console::setSize(float width, float height) {
    background.setSize(sf::Vector2f(width, height));
    text.setPosition(background.getPosition().x + 10.f, background.getPosition().y + background.getSize().y - 20.f);
}