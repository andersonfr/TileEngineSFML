#ifndef _SCENE_NODE__H
#define _SCENE_NODE__H

#include <memory.h>
#include <vector>
#include <SFML/Graphics.hpp>

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
	//parent
	typedef std::unique_ptr<SceneNode> Ptr;

	void AttachChild(Ptr child);
	Ptr DetachChild(const Ptr& node);
	virtual void OnStart() = 0;
	virtual void OnDestroyed() = 0;
	virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void UpdateCurrent(float dt) = 0;
private:
	std::vector<Ptr> m_children;
	SceneNode* m_parent;
	
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	virtual void Update(float dt) final;
};
#endif//_SCENE_NODE__H

