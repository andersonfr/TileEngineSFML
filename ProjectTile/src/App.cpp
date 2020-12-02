#include "App.h"
#include <iostream>

App::App() = default;

App::~App() = default;

int App::Init()
{
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1366, 768,32U), "TileEngine");
	if (window == nullptr)
		return 0;
	return 1;
	
}

void App::GameLoop()
{
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);
	m_holder.Load<TextureID>(TextureID::TEXTURE_ID_TILEMAP_GRASS, "assets/textures/grass.png");
	m_holder.Load<TextureID>(TextureID::TEXTURE_ID_PLAYER_CHARACTER, "assets/textures/player.png");
	m_holder.Load<TextureID>(TextureID::TEXTURE_ID_TILEMAP_PIXELATLAS, "assets/textures/PixelAtlas.png");
	//s.setTexture(holder.Get<sf::Texture>(TextureID::TEXTURE_ID_TILEMAP_GRASS));
	// define the level with an array of tile indices

	m_world.LoadWorld("pixelatlas.csv", m_holder.Get<sf::Texture>(TextureID::TEXTURE_ID_TILEMAP_PIXELATLAS));
	player.Init();

	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};
	
	//tm.Load(holder.Get<sf::Texture>(TextureID::TEXTURE_ID_TILEMAP_GRASS),sf::Vector2u(32,32), level,16,8);
	
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

		if (event.type == sf::Event::KeyPressed) 
		{
			if (event.key.code == sf::Keyboard::A)
				m_world.RequestTileChange(sf::Vector2i {0,5},0);
		}
	}
}

void App::Update()
{

}

void App::Render()
{	
	window->clear();
	//window->draw(shape);
	//window->draw(s);
	window->draw(m_world);
	window->draw(player);
	window->display();
}
