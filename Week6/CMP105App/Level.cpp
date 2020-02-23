#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	mousePressedX = 0;
	mousePressedY = 0;
	window = hwnd;
	input = in;
	mouseIsPressed = false;
	
	// initialise game objects
	beachBall.setInput(input);
	beachBallTexture.loadFromFile("gfx/Beach_Ball.png");
	beachBall.setSize(sf::Vector2f(80, 80));
	beachBall.setPosition(40, 40);
	beachBall.setTexture(&beachBallTexture);

	mushroomTexture.loadFromFile("gfx/MushroomTrans.png");
	mushroom.setSize(sf::Vector2f(45, 45));
	mushroom.setTexture(&mushroomTexture);

	goombaTexture.loadFromFile("gfx/Goomba.png");
	goomba.setSize(sf::Vector2f(50, 50));
	goomba.setTexture(&goombaTexture);

	slingshotTexture.loadFromFile("gfx/MushroomMask.png");
	slingshot.setSize(sf::Vector2f(100, 100));
	slingshot.setPosition(window->getSize().x * .5, window->getSize().y * .5);
	slingshot.setTexture(&slingshotTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isMouseLDown())
	{
		if (mouseIsPressed == false)
		{
			mousePressedX = input->getMouseX();
			mousePressedY = input->getMouseY();
		}
		mouseIsPressed = true;

	}

	if (!input->isMouseLDown() && mouseIsPressed)
	{
		mouseIsPressed = false;
		mouseDrag.x = input->getMouseX() - mousePressedX;
		mouseDrag.y = input->getMouseY() - mousePressedY;
	}
}

// Update game objects
void Level::update(float dt)
{
	beachBall.update(dt, window->getSize().y);
	mushroom.update(dt, window->getSize().x, window->getSize().y);
	goomba.update(dt, input->getMouseX(), input->getMouseY());
	slingshot.update(dt, mouseDrag);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(beachBall);
	window->draw(mushroom);
	window->draw(goomba);
	window->draw(slingshot);
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