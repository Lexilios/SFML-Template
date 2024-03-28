#include "Hierarchy.h"
#include "Button.h"
#include "Console.h"
#include "ButtonManager.h"

class Window {
public:
    Window();
    void run();

private:
    sf::RenderWindow window;
    ButtonManager buttonManager;
    sf::RectangleShape inspectorRect;
    float scrollSpeed;
    unsigned int scrollStartIndex;
    Console console;
    std::shared_ptr<HierarchyNode> sceneHierarchy;
};
