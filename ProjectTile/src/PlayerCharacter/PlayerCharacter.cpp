#include "PlayerCharacter.h"
#include "../App.h"
#include "../ResourceManager.h"

void PlayerCharacter::Init()
{
	setPosition(200, 200);
	AttachChild(std::move(std::make_unique<PlayerBodyEntity>()));
}

void PlayerCharacter::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void CharacterHeadModule::OnStart()
{
	Singletons::ResourceManager::GetInstance().holder.
		Load<TextureID>(TextureID::TEXTURE_ID_PLAYER_HEAD,"assets/textures/NormalHead.png");
	
	m_sprite.setTexture(Singletons::ResourceManager::GetInstance().holder.Get<sf::Texture>(TextureID::TEXTURE_ID_PLAYER_HEAD));
}

void CharacterHeadModule::DrawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

void PlayerBodyEntity::OnStart()
{
	AttachChild(std::move(std::make_unique<CharacterHeadModule>()));
}
