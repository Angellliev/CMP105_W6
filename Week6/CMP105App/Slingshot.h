#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Slingshot :public GameObject
{
	sf::Vector2f velocity;
	float speed;
	sf::Vector2f direction;
public:
	Slingshot();
	void update(float dt, sf::Vector2f mouseDrag);
	
};

