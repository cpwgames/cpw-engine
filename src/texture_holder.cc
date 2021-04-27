/*
 * texture_holder.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "texture_holder.h"


TextureHolder::TextureHolder()
{
	
}

void TextureHolder::load(Textures::ID id, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
		throw std::runtime_error("TextureHolder::load -Failed to load "+ filename);
	
	auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
	//assert(inserted.second);
}

sf::Texture& TextureHolder::get(Textures::ID id)
{
	auto found = mTextureMap.find(id);
	//assert(found != mTextureMap.end());

	return *found->second;
}

const sf::Texture& TextureHolder::get(Textures::ID id) const
{
	auto found = mTextureMap.find(id);
	//assert(found != mTextureMap.end());

	return *found->second;
}