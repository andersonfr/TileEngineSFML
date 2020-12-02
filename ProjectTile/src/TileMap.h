#ifndef _TILE_MAP__
#define  _TILE_MAP__


#include <SFML/Graphics.hpp>
#include "Tile.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool Load(const sf::Texture& texture, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
	bool Load(const sf::Texture& texture, sf::Vector2u tileSize, const std::vector<std::vector<int>> tiles, unsigned int width, unsigned int height);
	bool Load(const sf::Texture& texture, sf::Vector2u tileSize, const std::vector<Tile> tiles, unsigned int width, unsigned int height);
	void ChangeTileAt(int x, int y);
	//sfml function
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	int m_width;
	int m_height;
	sf::Texture m_tileSet;
	sf::VertexArray m_vertices;
};

#endif//_TILE_MAP__

