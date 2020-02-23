#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	
	// initialise game objects
	beachBall.setInput(input);
	beachBallTexture.loadFromFile("gfx/Beach_Ball.png");
	beachBall.setSize(sf::Vector2f(80, 80));
	beachBall.setPosition(40, 40);
	beachBall.setTexture(&beachBallTexture);

	mushroomTexture.loadFromFile("gfx/MushroomTrans.png");
	mushroom.setSize(sf::Vector2f(45, 45));
	mushroom.setTexture(&mushroomTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	beachBall.update(dt, window->getSize().y);
	mushroom.update(dt, window->getSize().x, window->getSize().y);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(beachBall);
	window->draw(mushroom);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}