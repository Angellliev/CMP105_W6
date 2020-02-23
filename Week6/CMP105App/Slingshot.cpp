#include "Slingshot.h"

Slingshot::Slingshot()
{
	speed = 5.f;
}

void Slingshot::update(float dt, sf::Vector2f mouseDrag)
{
	direction.x = mouseDrag.x * -1;
	direction.y = mouseDrag.y * -1;
	
	velocity += (direction * speed);
	setPosition(getPosition() + (direction * dt));
}


