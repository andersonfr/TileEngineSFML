#ifndef _APP__H
#define _APP__H

#include <SFML/Graphics.hpp>
#include <memory.h>
#include "./PlayerCharacter/PlayerCharacter.h"
#include "ResourceHolder.h"
#include "World.h"

class App 
{
private:
	//sfml window
	std::unique_ptr<sf::RenderWindow> window;
	sf::CircleShape shape;
	sf::Sprite s;
	PlayerCharacter player;
	World m_world;
	ResourceHolder m_holder;

	int Init();
	void Render();
	void HandleEvents();
	void Update();
	void GameLoop();
public:
	static App * instance;
	App();
	~App();
	ResourceHolder & GetHolder() { return m_holder;}
	void StartApp();	
};
#endif //_APP__H
