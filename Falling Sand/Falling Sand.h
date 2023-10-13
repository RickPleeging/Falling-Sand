#pragma once
#include "pch.h"




/////////////////////
//		Declerations
bool startup();

void updatematrix(std::vector<std::vector<int>>& matrix, int worldheight, int worldwidth, sf::RenderWindow& window);

void initializeParticles(std::vector<std::vector<int>>& matrix);

void addParticle(float x, float y, const sf::Color& color);

void draw(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window);

void handleinput(std::vector<std::vector<int>>& matrix, sf::RenderWindow& window, sf::Event& event);


//
/////////////////////

