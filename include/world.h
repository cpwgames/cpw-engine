/*
 * world.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef WORLD_H
#define WORLD_H


#include <SFML/Graphics.hpp>

#include "ResourceHolder.h"
#include "SceneNode.h"
#include "Aircraft.h"
#include "SpriteNode.h"


class World : private sf::NonCopyable
{
	public:
		explicit World(sf::RenderWindow& window);
		void update(sf::Time dt);
		void draw();
		Aircraft* get_mPlayerAircraft() const;


	private:
		void loadTextures();
		void buildScene();

	private:
		enum Layer
		{
			Background,
			Air,
			LayerCount
		};

	private:
		sf::RenderWindow& mWindow;
		sf::View mWorldView;
		sf::FloatRect mWorldBounds;
		sf::Vector2f mSpawnPosition;
		Aircraft* mPlayerAircraft;
		TextureHolder mTextures;
		SceneNode mSceneGraph;
		std::array<SceneNode*, LayerCount> mSceneLayers;
		float mScrollSpeed;
};

#endif /* WORLD_H */ 
