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
	int m_maxdispersal;
	float m_weight;
	float health;
	float lifetime;
	float hardness;
	float fireresistance;
	int m_spawnID;



	bool m_wasupdated;
	bool m_isfreefaling;

	bool issolid;
	bool isliquid;
	bool isgas;

	sf::Color m_color;


	Elements();

	inline bool completeboundscheck(int i, int j);

	inline void gravity(Matrix& matrix, int i, int j);
	inline void inverse_gravity(Matrix& matrix, int i, int j);

	void moveSideways(Matrix& matrix, int i, int j);
	void moveDiagonallydown(Matrix& matrix, int i, int j);
	void moveDiagonallyup(Matrix& matrix, int i, int j);

	void swapelements(Matrix& matrix, int i, int j, int i2, int j2);
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


///////////////
//	Gas

class Gas : public Elements {
public:
	Gas();
	void updateelement(Matrix& matrix, int i, int j);
};
//
////////////////


///////////////////////////////////////////////////////////
//					Individual Elements

class Sand : public MovableSolids {
public:
	Sand();
	void updateelement(Matrix& matrix, int i, int j);
};

class Water : public Liquids {
public:
	Water();
};

class Stone : public ImmovableSolids {
public:
	Stone();
};

class Smoke : public Gas
{
public:
	Smoke();

};

//
///////////////////////////////////////////////////////////
