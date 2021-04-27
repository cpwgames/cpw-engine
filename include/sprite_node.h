/*
 * sprite_node.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef SPRITE_NODE_H
#define SPRITE_NODE_H


#include <SFML/Graphics.hpp>

#include "SceneNode.h"
#include "TextureHolder.h"


class SpriteNode : public SceneNode
{
	public:
		explicit SpriteNode(const sf::Texture& texture);
		SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

	private:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		sf::Sprite mSprite;
};

#endif /* SPRITE_NODE_H */ 
