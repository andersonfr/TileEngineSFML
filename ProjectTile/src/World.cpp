#include "World.h"
#include "Utils/Utils.h"
//#include "App.h"
#include <vector>


#define WINDOW_WIDTH (1366)
#define WINDOW_HEIGHT (768)

void World::LoadWorld(const std::string & filename, const sf::Texture& tileMapTexture)
{
	LoadTileMapInfo(filename, m_tilesInfo, m_width, m_height);
	SetTiles();
	m_tileMap.Load(tileMapTexture, sf::Vector2u(32, 32), m_tiles, m_width, m_height);
	//m_tileMap.setScale(2, 2);
	m_tileMap.setOrigin(m_width/2 * 32, 0);
	m_tileMap.setPosition((float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2);
}

void World::BreakTile(int frameX, int frameY)
{

}

void World::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_tileMap.draw(target,states);
}

void World::UpdateCurrent(float dt)
{

}

void World::RequestTileChange(sf::Vector2i tPosition, int mode)
{
	m_tileMap.ChangeTileAt(tPosition.x, tPosition.y);
}

void World::SetTiles()
{		
	m_tiles.resize(m_width * m_height, Tile(0, 0, 0));

	for (int i = 0; i < m_width; ++i)
	{
		for (int j = 0; j < m_height; ++j)
		{
			//std::cout << m_tilesInfo[i + j * m_width] << " ";
			m_tiles[i + j * m_width] = Tile{i, j, (unsigned int)m_tilesInfo[i + j* m_width]} ;
		}
		//std::cout << "\n";
	}
}
