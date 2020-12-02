#include "TileMap.h"

bool TileMap::Load(const sf::Texture& texture, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
	m_tileSet = texture;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileNumber = tiles[i + j * width];

			int tu = tileNumber % (m_tileSet.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileSet.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			//define position
			quad[0].position = sf::Vector2f(i * tileSize.x, j*tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j*tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1)*tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1)*tileSize.y);

			//define the text coord on tilemap
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv*tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv*tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1)*tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1)*tileSize.y);
		}
	}
	return true;
}

bool TileMap::Load(const sf::Texture & texture, sf::Vector2u tileSize, const std::vector<std::vector<int>> tiles, unsigned int width, unsigned int height)
{
	m_tileSet = texture;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			int tileNumber = tiles[j][i];

			int tu = tileNumber % (m_tileSet.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileSet.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			//define position
			quad[0].position = sf::Vector2f(i * tileSize.x, j*tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j*tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1)*tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1)*tileSize.y);

			//define the text coord on tilemap
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv*tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv*tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1)*tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1)*tileSize.y);
		}
	}
	return true;	
}

bool TileMap::Load(const sf::Texture& texture, sf::Vector2u tileSize, const std::vector<Tile> tiles, unsigned int width, unsigned int height)
{
	m_tileSet = texture;
	m_width = width;
	m_height = height;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	for (unsigned int i = 0; i < width; ++i)
	{
		for (unsigned int j = 0; j < height; ++j)
		{
			if (!tiles[i + j * width].bEnable)
				continue;

			int tileNumber = tiles[i + j*width].GetID();

			int tu = tileNumber % (m_tileSet.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileSet.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			//define position
			quad[0].position = sf::Vector2f(i * tileSize.x, j*tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j*tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1)*tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1)*tileSize.y);

			//define the text coord on tilemap
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv*tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv*tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1)*tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1)*tileSize.y);
		}
	}
	return true;
}

void TileMap::ChangeTileAt(int x, int y)
{
	sf::Vertex* quad = &m_vertices[(x + y *m_width) * 4];
	quad[0].color = sf::Color(0, 0, 0, 0);
	quad[1].color = sf::Color(0, 0, 0, 0);
	quad[2].color = sf::Color(0, 0, 0, 0);
	quad[3].color = sf::Color(0, 0, 0, 0);
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileSet;
	target.draw(m_vertices, states);
}
