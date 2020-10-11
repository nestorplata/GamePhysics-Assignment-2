#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "Sprite.h"
#include "Label.h"
#include <math.h>

class Player final : public Sprite
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	void move();
	void stopmoving();

	//float setangle(float gravity, float max_distance, float velocity);
	float settodegrees(float radians);
	float settoradians(float degrees);
	float getangle();
	float getangle_R();
	float getgravity();
	float getMax_distance();
	float getvelocity();
	bool getstart();

	bool isColliding(GameObject*);
	float getDistance(GameObject*);

private:
	const float GRAVITY = 9.8f;
	const float SPEED = 95.0f;
	const float I_DISTANCE = 485.0f;
	const float ANGLE = 15.8896328197f;
	const float ANGLE_R = 15.8f * M_PI / 180;

	glm::vec2 m_direction;
	bool start = true;
};

#endif /* defined (__PLAYER__) */