/*
 * entity.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef ENTITY_H
#define ENTITY_H


#include <SFML/Graphics.hpp>

#include "scene_node.h"


class Entity : public SceneNode
{
	public:
		Entity();
		virtual ~Entity();
		
	public:
		void setVelocity(sf::Vector2f velocity);
		void setVelocity(float vx, float vy);
		sf::Vector2f getVelocity() const;
		
	private:
		virtual void updateCurrent(sf::Time dt);
		
	private:
		sf::Vector2f mVelocity;
};

#endif /* ENTITY_H */ 
