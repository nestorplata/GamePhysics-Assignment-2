#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"
#include <math.h>
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	drawDisplayList();
}

void PlayScene::update()
{
	updateDisplayList();

	std::string labelText = "";
	std::string labelText2 = "";



	if (m_pPlayer->isColliding(m_pEnemy)) {
		labelText = "HIT";
	}
	else {
		labelText = "Distance = " + std::to_string(m_pPlayer->getDistance(m_pEnemy));
	}

	labelText2 = "Velocity = " + std::to_string(Util::magnitude(m_pPlayer->getRigidBody()->velocity));


	m_pDistanceLabel->setText(labelText);
	m_pVelocityLabel->setText(labelText2);


}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
	{
		m_pPlayer->moveLeft();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
	{
		m_pPlayer->moveRight();
	}
	else
	{
		m_pPlayer->stopMoving_x();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_W)) {
		m_pPlayer->moveUp();
	}
	else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_S)) {
		m_pPlayer->moveDown();
	}
	else
	{
		m_pPlayer->stopMoving_y();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}
}

void PlayScene::start()
{
	// Player Sprite
	m_pPlayer = new Player();
	addChild(m_pPlayer);
	
	// Enemy Sprite
	m_pEnemy = new Enemy();
	addChild(m_pEnemy);

	// Distance Label
	const SDL_Color blue = { 0, 0, 255, 255 };
	m_pDistanceLabel = new Label("Distance", "Consolas", 40, blue, glm::vec2(400.0f, 40.0f));
	m_pDistanceLabel->setParent(this);
	addChild(m_pDistanceLabel);

	// Velocity Label
	const SDL_Color red = { 255, 0, 0, 255 };
	m_pVelocityLabel = new Label("Velocity", "Consolas", 40, red, glm::vec2(400.0f, 80.0f));
	m_pVelocityLabel->setParent(this);
	addChild(m_pVelocityLabel);
}
