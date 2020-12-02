#ifndef _RESOURCE_HOLDER__H
#define _RESOURCE_HOLDER__H

#include <unordered_map>
#include <memory.h>
#include <string.h>
#include <assert.h>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



enum class TextureID
{
	TEXTURE_ID_TILEMAP_GRASS = 1,
	TEXTURE_ID_TILEMAP_PIXELATLAS = 2,
	TEXTURE_ID_PLAYER_CHARACTER = 3,
	TEXTURE_ID_PLAYER_HEAD = 4,
	TEXTURE_COUNT,
};

enum class FontID
{

};

enum class SoundID 
{

};

enum class ShaderID{};

class ResourceHolder
{
private :
	std::unordered_map <TextureID, std::unique_ptr<sf::Texture>> m_TextureMap;
	std::unordered_map <SoundID, std::unique_ptr<sf::Sound>> m_SoundMap;
	std::unordered_map <ShaderID, std::unique_ptr<sf::Shader>> m_ShaderMap;

public:
	ResourceHolder() = default;
	~ResourceHolder() = default;
	//templates
	template<typename ResourceTypeID>
	void Load(ResourceTypeID id, const std::string& filename);
	template<typename ResourceTypeID,typename Parameter>
	void Load(ResourceTypeID id, const std::string& filename, const Parameter& secondParameter);
	template<typename Resource, typename ResourceTypeID>
	const Resource& Get(ResourceTypeID id);

	//templates specializations
	template<>
	const sf::Texture& Get<sf::Texture>(TextureID id);
	template<>
	void Load<int>(int id, const std::string& filename);
	template<>
	void Load<TextureID>(TextureID id, const std::string& filename);
	template<>
	void Load<ShaderID,sf::Shader::Type>(ShaderID id, const std::string& filename, const sf::Shader::Type& shaderType);
	template<>
	void Load<ShaderID, std::string>(ShaderID id, const std::string& vertexFilename, const std::string& fragFilename);

};

template<typename ResourceTypeID>
inline void ResourceHolder::Load(ResourceTypeID id, const std::string & filename)
{
	std::cout << "Loading Generic" << std::endl;
}

template<typename Resource, typename ResourceTypeID>
inline const Resource & ResourceHolder::Get(ResourceTypeID id)
{
	// You Should not reach here.
	std::cout << "Getting Generic" << std::endl;
	return NULL;
}

template<>
inline const sf::Texture & ResourceHolder::Get(TextureID id)
{
	std::cout << "Getting Texture " << std::endl;
	auto texture = m_TextureMap.find(id);
	assert(texture != m_TextureMap.end());

	return *m_TextureMap[id];
}

template<>
void ResourceHolder::Load(int id, const std::string& filename)
{
	std::cout << "Loading integer" << std::endl;
}

template<>
inline void ResourceHolder::Load(TextureID id, const std::string & filename)
{
	std::cout << "Loading Texture" << std::endl;
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::Load - Failed To Load Texture " + filename);

	auto it = m_TextureMap.insert(std::make_pair(id, std::move(texture)));
	assert(it.second);
}

template<>
inline void ResourceHolder::Load(ShaderID id, const std::string & filename, const sf::Shader::Type & shaderType)
{
}

template<>
inline void ResourceHolder::Load(ShaderID id, const std::string & vertexFilename, const std::string & fragFilename)
{
}

template<>
inline void ResourceHolder::Load(ShaderID id, const std::string & filename)
{
}

#endif //_RESOURCE_HOLDER__H

