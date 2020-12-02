#pragma once
#include "../Entity.h"
#include <array>

class CharacterModule : public Entity
{
public:
	sf::Sprite m_sprite;
	virtual ~CharacterModule() = default;
	virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
};

class CharacterHeadModule : public CharacterModule 
{
public:
	CharacterHeadModule() = default;
	~CharacterHeadModule() {};
	// Inherited via CharacterModule
	virtual void OnStart() override;
	virtual void DrawCurrent(sf::RenderTarget & target, sf::RenderStates states) const override;
};


enum class ECharacterModule 
{
	HEAD,
	CHEST,
	LEGS,
	FEET,
	COUNT
};

class PlayerBodyEntity : public Entity
{
public:
	virtual void OnStart() override;
	virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override {}
};


class PlayerCharacter : public Entity
{

public:
	PlayerCharacter() = default;
	~PlayerCharacter() = default;

	sf::Vector2f m_pos;

	void Init();
	virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
	std::array<CharacterModule*, 5> m_characterModules;
};

