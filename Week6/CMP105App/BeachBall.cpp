#include "BeachBall.h"


BeachBall::BeachBall()
{
	hasJumped =true;
	velocity = 0;
	acceleration = 2;
}

void BeachBall::update(float dt, int windowSize)
{
	if (getPosition().y < windowSize - getSize().y)
	{
		velocity = velocity + acceleration * dt;
	}
	else if (getPosition().y >= windowSize - getSize().y)
	{
		velocity = 0;
		hasJumped = false;
		setPosition(getPosition().x, windowSize - getSize().y);
	}

	if (input->isKeyDown(sf::Keyboard::Space) && !hasJumped)
	{
		velocity = -0.7;
		hasJumped = true;
	}

	if (input->isMouseLDown())
	{
		velocity = 0;
		setPosition(input->getMouseX() - getSize().x / 2, input->getMouseY() - getSize().y / 2);
	}

	move(0, velocity);
}




