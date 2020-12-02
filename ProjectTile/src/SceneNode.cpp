#include "SceneNode.h"
#include <assert.h>

void SceneNode::AttachChild(Ptr child)
{
	child->m_parent = this;
	child->OnStart();
	m_children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::DetachChild(const Ptr& node)
{
	auto find = std::find_if(m_children.begin(), m_children.end(), [&](Ptr& p) { return p == node; });
	assert(find != m_children.end());
	
	Ptr p = std::move(*find);
	p->m_parent = nullptr;
	m_children.erase(find);
	p->OnDestroyed();
	return p;
}

void SceneNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	DrawCurrent(target, states);

	for(const Ptr& c : m_children)
	{
		c->draw(target, states);
	}
}

void SceneNode::Update(float dt)
{
	UpdateCurrent(dt);

	for(const Ptr& c : m_children)
	{
		c->Update(dt);
	}
}
