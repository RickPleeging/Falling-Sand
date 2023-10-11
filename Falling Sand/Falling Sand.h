#pragma once
#include "pch.h"




/////////////////////
//		Declerations

void updatematrix(std::vector<std::vector<int>>& matrix, int worldheight, int worldwidth, sf::RenderWindow& window);

void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window);

void handleinput(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window, sf::Event& event);

//
/////////////////////

