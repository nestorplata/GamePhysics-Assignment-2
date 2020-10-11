#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"
#include <math.h>
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();

	TextureManager::Instance()->load("../Assets/textures/blackspace.png", "background4");
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	TextureManager::Instance()->draw("background4", 255, 255, 0, 255, true);
	drawDisplayList();
}

void PlayScene::update()
{
	updateDisplayList();

	std::string labelText = "";
	std::string labelText2 = "";
	std::string labelText3 = "";
	std::string labelText4 = "";


	if (m_pPlayer->isColliding(m_pObjective) || m_pPlayer->isColliding(m_pShip)) {
		labelText = "HIT";

	}
	else {
		labelText = "Distance = " + std::to_string(m_pPlayer->getDistance(m_pShip));
	}

	labelText2 = "Velocity = " + std::to_string(Util::magnitude(m_pPlayer->getRigidBody()->velocity));

	labelText3 = "Elevation Angle = " + std::to_string(m_pPlayer->getangle());
	labelText4 = "Press L to launch";

	m_pDistanceLabel->setText(labelText);
	m_pVelocityLabel->setText(labelText2);
	m_pI_AngleLabel->setText(labelText3);
	m_pinstructions->setText(labelText4);


}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_L) || m_pPlayer->getstart() == false)
	{
		m_pPlayer->move();
	}



	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (m_pPlayer->isColliding(m_pObjective)|| m_pPlayer->isColliding(m_pShip)) {
		m_pPlayer->stopmoving();
	}
}

void PlayScene::start()
{
	// DETONATOR Sprite
	m_pPlayer = new Player();
	addChild(m_pPlayer);
	
	// WOOKIE Sprite
	m_pEnemy = new Enemy();
	addChild(m_pEnemy);

	// STORMTROPPER Sprite
	m_pShip = new Ship();
	addChild(m_pShip);

	//Objective Sprite
	m_pObjective = new Points();
	addChild(m_pObjective);

	//m_pObjective2 = new Points();
	//addChild(m_pObjective2);
	//m_pObjective2->getTransform()->position = glm::vec2(650.0f, 500.0f);

	////START Sprite
	//m_pStart = new Points();
	//addChild(m_pStart);
	//m_pStart->getTransform()->position = glm::vec2(165.0f, 450.0f);


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

	const SDL_Color green = { 0, 255, 0, 255 };
	m_pI_AngleLabel = new Label("Angle", "Consolas", 40, green, glm::vec2(400.0f, 120.0f));
	m_pI_AngleLabel->setParent(this);
	addChild(m_pI_AngleLabel);

	const SDL_Color orange = { 255, 117, 020, 255 };
	m_pinstructions = new Label("Angle", "Consolas", 40, orange, glm::vec2(400.0f, 160.0f));
	m_pinstructions->setParent(this);
	addChild(m_pinstructions);
}
