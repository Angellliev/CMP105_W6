#pragma once
#include "Framework/GameObject.h"
class BeachBall: public GameObject
{
	float acceleration;
	float velocity;
	bool hasJumped;
	
	
public:
	BeachBall();
	void update(float dt, int windowSize);
	void jump();
};

