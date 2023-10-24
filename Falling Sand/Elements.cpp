////Elements.cpp
#include "pch.h"


//////////////////////////////////////////////////////
//						CONSTRUCTORS



///////////
// Classes
Elements::Elements() {
	m_name = "AIR";
	m_ID = 0;
	m_velocity = 0;
	m_maxvelocity = 10;
	m_maxdispersal = 1;

	m_wasupdated = false;

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


	m_name = "Sand";
	m_ID = 1;
	m_weight = 4;
	m_color = sf::Color(217, 184, 17, 255);

}
Water::Water() {
	m_name = "Water";
	m_ID = 2;
	m_weight = 2;
	m_color = sf::Color(0, 92, 212, 255);

}
Stone::Stone() {
	m_name = "Stone";
	m_ID = 3;
	m_color = sf::Color(122, 116, 116, 255);
}

Smoke::Smoke() {
	m_name = "Smoke";
	m_ID = 4;
	m_color = sf::Color(30, 30, 30, 150);

}

//
////////////



//						CONSTRUCTORS
//////////////////////////////////////////////////////





//////////////////////////////////////////////////////
//					CLASS FUNCTIONS

void Elements::updateelement(Matrix& matrix, int y, int x) {
	//updatethings
}

void Elements::reacton(Matrix& matrix, int y, int x, int yt, int xt) {
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
	tempvel = matrix[y][x].m_velocity;

	if (matrix[y][x].m_isfreefaling == true && tempvel < m_maxvelocity)
	{
		tempvel += 1;
	}
	int desired = 1+ tempvel;
	int actual=0;


	if (y + 1 < worldheight && matrix[y + 1][x].m_ID == 0)
	{

		for (int i = 0; i <= desired; i++) {
			if (y + i < worldheight && matrix[y + i][x].m_ID == 0)
			{
				//increase int if freed
				actual++;
			}
		}
		if (matrix[y + actual][x].m_ID == 0) {

		matrix[y + actual][x] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y + actual][x].m_wasupdated = true;
		matrix[y + actual][x].m_isfreefaling = true;
		matrix[y + actual][x].m_velocity = tempvel;
		//std::cout << "Velocity: " << matrix[y + actual][x].m_velocity << std::endl;
		}

	}
	else {
		matrix[y][x].m_isfreefaling = false;
		matrix[y][x].m_velocity = 0;
		//std::cout << "no longer freefalling"<<std::endl;
	}
}

void Elements::moveSideways(Matrix& matrix, int y, int x) {
	// Check leftward movement
	if (x - 1 > 0 && matrix[y][x - 1].m_ID == 0) {
		matrix[y][x - 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y][x - 1].m_wasupdated = true;
	}
	// Check rightward movement
	if (x + 1 < worldwidth && matrix[y][x + 1].m_ID == 0) {
		matrix[y][x + 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y][x + 1].m_wasupdated = true;
	}
}

void Elements::moveDiagonallydown(Matrix& matrix, int y, int x) {
	if (y + 1 < worldheight && x + 1 < worldwidth && matrix[y + 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0) //move down right
	{
		matrix[y + 1][x + 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y + 1][x + 1].m_wasupdated = true;

	}
	else if (y + 1 < worldheight && x > 0 && matrix[y + 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0) //move down left
	{
		matrix[y + 1][x - 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y + 1][x - 1].m_wasupdated = true;

	}
}
void Elements::moveDiagonallyup(Matrix& matrix, int y, int x) {
	if (y - 1 > 0 && x + 1 < worldwidth && matrix[y - 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0) //move up right
	{
		matrix[y - 1][x + 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x + 1].m_wasupdated = true;

	}
	else if (y - 1 > 0 && x - 1 > 0 && matrix[y - 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0) //move up left
	{
		matrix[y - 1][x - 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x - 1].m_wasupdated = true;

	}
}
void Elements::swapelements(Matrix& matrix, int y, int x, int y2, int x2) {

	temp = matrix[y][x];
	matrix[y][x] = matrix[y2][x2];
	matrix[y2][x2] = temp;
	temp = AIR;

	matrix[y][x].m_wasupdated = true;
	matrix[y2][x2].m_wasupdated = true;

}

inline void Elements::inverse_gravity(Matrix& matrix, int y, int x) {
	if (y - 1 > 0 && matrix[y - 1][x].m_ID == 0)
	{
		matrix[y - 1][x] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x].m_wasupdated = true;
	}
}


////////////////////////
//		 Solids
void MovableSolids::updateelement(Matrix& matrix, int y, int x) {
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
//////////////////////////////////////////////////////





///////////////////////////////////////////////////////////
//					Individual FUNCTIONS

void Sand::updateelement(Matrix& matrix, int y, int x) {


	if (completeboundscheck(y, x) == true && matrix[y + 1][x].isliquid == true || completeboundscheck(y, x) == true && matrix[y + 1][x].isgas == true)
	{
		swapelements(matrix, y, x, y + 1, x);
		//std::cout << "Sand touched Water!";
	}
	MovableSolids::updateelement(matrix, y, x);

}


//
///////////////////////////////////////////////////////////




