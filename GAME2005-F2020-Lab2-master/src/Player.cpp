#include "Player.h"
#include "TextureManager.h"
#include "Util.h"

Player::Player()
{
	TextureManager::Instance()->load("../Assets/textures/Detonator.png", "Detonator");
	
	auto size = TextureManager::Instance()->getTextureSize("Detonator");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(165.0f,450.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(PLAYER);
}

Player::~Player()
= default;

void Player::draw()
{
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	TextureManager::Instance()->draw("Detonator", x, y, 0, 255, true);
}

void Player::update()
{
	const float deltaTime = 1.0f / 60.f;

	// Normalize direction sector
	//float dirMagnitude = Util::magnitude(m_direction);

	//if (dirMagnitude > 0) {

	//	getRigidBody()->acceleration = Util::normalize(m_direction) * ACCELERATION;
	//}
	//else if (Util::magnitude(getRigidBody()->velocity) > 0)
	//{

	//	getRigidBody()->acceleration = Util::normalize(getRigidBody()->velocity) * -ACCELERATION;
	//}

	if (start != true && bottom ==false) {
		getRigidBody()->velocity.y += VERTICAL_ACC * deltaTime;
		getRigidBody()->velocity.x += HORIZONTAL_ACC*deltaTime;
	}
	else if (bottom ==true) {
		getRigidBody()->velocity.x -= FRICTION_DESACC * deltaTime;
	}
	else {
		getRigidBody()->velocity.y = 0;
		getRigidBody()->velocity.x = 0;
	}

	glm::vec2 pos = getTransform()->position;
	pos.x += getRigidBody()->velocity.x * deltaTime;
	pos.y += getRigidBody()->velocity.y * deltaTime;

	getTransform()->position = pos;

}

void Player::clean()
{

}

void Player::move() {
	if (start == true)
	{
		getRigidBody()->velocity = glm::vec2(SPEED * cos(ANGLE_R), SPEED * sin(ANGLE_R));
		start = false;
	}
	else {
		getRigidBody()->velocity = glm::vec2(getRigidBody()->velocity.x, getRigidBody()->velocity.y);
	}

}

void Player::movehorizontaly()
{
	getRigidBody()->velocity = glm::vec2(0, 0.0f);
}


void Player::stopmoving() {
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
}
//
//void Player::moveLeft() {
//	getRigidBody()->velocity = glm::vec2(-SPEED, 0.0f);
//}
//
//void Player::moveRight() {
//	getRigidBody()->velocity = glm::vec2(SPEED, 0.0f);
//}
//
//void Player::moveUp() {
//	getRigidBody()->velocity = glm::vec2(0.0f, -SPEED);
//}
//
//void Player::moveDown() {
//	getRigidBody()->velocity = glm::vec2(0.0f, SPEED);
//}
//
//void Player::stopMoving() {
//	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
//}

//float Player::setangle(float gravity, float max_distance, float velocity)
//{
//	float left = gravity * max_distance / (velocity * velocity);
//	ANGLE = (1 / (2 * sin(left)));
//	return ANGLE;
//}
//float Player::settodegrees(float radians)
//{
//	return radians * 180.0f / M_PI;
//}
//
//float Player::settoradians(float degrees)
//{
//	return degrees * M_PI / 180.0f;
//}

float Player::settometers(float pixels)
{
	return pixels *1/100;
}

float Player::settopixels(float meters)
{
	return meters*100;
}

float Player::getangle()
{
	return ANGLE;
}
float Player::getangle_R()
{
	return ANGLE_R;
}

float Player::getgravity()
{
	return GRAVITY;
}

float Player::getMax_distance()
{
	return I_DISTANCE;
}

float Player::getvelocity()
{
	return SPEED;
}

bool Player::getstart()
{
	return start;
}

bool Player::isColliding(GameObject* pOther) {
	// Works for square sprites only
	float myRadius = getWidth() * 0.5f;
	float otherRadius = pOther->getWidth() * 0.5f;

	return (getDistance(pOther) <= myRadius + otherRadius);
}

bool Player::gotbottom() {
	return bottom;

}

void Player::setbottom() {
	bottom = true;
}




float Player::getDistance(GameObject* pOther) {
	glm::vec2 myPos = getTransform()->position;
	glm::vec2 otherPos = pOther->getTransform()->position;

	// Use pythagorean to calculate distance c = sqrt(a^2 + b^2)
	float a = myPos.x - otherPos.x;
	float b = myPos.y - otherPos.y;
	return sqrt(a * a + b * b);
}
