#ifndef _WORLD_H__
#define _WORLD_H__
#endif // !_WORLD_H__

#include "Tile.h"
#include <vector>
#include <string.h>
#include "Entity.h"
#include "TileMap.h"
#include "ResourceHolder.h"

class World : public Entity
{
private:
	void SetTiles();
	int m_width;
	int m_height;
	TextureID m_tileMapTextureID;
	TileMap m_tileMap;
public:
	std::vector<Tile> m_tiles;
	std::vector<int> m_tilesInfo;
	void LoadWorld(const std::string& filename, const sf::Texture& tileMapTexture);
	void BreakTile(int frameX, int frameY);
	
	void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	void UpdateCurrent(float dt) override;

	void RequestTileChange(sf::Vector2i tPosition, int mode);
};

