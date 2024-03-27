#include <SFML/Graphics.hpp>
#include <vector>

class Button {
public:
    Button(float x, float y, float width, float height, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {
        buttonState = IDLE;

        shape.setPosition(sf::Vector2f(x, y));
        shape.setSize(sf::Vector2f(width, height));

        idleColor_ = idleColor;
        hoverColor_ = hoverColor;
        activeColor_ = activeColor;

        shape.setFillColor(idleColor_);

    }

    ~Button() {}

    void update(const sf::Vector2f& mousePos) {
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

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    bool isActive() const {
        return buttonState == ACTIVE;
    }

private:
    enum ButtonState { IDLE, HOVER, ACTIVE };
    ButtonState buttonState;

    sf::RectangleShape shape;
    sf::Color idleColor_, hoverColor_, activeColor_;
};

class ButtonManager {
public:
    void addButton(Button button) {
        buttons.push_back(button);
    }

    void update(const sf::Vector2f& mousePos) {
        for (auto& button : buttons) {
            button.update(mousePos);
        }
    }

    void draw(sf::RenderWindow& window) {
        for (auto& button : buttons) {
            button.draw(window);
        }
    }

private:
    std::vector<Button> buttons;
};

class Window {
public:
    Window() : window(sf::VideoMode(1920, 1080), "Moteur Custom") {
        buttonManager.addButton(Button(1600.f, 0.f, 400.f, 50.f, sf::Color::Red, sf::Color::Green, sf::Color::Blue));
        buttonManager.addButton(Button(1665.f, 100.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 180.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 260.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 340.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 420.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 500.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 580.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 660.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 740.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 820.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));
        buttonManager.addButton(Button(1665.f, 900.f, 200.f, 50.f, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan));

        inspectorRect.setPosition(1600.f, 0.f);
        inspectorRect.setSize(sf::Vector2f(400.f, 1080.f));
        inspectorRect.setFillColor(sf::Color(140, 140, 140));
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }



            sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));

            buttonManager.update(mousePos);

            window.clear();
            window.draw(inspectorRect);
            buttonManager.draw(window);
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    ButtonManager buttonManager;
    sf::RectangleShape inspectorRect;
};

int main() {
    Window app;
    app.run();

    return 0;
}