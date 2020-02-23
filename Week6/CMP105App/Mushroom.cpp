#include "Mushroom.h"




void Mushroom::update(float dt, int windowSizeX, int windowSizeY)
{
	acceleration = 50.f;;
	target = sf::Vector2f(windowSizeX - getSize().x, windowSizeY - getSize().y);
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * acceleration) * dt;
	setPosition(getPosition() + (velocity * dt)); 

	if(Vector::magnitude(target -getPosition()) < 5.f)
	{
		setPosition(target);
		velocity = sf::Vector2f(0,0);
		acceleration = 0;
	}
	
}
