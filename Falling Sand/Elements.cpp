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

	m_wasupdated = false;
}
Liquids::Liquids() {
}

Solids::Solids() {
}
MovableSolids::MovableSolids() {
}
ImmovableSolids::ImmovableSolids() {
}

//
//////////

///////////
//	Individual Materials

Sand::Sand() {
	m_name = "Sand";
	m_ID = 1;
	m_weight = 4;
}
Water::Water() {
	m_name = "Water";
	m_ID = 2;
	m_weight = 2;
}
Stone::Stone() {
	m_name = "Stone";
	m_ID = 3;
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

void Elements::gravity(Matrix& matrix, int i, int j) {
	//float tempvel;
	//tempvel = matrix[i][j].m_velocity;

	if ( i + 1 < worldheight && matrix[i][j].m_wasupdated == false && matrix[i + 1][j].m_ID == 0)
	{
		matrix[i + 1][j]= matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i + 1][j].m_wasupdated = true;
	}
}

void Elements::moveSideways(Matrix& matrix, int i, int j) {
	// Check leftward movement
	if (j - 1 > 0 && matrix[i][j].m_wasupdated == false && matrix[i][j - 1].m_ID == 0) {
		matrix[i][j - 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i][j - 1].m_wasupdated = true;

		//debug
		//std::cout << "Matrix[" << i << "][" << j << "] to: Matrix[" << i << "][" << j-1 << "]" <<std::endl;
		//std::cout << "Matrix[" << i << "][" << j-1 << "] was updated: " << matrix[i][j-1].m_wasupdated << std::endl;
		//
	}
	// Check rightward movement
	if ( j +1 < worldwidth && matrix[i][j].m_wasupdated == false && matrix[i][j + 1].m_ID == 0) {
		matrix[i][j + 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i][j + 1].m_wasupdated = true;
	}
}

void Elements::moveDiagonallydown(Matrix& matrix, int i, int j) {
	if ( i + 1 < worldheight && j + 1 < worldwidth && matrix[i][j].m_wasupdated == false && matrix[i + 1][j + 1].m_ID == 0 && matrix[i][j + 1].m_ID == 0) //move down right
	{
		matrix[i + 1][j + 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i + 1][j + 1].m_wasupdated = true;
		
	}
	else if (i + 1 < worldheight && j > 0 && matrix[i][j].m_wasupdated == false && matrix[i + 1][j - 1].m_ID == 0 && matrix[i][j - 1].m_ID == 0) //move down left
	{
		matrix[i + 1][j - 1] = matrix[i][j];
		matrix[i][j] = AIR;
		matrix[i + 1][j - 1].m_wasupdated = true;
	
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

//					CLASS FUNCTIONS
//////////////////////////////////////////////////////





///////////////////////////////////////////////////////////
//					Individual FUNCTIONS




//
///////////////////////////////////////////////////////////




