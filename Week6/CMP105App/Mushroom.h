#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Mushroom: public GameObject
{
	
	sf::Vector2f velocity;
	sf::Vector2f target;
	float acceleration;
	sf::Vector2f direction;

public:
	void update(float dt, int windowSizeX, int windowSizeY);
};

