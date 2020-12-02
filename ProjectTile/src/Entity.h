#ifndef _ENTITY__H
#define _ENTITY__H

#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	
	virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	void UpdateCurrent(float dt) override;

	// Inherited via SceneNode
	virtual void OnStart() override;
	virtual void OnDestroyed() override;
};

#endif //_ENTITY__H