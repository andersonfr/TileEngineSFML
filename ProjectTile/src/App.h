#ifndef _APP__H
#define _APP__H

#include <SFML/Graphics.hpp>
#include <memory.h>

class App 
{
private:
	//sfml window
	std::unique_ptr<sf::RenderWindow> window;
	sf::CircleShape shape;
	int Init();
	void Render();
	void HandleEvents();
	void Update();
	void GameLoop();

public:
	App();
	~App();

	void StartApp();
};

#endif //_APP__H
