#include "Points.h"
#include "TextureManager.h"

Points::Points() {
	TextureManager::Instance()->load("../Assets/textures/bullet.png", "Point");

	auto size = TextureManager::Instance()->getTextureSize("Point");
	setWidth(size.x);
	setHeight(size.y);

	getTransform()->position = glm::vec2(0.0f, 0.0f);
	getRigidBody()->velocity = glm::vec2(0.0f, 0.0f);
	getRigidBody()->acceleration = glm::vec2(0.0f, 0.0f);
	getRigidBody()->isColliding = false;
	setType(ENEMY);
}

Points::~Points()
= default;

void Points::draw() {
	// alias for x and y
	const auto x = getTransform()->position.x;
	const auto y = getTransform()->position.y;

	TextureManager::Instance()->draw("Point", x, y, 0, 255, true);
}

void Points::update() {

}

void Points::clean() {

}