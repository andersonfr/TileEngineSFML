#ifndef _TILE__H
#define _TILE__H

#include <SFML/Graphics.hpp>

class Tile : public sf::Transformable
{
private:
	unsigned int id;
public:
	Tile(int frameX_, int frameY_, unsigned int id_) : frameX(frameX_), frameY(frameY), id(id_){};
	~Tile() = default;

	int frameX;
	int frameY;
	unsigned int GetID() const { return id; }
	bool bEnable = true;
};
#endif //_TILE__H

