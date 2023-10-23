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
	m_color = sf::Color(122, 116, 116,255);
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

void Elements::updateelement(Matrix& matrix, int i, int j) {
	//updatethings
}
inline bool Elements::completeboundscheck(int i, int j) {
	if (i-1 > 0 && i + 1 < worldheight && j-1 > 0 && j+1 < worldwidth)
	{
		return true;
	}
	else return false;
}

inline void Elements::gravity(Matrix& matrix, int i, int j) {
	//float tempvel;
	//tempvel = matrix[i][j].m_velocity;

	if ( i + 1 < worldheight && matrix[i + 1][j].m_ID == 0)
	{
		matrix[i + 1][j]= matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i + 1][j].m_wasupdated = true;
	}
}

void Elements::moveSideways(Matrix& matrix, int i, int j) {
	// Check leftward movement
	if (j - 1 > 0 && matrix[i][j - 1].m_ID == 0) {
		matrix[i][j - 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i][j - 1].m_wasupdated = true;
	}
	// Check rightward movement
	if ( j +1 < worldwidth && matrix[i][j + 1].m_ID == 0) {
		matrix[i][j + 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i][j + 1].m_wasupdated = true;
	}
}

void Elements::moveDiagonallydown(Matrix& matrix, int i, int j) {
	if ( i + 1 < worldheight && j + 1 < worldwidth && matrix[i + 1][j + 1].m_ID == 0 && matrix[i][j + 1].m_ID == 0) //move down right
	{
		matrix[i + 1][j + 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i + 1][j + 1].m_wasupdated = true;
		
	}
	else if (i + 1 < worldheight && j > 0 && matrix[i + 1][j - 1].m_ID == 0 && matrix[i][j - 1].m_ID == 0) //move down left
	{
		matrix[i + 1][j - 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i + 1][j - 1].m_wasupdated = true;
	
	}
}
void Elements::moveDiagonallyup(Matrix& matrix, int i, int j) {
	if (i - 1 > 0 && j + 1 < worldwidth && matrix[i - 1][j + 1].m_ID == 0 && matrix[i][j + 1].m_ID == 0) //move up right
	{
		matrix[i - 1][j + 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i - 1][j + 1].m_wasupdated = true;

	}
	else if (i - 1 > 0 && j -1 > 0 && matrix[i - 1][j - 1].m_ID == 0 && matrix[i][j - 1].m_ID == 0) //move up left
	{
		matrix[i - 1][j - 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i - 1][j - 1].m_wasupdated = true;

	}
}
void Elements::swapelements(Matrix& matrix, int i, int j, int i2, int j2) {
	
	temp = matrix[i][j];
	matrix[i][j] = matrix[i2][j2];
	matrix[i2][j2] = temp;
	temp = AIR;

	matrix[i][j].m_wasupdated = true;
	matrix[i2][j2].m_wasupdated = true;

}

inline void Elements::inverse_gravity(Matrix& matrix, int i, int j){
	if (i - 1 > 0 && matrix[i - 1][j].m_ID == 0)
	{
		matrix[i - 1][j] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i - 1][j].m_wasupdated = true;
	}
}


////////////////////////
//		 Solids
void MovableSolids::updateelement(Matrix& matrix, int i, int j) {
	gravity(matrix, i, j);
	moveDiagonallydown(matrix, i, j);

}
//	
////////////////////////


////////////////////////
//		LIQUIDS
void Liquids::updateelement(Matrix& matrix, int i, int j) {
	gravity(matrix, i, j);
	moveDiagonallydown(matrix, i, j);
	moveSideways(matrix, i, j);
}
//		LIQUIDS
////////////////////////


////////////////////////
//		Gas

void Gas::updateelement(Matrix& matrix, int i, int j) {
	inverse_gravity(matrix, i, j);
	moveDiagonallyup(matrix, i, j);
	moveSideways(matrix,i,j);
}
//		Gas
////////////////////////



//					CLASS FUNCTIONS
//////////////////////////////////////////////////////





///////////////////////////////////////////////////////////
//					Individual FUNCTIONS

void Sand::updateelement(Matrix& matrix, int i, int j){

	
	if (completeboundscheck(i, j) == true && matrix[i + 1][j].isliquid == true || completeboundscheck(i, j) == true && matrix[i+1][j].isgas == true)
	{
		swapelements(matrix,i,j, i+1,j);
		//std::cout << "Sand touched Water!";
	}
	MovableSolids::updateelement(matrix, i, j);

}


//
///////////////////////////////////////////////////////////




