/*
 * texture_holder.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H


#include <SFML/Graphics.hpp>


namespace Textures
{
	enum ID
	{
		Landscape,
		Airplane,
		Missile,
		Eagle,
		Raptor,
		Desert
	};
}

class TextureHolder
{
	public:
		TextureHolder();
		void load(Textures::ID id, const std::string& filename);
		sf::Texture& get(Textures::ID id);
		const sf::Texture& get(Textures::ID id) const;

	private:
		std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};

#endif /* TEXTURE_HOLDER_H */ 