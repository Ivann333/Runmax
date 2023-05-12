#pragma once
#include "Libs.h"


int** worldcreate();

void printArray(int** arr);
int worldDraw(int** arr, sf::RenderWindow& window);
sf::IntRect getWorldSize();


sf::Sprite& getSprite();


