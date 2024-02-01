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


// Base class for all elements
class Elements
{
public:
	std::string name;
	int m_ID;

	double velocity;
	double velocity_x;
	double velocity_y;
	double inertialresistance;


	float maxvelocity;
	int maxdispersal;
	float weight;
	float density;
	float health;
	float lifetime;
	float fireresistance;
	int m_spawnID;
	int temperature;
	int baseheat;
	int maxheat;
	int burnID;
	int acidity;



	std::vector<sf::Color> colorPalette;

	bool wasupdated;
	bool isfreefaling;
	bool hasmoved;

	bool corodable;

	bool issolid;
	bool isliquid;
	bool isgas;
	bool ismovable;

	sf::Color m_color;



	Elements();

	void updateelement(Matrix& matrix, int y, int x);

	const inline void getColor(std::vector<sf::Color>& colorPalette, Matrix& matrix, int y, int x);

	inline bool completeboundscheck(int y, int x);
	inline bool istouchedby(Matrix& matrix, int y, int x, int id);
	inline bool issurroundedby(Matrix& matrix, int y, int x,int id);
	virtual inline bool gravity(Matrix& matrix, int y, int x);
	inline bool inverse_gravity(Matrix& matrix, int y, int x);

	inline bool moveSideways2(Matrix& matrix, int y, int x);
	inline bool moveSideways(Matrix& matrix, int y, int x);
	inline bool moveDiagonallydown(Matrix& matrix, int y, int x);
	inline bool moveDiagonallyup(Matrix& matrix, int y, int x);

	void corode(Matrix& matrix,int yt, int xt);

	inline void swapelements(Matrix& matrix, int y, int x, int i2, int j2);
	virtual inline bool try_actOnOther(Matrix& matrix, int y, int x);
	virtual inline bool actOnOther(Matrix& matrix, int y, int x, int yt, int xt);
	inline bool try_applyHeat(Matrix& matrix, int y, int x);
	inline bool applyHeat(Matrix& matrix, int y, int x, int yt, int xt);
	inline void ignite(Matrix& matrix, int y, int x, int yt, int xt);


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
	inline bool moveSideways(Matrix& matrix, int y, int x);

};

class ImmovableSolids : public Solids {
public:
	ImmovableSolids();
	void updateelement(Matrix& matrix, int y, int x);

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


};

class GasFire : public Gas {
public:

	GasFire();
	void updateelement(Matrix& matrix, int y, int x);

};

class LiquidFire : public Liquids {
public:
	LiquidFire();
	void updateelement(Matrix& matrix, int y, int x);

};

class Lava : public Liquids {
public:
	Lava();
	void updateelement(Matrix& matrix, int y, int x);
};

class Steam : public Gas {
public:
	Steam();
	void updateelement(Matrix& matrix, int y, int x);
};

class Oil : public Liquids {
public:
	Oil();

};

class Cement : public Liquids {
public:
	Cement();
	void updateelement(Matrix& matrix, int y, int x);

};



class Ice : public ImmovableSolids {
public:
	Ice();
	void updateelement(Matrix& matrix, int y, int x);
	inline bool actOnOther(Matrix& matrix, int y, int x, int yt, int xt);

};
//gunpowder
//salt


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
// Create selectedmat
//
// spawners
// Create spawner if necesarry.
