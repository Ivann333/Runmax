#pragma once
#include "Libs.h"
#include"AssetManager.h"
#include "WorldCreater.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Engine
{
public:
	Engine();
	void run();

private:


	AssetManager manager;

	sf::Vector2i winPosition;
	
	sf::Vector2f m_resolution = sf::Vector2f(static_cast<float>(sf::VideoMode::getDesktopMode().width + 9),
		static_cast<float>(sf::VideoMode::getDesktopMode().height));

	sf::View mainView = sf::View(sf::FloatRect(0, 0, m_resolution.x, m_resolution.y));

	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_resolution.x, m_resolution.y), L"Runnmaxx", sf::Style::Default);
	
	sf::VertexArray world;
	sf::IntRect worldsize;

	std::deque<Enemy> monster;

	std::deque<Bullet> bullet;

	Player player;
	int bulletnum = 0;

	int numMonster;

	void update(sf::Time const& deltaTime);

	void draw();
	void input();

	int** arr;
	int currentBullet = 0;
	
};

