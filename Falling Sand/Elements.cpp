////Elements.cpp
#include "pch.h"


//////////////////////////////////////////////////////
//						CONSTRUCTORS



///////////
// Classes
Elements::Elements() {
	name = "AIR";
	m_ID = 0;
	velocity = 0;
	maxvelocity = 10;
	maxdispersal = 1;
	health = 100;
	fireresistance = 100;
	issolid = false;
	isliquid = false;
	isgas = false;

	corodable = false;

	wasupdated = false;


}
Liquids::Liquids() {
	isliquid = true;
}

Solids::Solids() {
	issolid = true;
}
MovableSolids::MovableSolids() {
}
ImmovableSolids::ImmovableSolids() {
}
Gas::Gas() {
	isgas = true;
}


//
//////////

///////////
//	Individual Materials

Sand::Sand() {
	name = "Sand";
	m_ID = 1;
	health = 70;
	weight = 4;
	corodable = true;
	m_color = sf::Color(217, 184, 17, 255);

}
Water::Water() {
	name = "Water";
	m_ID = 2;
	weight = 2;
	maxdispersal = 5;
	corodable = true;
	m_color = sf::Color(0, 92, 212, 255);

}
Stone::Stone() {
	name = "Stone";
	m_ID = 3;
	health = 150;
	corodable = true;
	m_color = sf::Color(122, 116, 116, 255);
}

Smoke::Smoke() {
	name = "Smoke";
	m_ID = 4;
	m_color = sf::Color(30, 30, 30, 150);
}

Acid::Acid() {
	name = "Acid";
	m_ID = 5;
	acidity = 3;
	m_color = sf::Color(15, 222, 11, 255);
}

FlammableGas::FlammableGas() {
	name = "Flamable Gas";
	m_ID = 6;
	health = 5;
	m_color = sf::Color(63, 115, 62, 100);
	fireresistance = 0;
}

Glass::Glass() {
	name = "Glass";
	m_ID = 7;
	health = 50;
	m_color = sf::Color(255, 255, 255, 150);
}

Wood::Wood() {
	name = "Wood";
	m_ID = 8;
	health = 80;
	corodable = true;
	fireresistance = 95;
	m_color = sf::Color(36, 22, 8, 255);
}

BlackHole::BlackHole() {
	name = "BlackHole";
	m_ID = 10;
	m_color = sf::Color(0, 0, 0, 255);
}

StaticFire::StaticFire() {
	name = "Fire";
	m_ID = 20;
	m_color = sf::Color(255, 0, 0, 255);

}

Steam::Steam() {
	name = "Steam";
	m_ID = 9;
	m_color = sf::Color(183, 198, 201, 255);
}
/*
MovableFire::MovableFire() {
	name = "Fire";
	m_ID = 21;
}
LiquidFire::LiquidFire() {
	name = "Fire";
	m_ID = 22;
}
*/


//Rob Particle, make it bounce through the screen untill it hits something,
//then change direction

//
////////////



//						CONSTRUCTORS
//////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////
//					CLASS FUNCTIONS

void Elements::updateelement(Matrix& matrix, int y, int x) {
	//updatethings
}

inline void Elements::move(Matrix& matrix, int y, int x, int yt, int xt) {
	matrix[yt][xt] = matrix[y][x];
	matrix[y][x] = AIR;
	matrix[yt][xt].wasupdated = true;

}


void Elements::reaction(Matrix& matrix, int y, int x, int yt, int xt) {

}

inline bool Elements::actOnOther(Matrix& matrix, int y, int x, int yt, int xt) {
	return false;
}

void Elements::corode(Matrix& matrix, int yt, int xt) {
	matrix[yt][xt].health -= 30;
	if (matrix[yt][xt].health < 0)
	{
		matrix[yt][xt] = FLAMMABLEGAS;
	}
}


inline bool Elements::completeboundscheck(int y, int x) {
	if (y - 1 > 0 && y + 1 < worldheight && x - 1 > 0 && x + 1 < worldwidth)
	{
		return true;
	}
	else return false;
}

