/*
 * game.cc
 * 
 * Copyright 2021 CPW Online <support@cpwonline.org>
 * 
 * This program is free software; see the License file for more details.
 * 
 * You should have received a copy of the License along with this program.
 * 
 */


#include "game.h"


Game::Game() :
	mWindow(sf::VideoMode(1080, 720), "SFML Application"),
	mTexture(),
	mFontText(),
	mColorText(),
	//mPlayer(),
	mWorld(mWindow)
{
	/*if(!mTexture.loadFromFile("cb.bmp"))
	{
		// Manejo de error
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f, 100.f);*/
	PlayerSpeed = 300.f;
	TimePerFrame = sf::seconds(1.f / 60.f);
	mFontText.loadFromFile("share/FreeMono.otf");
	mStatisticsText.setString("hola");
	mStatisticsText.setPosition(10.f, 10.f);
	mStatisticsText.setFont(mFontText);
	mStatisticsText.setColor(mColorText.White);
	mStatisticsText.setCharacterSize(12);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while(timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
			mWorld.update(TimePerFrame);
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
			break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
			break;
			case sf::Event::Closed:
				mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if(mIsMovingUp)
		movement.y -= PlayerSpeed;
	if(mIsMovingDown)
		movement.y += PlayerSpeed;
	if(mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if(mIsMovingRight)
		movement.x += PlayerSpeed;
	mWorld.get_mPlayerAircraft()->move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWorld.draw();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}