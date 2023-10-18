#pragma once
#include "pch.h"

//this is elements.

struct Pixels {
	int ID;
	sf::Color color;
	bool wasupdated;

	Pixels() : ID(0), color(sf::Color::White), wasupdated(false) {}
};


class Elements
{
protected:
	
public:
	
	Elements();
	void updatematerial(std::vector<std::vector<Pixels>>& matrix, int i, int j);
};

// Solids
class Solids : public Elements {
public:

	Solids();

};

class MovableSolids : public Solids {
public:

	MovableSolids();

};

class ImmovableSolids : public Solids {
public:

	ImmovableSolids();
};
/////////
//Liquids

class Liquids : public Elements {
public:
	Liquids();
};

//Move this later
class Sand : public MovableSolids {
public:
	Sand();
};

