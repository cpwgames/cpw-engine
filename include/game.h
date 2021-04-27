/*
 * game.h
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#ifndef GAME_H
#define GAME_H


#include <string>

#include <SFML/Graphics.hpp>

#include "World.h"


class Game
{
	public:
		Game();
		void run();

	private:
		void processEvents();
		void update(sf::Time deltaTime);
		void render();
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	private:
		sf::RenderWindow mWindow;
		sf::Texture mTexture;
		sf::Sprite mPlayer;
		bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
		float PlayerSpeed;
		sf::Time TimePerFrame;
		World mWorld;
		sf::Color mColorText;
		sf::Text mStatisticsText;
		sf::Font mFontText;
};

#endif /* GAME_H */ 
