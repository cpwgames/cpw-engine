/*
 * sprite_node.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "sprite_node.h"


SpriteNode::SpriteNode(const sf::Texture& texture) :
	mSprite(texture)
{
	
}

SpriteNode::SpriteNode(const sf::Texture& texture, const sf::IntRect& rect) :
	mSprite(texture, rect)
{
	
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