inline void Elements::gravity(Matrix& matrix, int y, int x) {
	float tempvel;
	tempvel = matrix[y][x].velocity;

	if (matrix[y][x].isfreefaling == true && tempvel < maxvelocity)
	{
		tempvel += 0.3 + getRandom05() * 0.01;
	}

	int desired = tempvel + 1;
	int actual = 0;

	if (y + 1 < worldheight)
	{
		if (matrix[y + 1][x].m_ID == 0 || matrix[y + 1][x].isgas)
		{
			for (int i = 1; i <= desired; i++) {
				if (y + i < worldheight && matrix[y + i][x].m_ID == 0 || y + i < worldheight && matrix[y + i][x].isgas)
				{
					//increase actual for every free pixel underneath
					actual++;
				}

				else { break; }
			}
			if (actual == 0) { actual += 1; }

			if (matrix[y + actual][x].isgas) {
				swapelements(matrix, y, x, y + actual, x);
			}
			else {
				matrix[y + actual][x] = matrix[y][x];
				matrix[y][x] = AIR;
			}
			matrix[y + actual][x].wasupdated = true;
			matrix[y + actual][x].isfreefaling = true;
			matrix[y + actual][x].velocity = tempvel;

			//std::cout << "Velocity: " << matrix[y + actual][x].m_velocity << std::endl;


		}
		else {
			actOnOther(matrix, y, x, y + 1, x);
			matrix[y][x].isfreefaling = false;
		}
	}

}

inline void Elements::moveSideways(Matrix& matrix, int y, int x) {
	// Check leftward movement

	if (getRandom100() > 50) {
		if (x - 1 > 0 && matrix[y][x - 1].m_ID == 0) {
			matrix[y][x - 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y][x - 1].wasupdated = true;
		}
		// Check rightward movement
		if (x + 1 < worldwidth && matrix[y][x + 1].m_ID == 0) {
			matrix[y][x + 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y][x + 1].wasupdated = true;
		}
	}
	else
	{
		// Check rightward movement
		if (x + 1 < worldwidth && matrix[y][x + 1].m_ID == 0) {
			matrix[y][x + 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y][x + 1].wasupdated = true;
		}
		if (x - 1 > 0 && matrix[y][x - 1].m_ID == 0) {
			matrix[y][x - 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y][x - 1].wasupdated = true;
		}

	}

}

