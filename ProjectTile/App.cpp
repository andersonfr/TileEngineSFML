#include "src/App.h"
#include <iostream>

App::App() = default;

App::~App() = default;

int App::Init()
{
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800,600,32U), "TileEngine");
	if (window == nullptr)
		return 0;
	return 1;
	
}

void App::GameLoop()
{
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);

	while(window->isOpen())
	{
		HandleEvents();
		Update();
		Render();
	}
}

void App::StartApp()
{
	if (!Init())
		throw "Could not initialize app";

	GameLoop();
	
}

void App::HandleEvents()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

void App::Update()
{

}

void App::Render()
{
	window->clear();
	window->draw(shape);
	window->display();
}