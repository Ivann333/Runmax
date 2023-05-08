#pragma once
#include "Libs.h"
#include"AssetManager.h"
#include "WorldCreater.h"

class Engine
{
public:
	Engine();
	void run();

private:


	AssetManager manager;

	
	sf::Vector2f m_resolution = sf::Vector2f(static_cast<float>(sf::VideoMode::getDesktopMode().width),
		static_cast<float>(sf::VideoMode::getDesktopMode().height));

	sf::View mainView = sf::View(sf::FloatRect(0, 0, m_resolution.x, m_resolution.y));

	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_resolution.x, m_resolution.y), L"Runnmaxx", sf::Style::Default);
	
	sf::VertexArray world;
	sf::IntRect worldsize;

	

	void draw();
	void input();
	
};

