#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "BeachBall.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "Slingshot.h"

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	//Mouse controlls
	bool mouseIsPressed;
	int mousePressedX;
	int mousePressedY;
	sf::Vector2f mouseDrag;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// More level variables
	BeachBall beachBall;
	sf::Texture beachBallTexture;

	Mushroom mushroom;
	sf::Texture mushroomTexture;

	Goomba goomba;
	sf::Texture goombaTexture;

	Slingshot slingshot;
	sf::Texture slingshotTexture;
};