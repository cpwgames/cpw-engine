/*
 * aircraft.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "aircraft.h"


Aircraft::Aircraft(Aircraft::Type type, TextureHolder& textures):
	mType(type),
	mSprite(textures.get(toTextureID(type)))
{
	
}

Aircraft::Aircraft(Aircraft::Type type, sf::Texture& texture):
	mType(type),
	mSprite(texture)
{
	
}

Aircraft::~Aircraft()
{
	
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

Textures::ID Aircraft::toTextureID(Aircraft::Type type)
{
	switch (type)
	{
		case Aircraft::Eagle:
			return Textures::Eagle;
		case Aircraft::Raptor:
			return Textures::Raptor;
	}
}
