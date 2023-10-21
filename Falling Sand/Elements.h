////Elements.h.
#pragma once
#include "pch.h"


//struct Pixels {
//	int ID;
//	
//	sf::Color color;
//	bool wasupdated;
//
//	Pixels() : ID(0), color(sf::Color::White), wasupdated(false) {}
//};



class Elements
{
protected:
	
public:
	std::string m_name;
	int m_ID;
	float m_velocity;
	float m_maxvelocity;
	float m_weight;
	float health;
	float hardness;
	float fireresistance;


	bool m_wasupdated;
	bool m_isfreefaling;


	sf::Color color;
	Elements();

	void gravity(Matrix& matrix, int i, int j);
	void moveSideways(Matrix& matrix, int i, int j);
	void moveDiagonallydown(Matrix& matrix, int i, int j);


	void updateelement(Matrix& matrix, int i, int j);
};



///////////////
//  Solids
class Solids : public Elements {
public:

	Solids();

};

class MovableSolids : public Solids {
public:

	MovableSolids();

	void updateelement(Matrix& matrix, int i, int j);

};

class ImmovableSolids : public Solids {
public:
	ImmovableSolids();
};
//  Solids
///////////////
 

///////////////
//	Liquids

class Liquids : public Elements {
public:
	Liquids();
	void updateelement(Matrix& matrix, int i, int j);
};
//
////////////////


///////////////////////////////////////////////////////////
//					Individual Elements

class Sand : public MovableSolids {
public:
	Sand();
};

class Water : public Liquids {
public:
	Water();
};

class Stone : public ImmovableSolids {
public:
	Stone();

};

//
///////////////////////////////////////////////////////////
