#include "Goomba.h"

void Goomba::update(float dt, int mousePositionX, int mousePositionY)
{
	acceleration = 200.f;
	target = sf::Vector2f(mousePositionX - getSize().x *.5, mousePositionY - getSize().y *.5);
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * acceleration) * dt;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
		velocity = sf::Vector2f(0, 0);
		acceleration = 0;
	}
}
