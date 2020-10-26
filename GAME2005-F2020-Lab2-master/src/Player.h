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
	void movehorizontaly();
	void stopmoving();

	//float setangle(float gravity, float max_distance, float velocity);
	//float settodegrees(float radians);
	//float settoradians(float degrees);

	//100 pixels = 1 meter
	float settometers(float pixels);
	float settopixels(float meters);
	float getangle();
	float getangle_R();
	float getgravity();
	float getMax_distance();
	float getvelocity();
	bool getstart();

	bool gotbottom();
	void setbottom();

	bool isColliding(GameObject*);
	float getDistance(GameObject*);

private:
	const float WEIGHT = 12.8f;
	const float GRAVITY = 9.8f;
	const float SPEED = 0.0f;
	const float I_DISTANCE = 485.0f;
	const float COE_FRICTION = 0.42f;
	const float ANGLE = 36.86989765f;
	const float ANGLE_R = ANGLE * M_PI / 180.0f;

	//ACC = acceleration
	const float NET_ACCELERATION = GRAVITY*sin(ANGLE_R);
	const float HORIZONTAL_ACC = NET_ACCELERATION* cos(ANGLE_R);
	const float VERTICAL_ACC = NET_ACCELERATION* sin(ANGLE_R);

	const float FRICTION_DESACC = COE_FRICTION*GRAVITY;
	

	glm::vec2 m_direction;
	bool start = true;
	bool bottom = false;
};

#endif /* defined (__PLAYER__) */