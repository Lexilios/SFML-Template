#include "Modules/WindowModule.h"

#include <iostream>
#include <SFML/Window/Event.hpp>

#include "Engine.h"

void WindowModule::Awake()
{
	Module::Awake();

	window = new sf::RenderWindow(sf::VideoMode(600, 600), "SFML Engine");
}

void WindowModule::PreRender()
{
	Module::PreRender();

	window->clear(sf::Color::Black);
}

void WindowModule::Present()
{
	Module::Present();

	window->display();
}

void WindowModule::Destroy()
{
	Module::Destroy();

	window->close();
}
