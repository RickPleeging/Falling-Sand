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
	std::string name;
	int m_ID;

	float velocity;
	float maxvelocity;
	int maxdispersal;
	float weight;
	float density;
	float health;
	float lifetime;
	float hardness;
	float fireresistance;
	int m_spawnID;
	int burnID;
	int acidity;


	bool wasupdated;
	bool isfreefaling;
	bool hasnotmoved;

	bool corodable;
	bool issolid;
	bool isliquid;
	bool isgas;

	sf::Color m_color;



	Elements();

	inline bool completeboundscheck(int y, int x);

	virtual inline void gravity(Matrix& matrix, int y, int x);
	inline void inverse_gravity(Matrix& matrix, int y, int x);

	inline void moveSideways(Matrix& matrix, int y, int x);
	inline void moveDiagonallydown(Matrix& matrix, int y, int x);
	inline void moveDiagonallyup(Matrix& matrix, int y, int x);

	void corode(Matrix& matrix,int yt, int xt);

	inline void move(Matrix& matrix, int y, int x, int yt, int xt);
	inline void swapelements(Matrix& matrix, int y, int x, int i2, int j2);
	void updateelement(Matrix& matrix, int y, int x);
	void reaction(Matrix& matrix, int y, int x, int yt, int xt);
	virtual inline bool actOnOther(Matrix& matrix, int y, int x, int yt, int xt);

	

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
	void updateelement(Matrix& matrix, int y, int x);
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
	void updateelement(Matrix& matrix, int y, int x);
};
//
////////////////


///////////////
//	Gas

class Gas : public Elements {
public:
	Gas();
	void updateelement(Matrix& matrix, int y, int x);
};
//
////////////////


///////////////////////////////////////////////////////////
//					Individual Elements

class Sand : public MovableSolids {
public:
	Sand();
	void updateelement(Matrix& matrix, int y, int x);
};

class Water : public Liquids {
public:
	Water();
	void updateelement(Matrix& matrix, int y, int x);
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

class FlammableGas : public Gas {
public:
	FlammableGas();
};

class Acid : public Liquids
{
public:
	Acid();

	inline bool actOnOther(Matrix& matrix, int y, int x, int yt, int xt);
	void updateelement(Matrix& matrix, int y, int x);

};

class Glass : public ImmovableSolids {
public:
	Glass();

};

class Wood : public ImmovableSolids {
public:
	Wood();
};

class BlackHole : public ImmovableSolids {
public:
	BlackHole();
	void updateelement(Matrix& matrix, int y, int x);
};


class StaticFire : public ImmovableSolids {
public:

	StaticFire();
	void updateelement(Matrix& matrix, int y, int x);
	inline bool actOnOther(Matrix& matrix, int y, int x, int yt, int xt);


};

class Steam : public Gas {
public:
	Steam();
	void updateelement(Matrix& matrix, int y, int x);


};
/*
class MovableFire : public ImmovableSolids {
public:
	MovableFire();

};
class LiquidFire : public ImmovableSolids {
public:
	LiquidFire();

};
*/
//
///////////////////////////////////////////////////////////


//Create Element Checklist:
//
// Elements.cpp / Elemenets.h 
// Create Class Definition and Decleration
// 
// globals.h / globals.cpp
// Create Class Instance
// 
// updatematrix.cpp
// Add Element update
//
// handleinput.cpp
// Create keyboard shortcut
//
// spawners
// Create spawner if necesarry.
