#include "App.h"
#include <fstream>
#include <iostream>
#include <utility>
#include <stdexcept>
#include <sstream>
#include <string>
#include <Windows.h>



int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	App app;
	ResourceHolder holder;
	
	/*holder.Load<int>(2, "filename");
	holder.Load(0.2, "filename");*/
	
	try
	{
		
		//holder.Load<TextureID>(TextureID::TEXTURE_ID_TILEMAP_GRASS, "assets/textures/player.png");
		//sf::Texture t = holder.Get<sf::Texture>(TextureID::TEXTURE_ID_TILEMAP_GRASS);
		app.StartApp();
	}
	catch (char* e)
	{
		MessageBoxA(NULL, e, "Exception Occured", MB_OK | MB_ICONERROR);
	}

	return 0;
}