inline void Elements::moveDiagonallydown(Matrix& matrix, int y, int x) {
	if (getRandom100() > 50)
	{

		if (y + 1 < worldheight && x + 1 < worldwidth && matrix[y + 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0) //move down right
		{
			matrix[y + 1][x + 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y + 1][x + 1].wasupdated = true;

		}
		
		else if (y + 1 < worldheight && x > 0 && matrix[y + 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0) //move down left
		{
			matrix[y + 1][x - 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y + 1][x - 1].wasupdated = true;

		}
	}
	else
	{

		if (y + 1 < worldheight && x > 0 && matrix[y + 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0) //move down left
		{
			matrix[y + 1][x - 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y + 1][x - 1].wasupdated = true;

		}
		else if (y + 1 < worldheight && x + 1 < worldwidth && matrix[y + 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0) //move down right
		{
			matrix[y + 1][x + 1] = matrix[y][x];
			matrix[y][x] = AIR;
			matrix[y + 1][x + 1].wasupdated = true;

		}
	}
}
inline void Elements::moveDiagonallyup(Matrix& matrix, int y, int x) {
	if (y - 1 > 0 && x + 1 < worldwidth && matrix[y - 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0) //move up right
	{
		matrix[y - 1][x + 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x + 1].wasupdated = true;

	}
	else if (y - 1 > 0 && x - 1 > 0 && matrix[y - 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0) //move up left
	{
		matrix[y - 1][x - 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x - 1].wasupdated = true;

	}
}
inline void Elements::swapelements(Matrix& matrix, int y, int x, int y2, int x2) {

	temp = matrix[y][x];
	matrix[y][x] = matrix[y2][x2];
	matrix[y2][x2] = temp;
	temp = AIR;

	matrix[y][x].wasupdated = true;
	matrix[y2][x2].wasupdated = true;

}

inline void Elements::inverse_gravity(Matrix& matrix, int y, int x) {
	if (y - 1 > 0 && matrix[y - 1][x].m_ID == 0)
	{
		matrix[y - 1][x] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x].wasupdated = true;
	}
}


////////////////////////
//		 Solids
void MovableSolids::updateelement(Matrix& matrix, int y, int x) {

	if (y + 1 < worldheight && matrix[y + 1][x].isliquid)
	{
		swapelements(matrix, y, x, y + 1, x);
	}
	gravity(matrix, y, x);
	moveDiagonallydown(matrix, y, x);
}
//	
////////////////////////


////////////////////////
//		LIQUIDS
void Liquids::updateelement(Matrix& matrix, int y, int x) {

	gravity(matrix, y, x);
	moveDiagonallydown(matrix, y, x);
	moveSideways(matrix, y, x);


}
//		LIQUIDS
////////////////////////


////////////////////////
//		Gas

void Gas::updateelement(Matrix& matrix, int y, int x) {
	inverse_gravity(matrix, y, x);
	moveDiagonallyup(matrix, y, x);
	moveSideways(matrix, y, x);
}
//		Gas
////////////////////////

//					CLASS FUNCTIONS
/////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
//					Individual FUNCTIONS

void Sand::updateelement(Matrix& matrix, int y, int x) {
	MovableSolids::updateelement(matrix, y, x);

}


void Water::updateelement(Matrix& matrix, int y, int x) {
	Liquids::updateelement(matrix, y, x);


}

inline bool Acid::actOnOther(Matrix& matrix, int y, int x, int yt, int xt) {

	if (matrix[yt][xt].corodable) {
		corode(matrix, yt, xt);
		matrix[y][x].acidity--;
		return true;
	}
	else {
		return false;
	}
}

void Acid::updateelement(Matrix& matrix, int y, int x) {


	if (matrix[y][x].acidity <= 0) {
		matrix[y][x] = AIR;
		matrix[y][x].wasupdated = true;
	}


	if (y - 1 > 0)
	{
		actOnOther(matrix, y, x, y - 1, x);
	}
	if (y + 1 < worldheight)
	{
		actOnOther(matrix, y, x, y + 1, x);
	}
	if (x + 1 < worldwidth)
	{
		actOnOther(matrix, y, x, y, x + 1);
	}
	if (x - 1 > 0)
	{
		actOnOther(matrix, y, x, y, x - 1);
	}

	Liquids::updateelement(matrix, y, x);
}

void StaticFire::updateelement(Matrix& matrix, int y, int x) {

	matrix[y][x].m_color = sf::Color(255, getRandom(0, 100), 0, getRandom(50, 255));


	matrix[y][x].health -= getRandom(1,5) *0.2;

	if (matrix[y][x].health < 0)
	{
		matrix[y][x] = AIR;
		matrix[y][x].wasupdated = true;
	}
	if (getRandom(0, 100) < 30)
	{

		if (y - 1 > 0)
		{
			actOnOther(matrix, y, x, y - 1, x);
		}
		if (y + 1 < worldheight)
		{
			actOnOther(matrix, y, x, y + 1, x);
		}
		if (x + 1 < worldwidth )
		{
			actOnOther(matrix, y, x, y, x + 1);
		}
		if (x - 1 > 0)
		{
			actOnOther(matrix, y, x, y, x - 1);
		}
	}

	ImmovableSolids::updateelement(matrix, y, x);


}
inline bool StaticFire::actOnOther(Matrix& matrix, int y, int x, int yt, int xt) {
	//checks if flamable
	if (matrix[yt][xt].fireresistance != 100) {
		//random chance to turn into fire particle
		if (getRandom(0, 100) > matrix[yt][xt].fireresistance)
		{
			matrix[yt][xt].burnID = matrix[yt][xt].m_ID;
			float temphealth = matrix[yt][xt].health;
			matrix[yt][xt] = STATICFIRE;
			matrix[yt][xt].health = temphealth;
			matrix[yt][xt].wasupdated = true;


		}
		return true;
	}
	//turns water into smoke
	if (matrix[yt][xt].m_ID == 2) {
		matrix[y][x] = STEAM;
		matrix[yt][xt] = STEAM;

		matrix[y][x].wasupdated = true;
		matrix[yt][xt].wasupdated = true;

	}


	return false;


}

void Steam::updateelement(Matrix& matrix, int y, int x) {
	
	matrix[y][x].health -= 1;

	if (matrix[y][x].health < 0){

		if (getRandom(0, 1000) == 1)
		{
			matrix[y][x] = WATER;
		}
		else {
			matrix[y][x].health = 50;
		}

	}

	Gas::updateelement(matrix, y, x);
}


void BlackHole::updateelement(Matrix& matrix, int y, int x) {
	ImmovableSolids::updateelement(matrix, y, x);
	if (completeboundscheck(y, x) == true)
	{
		if (matrix[y - 1][x].m_ID != 10)
		{
			matrix[y - 1][x] = AIR;
		}

		if (matrix[y + 1][x].m_ID != 10)
		{
			matrix[y + 1][x] = AIR;
		}

		if (matrix[y][x + 1].m_ID != 10)
		{
			matrix[y][x + 1] = AIR;
		}

		if (matrix[y][x - 1].m_ID != 10)
		{
			matrix[y][x - 1] = AIR;
		}
	}
}
//
///////////////////////////////////////////////////////////

