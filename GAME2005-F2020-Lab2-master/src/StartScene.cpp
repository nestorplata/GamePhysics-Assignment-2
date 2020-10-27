#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"


StartScene::StartScene()
{
	StartScene::start();
	TextureManager::Instance()->load("../Assets/textures/garage.jpg", "background");
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	TextureManager::Instance()->draw("background", 255, 255, 0, 255, true);
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	const SDL_Color orange = { 255, 117, 020, 255 };
	const SDL_Color red = { 255, 0, 0, 255 };
	const SDL_Color blue = { 0, 0, 255, 255 };
	const SDL_Color black = { 0, 0, 0, 255 };

	m_pStartLabel = new Label("Ramp Fall Simulator", "Consolas", 50, black, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	//m_pInstructionsLabel = new Label("Simulator", "Consolas", 60, blue, glm::vec2(400.0f, 100.0f));
	//m_pInstructionsLabel->setParent(this);
	//addChild(m_pInstructionsLabel);

	m_pNestorLabel = new Label("Nestor Plata 101282246", "Consolas", 40, orange, glm::vec2(400.0f, 150.0f));
	m_pNestorLabel->setParent(this);
	addChild(m_pNestorLabel);

	m_pKianLabel = new Label("Kian Badieikhorsand", "Consolas", 40, red, glm::vec2(400.0f, 200.0f));
	m_pKianLabel->setParent(this);
	addChild(m_pKianLabel);

	m_pKianLabel2 = new Label("101282433", "Consolas", 40, red, glm::vec2(400.0f, 250.0f));
	m_pKianLabel2->setParent(this);
	addChild(m_pKianLabel2);


	//m_pShip = new Ship();
	//m_pShip->getTransform()->position = glm::vec2(400.0f, 400.0f); 
	//addChild(m_pShip); 

	m_pPlayer = new Player();
	m_pPlayer->getTransform()->position = glm::vec2(400.0f, 370.0f);
	addChild(m_pPlayer);


	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(400.0f, 500.0f); 

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	
}

