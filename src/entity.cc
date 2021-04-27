/*
 * entity.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "entity.h"


Entity::Entity()
{
	
}

Entity::~Entity()
{
	
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}
void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}
sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}
void Entity::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}
