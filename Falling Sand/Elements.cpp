////Elements.cpp
#include "pch.h"


//////////////////////////////////////////////////////
//						CONSTRUCTORS




///////////
// Classes
Elements::Elements() {
	name = "AIR";
	m_ID = 0;
	m_spawnID = 0;
	velocity = 0;
	velocity_x = 0;
	velocity_y = 0;
	weight = 10;
	density = 1;
	maxvelocity = 10;
	maxdispersal = 1;
	health = 100;
	lifetime = -1;

	temperature = 0;
	fireresistance = -1;
	baseheat = 0;
	maxheat = 0;
	burnID = 0;
	inertialresistance = 1;
	acidity=0;


	issolid = false;
	isliquid = false;
	isgas = false;

	corodable = false;

	wasupdated = false;
	hasmoved = false;
	colorPalette = { sf::Color(55,55,55,255) };
	ismovable = true;

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
	ismovable = false;
}
Gas::Gas() {
	isgas = true;
}


//
//////////

///////////
//	Individual Materials

/*
ID:
	Air			  = 0
	Sand		  = 1
	Water		  = 2
	Stone		  = 3
	Smoke		  = 4
	Acid		  = 5
	FlammableGas  = 6
	Glass		  = 7
	Wood		  = 8
	Steam		  = 9
	Blackhole	  = 10
	Lava		  = 11


	cement		  = 13
	StaticFire	  = 20
	GasFire		  = 22
	Spawners	  = 100

*/
Sand::Sand() {
	name = "Sand";
	m_ID = 1;
	health = 70;
	weight = 10;
	corodable = true;
	m_color = sf::Color(217, 184, 17, 255);
	inertialresistance = 0.5;

	colorPalette = {
		sf::Color(247, 225, 190, 255),
		sf::Color(242, 210, 157),
		sf::Color(237, 194, 123, 255),
		sf::Color(219, 170, 96, 255),
	};
}
Water::Water() {
	name = "Water";
	m_ID = 2;
	weight = 5;
	maxdispersal = 10;
	density = 5;
	temperature = 20;
	m_color = sf::Color(0, 92, 212, 255);
	colorPalette = {
		sf::Color(136, 186, 182, 200),
	};
}
Stone::Stone() {
	name = "Stone";
	m_ID = 3;
	health = 150;
	corodable = true;
	m_color = sf::Color(122, 116, 116, 255);
	colorPalette = {
		sf::Color(122, 116, 116,255),
		sf::Color(65,64,64,255),
		sf::Color(87,86,85,255),
	};
}

Smoke::Smoke() {
	name = "Smoke";
	m_ID = 4;

	m_color = sf::Color(30, 30, 30, 150);
	colorPalette = { sf::Color(30, 30, 30, 150) };

}

Acid::Acid() {
	name = "Acid";
	m_ID = 5;
	acidity = 3;
	maxdispersal = 7;
	density = 6;
	m_color = sf::Color(15, 222, 11, 255);
	colorPalette = { sf::Color(15, 222, 11, 255) };

}

FlammableGas::FlammableGas() {
	name = "Flamable Gas";
	m_ID = 6;
	health = 5;

	m_color = sf::Color(63, 115, 62, 100);
	colorPalette = { sf::Color(63, 115, 62, 100) };

	fireresistance = 0;
}

Glass::Glass() {
	name = "Glass";
	m_ID = 7;
	health = 50;
	m_color = sf::Color(255, 255, 255, 150);

	colorPalette = {
		sf::Color(130, 232, 215,255),
		sf::Color(106, 197, 204,255),
		sf::Color(167, 227, 232,255)
	};

}

Wood::Wood() {
	name = "Wood";
	m_ID = 8;
	health = 80;
	corodable = true;
	fireresistance = 95;
	m_color = sf::Color(36, 22, 8, 255);
	colorPalette = {
	sf::Color(36, 22, 8, 255),
	};
}

Steam::Steam() {
	name = "Steam";
	m_ID = 9;
	m_color = sf::Color(183, 198, 201, 150);
	colorPalette = { sf::Color(183, 198, 201, 150) };

}

BlackHole::BlackHole() {
	name = "BlackHole";
	m_ID = 10;
	m_color = sf::Color(0, 0, 0, 255);
	colorPalette = { sf::Color(0, 0, 0, 255) };

}

Lava::Lava() {
	name = "Lava";
	m_ID = 11;
	density = 10;
	maxdispersal = 2;

	baseheat = 50;
	maxheat = 500;
	m_color = sf::Color(255, 90, 0, 255);
	colorPalette = { sf::Color(255, 90, 0, 255) };

}

Oil::Oil() {
	name = "Oil";
	m_ID = 12;
	health = 200;
	density = 4;
	maxdispersal = 5;
	m_color = sf::Color(100, 80, 40, 255);
	fireresistance = 50;
	colorPalette = { sf::Color(100, 80, 40, 255) };

}



Cement::Cement() {
	name = "Cement";
	m_ID = 13;
	lifetime = 100;
	density = 9;
	maxdispersal = 2;

	m_color = sf::Color(150, 147, 138, 255);
	colorPalette = { sf::Color(150, 147, 138, 200),
					sf::Color(145, 144, 140, 200), };
}

Ice::Ice() {
	name = "Ice";
	m_ID = 14;
	health = 30;
	colorPalette =
	{
		sf::Color(174, 208, 242,255),
		sf::Color(174, 208, 242,255),
		sf::Color(159, 183, 207, 255),
	};

}

StaticFire::StaticFire() {
	name = "Fire";
	m_ID = 20;

	baseheat = 0;
	maxheat = 100;
	m_color = sf::Color(255, 0, 0, 255);
	colorPalette = { sf::Color(255, 206, 0, 255),
					sf::Color(255, 154, 0, 255),
					sf::Color(255,  90, 0, 255),
					sf::Color(218,  75, 3, 255) };

}

LiquidFire::LiquidFire() {
	name = "Liquid Fire";
	m_ID = 21;

	baseheat = 0;
	maxheat = 100;
	m_color = sf::Color(255, 0, 0, 255);
	colorPalette = { sf::Color(255, 206, 0, 255),
					sf::Color(255, 154, 0, 255),
					sf::Color(255,  90, 0, 255),
					sf::Color(218,  75, 3, 255) };

}
GasFire::GasFire() {
	name = "Gas Fire";
	health = 20;
	m_ID = 22;

	baseheat = 0;
	maxheat = 100;

	m_color = sf::Color(255, 0, 0, 255);
	colorPalette = { sf::Color(228, 84, 1, 155),
					sf::Color(228, 84, 1, 155),
					sf::Color(244, 145, 20, 155),
					sf::Color(246, 189, 57, 155) };

}

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


inline bool Elements::actOnOther(Matrix& matrix, int y, int x, int yt, int xt) {
	return false;
}

inline bool Elements::try_actOnOther(Matrix& matrix, int y, int x) {

	if (y - 1 > 0)
	{
		if (actOnOther(matrix, y, x, y - 1, x) == true) {
			matrix[y - 1][x].wasupdated = true;
			return true;
		};
	}
	if (y + 1 < worldheight)
	{
		if (actOnOther(matrix, y, x, y + 1, x) == true) {
			matrix[y + 1][x].wasupdated = true;
			return true;
		}
	}
	if (x + 1 < worldwidth)
	{
		if (actOnOther(matrix, y, x, y, x + 1) == true) {
			matrix[y][x + 1].wasupdated = true;
			return true;
		}
	}
	if (x - 1 > 0)
	{
		if (actOnOther(matrix, y, x, y, x - 1) == true) {
			matrix[y][x - 1].wasupdated = true;
			return true;
		}
	}
	return false;

}

inline bool Elements::try_applyHeat(Matrix& matrix, int y, int x) {
	bool success = false;


	if (y - 1 > 0)
	{
		if (applyHeat(matrix, y, x, y - 1, x) == true) {
			success = true;
		};
	}

	if (y + 1 < worldheight)
	{
		if (applyHeat(matrix, y, x, y + 1, x) == true) {
			return true;
		}
	}
	if (x + 1 < worldwidth)
	{
		if (applyHeat(matrix, y, x, y, x + 1) == true) {
			return true;
		}
	}
	if (x - 1 > 0)
	{
		if (applyHeat(matrix, y, x, y, x - 1) == true) {
			return true;
		}
	}
	return false;
}

inline void Elements::ignite(Matrix& matrix, int y, int x, int yt, int xt) {

	matrix[yt][xt].burnID = matrix[yt][xt].m_ID;
	float temphealth = matrix[yt][xt].health;
	if (matrix[yt][xt].issolid)
	{
		matrix[yt][xt] = STATICFIRE;
	}
	else if (matrix[yt][xt].isliquid)
	{
		matrix[yt][xt] = LIQUIDFIRE;
	}
	else
	{
		matrix[yt][xt] = STATICFIRE;
	}
	matrix[yt][xt].health = temphealth;
	matrix[yt][xt].wasupdated = true;

}


inline bool Elements::applyHeat(Matrix& matrix, int y, int x, int yt, int xt) {

	if (matrix[yt][xt].fireresistance != -1) {
		if (getRandom(baseheat, maxheat) > matrix[yt][xt].fireresistance)
		{
			ignite(matrix, y, x, yt, xt);
		}
		return true;
	}

	//turns water and ice into steam
	if (matrix[yt][xt].m_ID == 2 || matrix[yt][xt].m_ID == 14)
	{

		matrix[y][x] = AIR;
		matrix[yt][xt] = STEAM;
		matrix[yt][xt].getColor(STEAM.colorPalette, matrix, yt, xt);
		return true;

	}
	//turns sand into glass
	if (matrix[yt][xt].m_ID == 1) {
		if (getRandom(0, 100) < 10)
		{
			matrix[y][x] = AIR;
			matrix[yt][xt] = GLASS;
			matrix[yt][xt].getColor(GLASS.colorPalette, matrix, yt, xt);
			matrix[y][x].wasupdated = true;
			matrix[yt][xt].wasupdated = true;
		}
		else
		{
			return false;
		}

	}
	else
		return false;
}

//Subtracts health From Corodable Elements, on death replaces Element with FlammableGas
void Elements::corode(Matrix& matrix, int yt, int xt) {
	matrix[yt][xt].health -= 30;
	if (matrix[yt][xt].health < 0)
	{
		matrix[yt][xt] = FLAMMABLEGAS;
		matrix[yt][xt].getColor(FLAMMABLEGAS.colorPalette, matrix, yt, xt);

	}
}

//gets random color from color palette
const inline void Elements::getColor(std::vector<sf::Color>& colorPalette, Matrix& matrix, int y, int x) {

	std::size_t paletteSize = colorPalette.size();
	matrix[y][x].m_color = colorPalette[getRandom(0, paletteSize - 1)];

}



inline bool Elements::completeboundscheck(int y, int x) {
	if (y - 1 > 0 && y + 1 < worldheight && x - 1 > 0 && x + 1 < worldwidth)
	{
		return true;
	}
	else return false;
}
//checks if an Element is surrounded by another set Element
inline bool Elements::issurroundedby(Matrix& matrix, int y, int x, int id) {
	if (completeboundscheck(y, x) == true) {
		for (int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++)
			{
				if (matrix[y + i][x + j].m_ID != id)
				{
					return false;
				}
			}
			return true;
	}
	else {
		return false;
	}

}
//checks if an Element is touched by a single instance of another set Element
inline bool Elements::istouchedby(Matrix& matrix, int y, int x, int id) {

	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
		{
			if (y + i < worldheight && y + i > 0 && x + j < worldwidth && x + j > 0)
			{
				if (matrix[y + i][x + j].m_ID == id)
				{
					return true;
				}
			}
		}
	return false;

}


//moves element down with acceleration
inline bool Elements::gravity(Matrix& matrix, int y, int x) {

	float tempvel_y = matrix[y][x].velocity_y;

	if (matrix[y][x].isfreefaling == true && tempvel_y < maxvelocity)
	{
		tempvel_y += matrix[y][x].weight * 0.01 + getRandom(1, 5) * 0.1;
	}

	int desired = tempvel_y + 1;
	int actual = 0;

	if (y + 1 < worldheight && matrix[y + 1][x].m_ID == 0 || y + 1 < worldheight && matrix[y + 1][x].isgas)
	{


		for (int i = 1; i <= desired; i++) {
			if (y + i >= worldheight)
			{
				break;
			}
			if (matrix[y + i][x].m_ID == 0 || matrix[y + i][x].isgas)
			{
				//increase actual for every free pixel underneath
				actual++;
			}
			else { break; }
		}
		//if (actual == 0) { actual = 1; }

		if (matrix[y + actual][x].isgas) {
			swapelements(matrix, y, x, y + actual, x);
		}
		else {
			matrix[y + actual][x] = matrix[y][x];
			matrix[y][x] = AIR;
		}
		matrix[y + actual][x].wasupdated = true;
		matrix[y + actual][x].isfreefaling = true;
		matrix[y + actual][x].velocity_y = tempvel_y;

		//std::cout << "Velocity: " << matrix[y + actual][x].m_velocity << std::endl;

		return true;


	}
	else
	{
		matrix[y][x].isfreefaling = false;

		if (matrix[y][x].velocity_y > 0) {
			if (getRandom(-1, 1) < 0)
			{
				//negative velocity
				matrix[y][x].velocity_x = matrix[y][x].velocity_y * -1 / 2;
				matrix[y][x].velocity_y = 0;
			}
			else
			{
				//positive velocity
				matrix[y][x].velocity_x = matrix[y][x].velocity_y / 2;
				matrix[y][x].velocity_y = 0;
			}

		}
	}
	return false;
}

//Moves Elements to their max dispersal on x axis
inline bool Elements::moveSideways2(Matrix& matrix, int y, int x) {
	//add velocity

	int current = 0;

	int rng = getRandom(0, 1);

	if (rng == 0)
	{
		for (int i = 1; i <= matrix[y][x].maxdispersal; i++)
		{

			if (x + i >= worldwidth)
			{
				break;
			}
			if (matrix[y][x + i].m_ID == 0 || matrix[y][x + i].isgas)
			{
				current++;
			}
			else
			{
				break;
			}
			
		}
	}
	else if (rng == 1)
	{
		for (int i = -1; i >= matrix[y][x].maxdispersal *-1; i--)
		{

			if (x + i < 0)
			{
				break;
			}
			if (matrix[y][x + i].m_ID == 0 || matrix[y][x + i].isgas)
			{
				current--;
			}
			else
			{
				break;
			}
			
		}
	}



	if (current == 0)
	{
		return false;
	}
	if (matrix[y][x + current].m_ID == 0)
	{
		matrix[y][x + current] = matrix[y][x];
		matrix[y][x + current].wasupdated == true;
		matrix[y][x] = AIR;
		return true;
	}
	else if (x + current > 0 && matrix[y][x + current].isgas)
	{
		swapelements(matrix, y, x + current -1, y, x + current);
		return true;
	}



}



//check left and right and move if spoace is available
inline bool Elements::moveSideways(Matrix& matrix, int y, int x) {


	// Check leftward movement
	if (getRandom100() > 50) {
		if (x - 1 > 0) {
			if (matrix[y][x - 1].m_ID == 0) {

				matrix[y][x - 1] = matrix[y][x];
				matrix[y][x] = AIR;
				matrix[y][x - 1].wasupdated = true;
				return true;
			}
			else if (matrix[y][x - 1].isgas)
			{
				swapelements(matrix, y, x, y, x - 1);
				return true;

			}
		}
		// Check rightward movement
		else if (x + 1 < worldwidth) {
			if (matrix[y][x + 1].m_ID == 0) {

				matrix[y][x + 1] = matrix[y][x];
				matrix[y][x] = AIR;
				matrix[y][x + 1].wasupdated = true;
				return true;

			}
			else if (matrix[y][x + 1].isgas) {
				swapelements(matrix, y, x, y, x + 1);
				return true;

			}
		}
	}
	else
	{
		// Check rightward movement
		if (x + 1 < worldwidth) {
			if (matrix[y][x + 1].m_ID == 0) {

				matrix[y][x + 1] = matrix[y][x];
				matrix[y][x] = AIR;
				matrix[y][x + 1].wasupdated = true;
				return true;

			}
			else if (matrix[y][x + 1].isgas) {
				swapelements(matrix, y, x, y, x + 1);
				return true;

			}
			// Check left movement
			if (x - 1 > 0) {
				if (matrix[y][x - 1].m_ID == 0) {

					matrix[y][x - 1] = matrix[y][x];
					matrix[y][x] = AIR;
					matrix[y][x - 1].wasupdated = true;
					return true;

				}
				else if (matrix[y][x - 1].isgas)
				{
					swapelements(matrix, y, x, y, x - 1);
					return true;

				}
			}
		}

	}
	return false;

}



inline bool MovableSolids::moveSideways(Matrix& matrix, int y, int x) {

	float tempvel_x = matrix[y][x].velocity_x;

	int desired = tempvel_x;
	int actual = 0;

	if (tempvel_x > 0) // positive (+x)
	{
		if (x + 1 < worldwidth && matrix[y][x + 1].m_ID == 0 || x + 1 < worldwidth && matrix[y][x + 1].isgas) {
			for (int i = 1; i <= desired; i++)
			{
				if (x + i < worldwidth && matrix[y][x + i].m_ID == 0 || x + i < worldwidth && matrix[y][x + i].isgas)
				{
					actual++;
				}
				else
				{
					break;
				}
			}
			if (actual == 0) {
				actual = 1;
			}
			if (matrix[y][x + actual].isgas) {
				swapelements(matrix, y, x, y, x + actual);
			}
			else
			{
				matrix[y][x + actual] = matrix[y][x];
				matrix[y][x] = AIR;
			}
			matrix[y][x + actual].wasupdated = true;
			matrix[y][x + actual].velocity_x -= inertialresistance;
			if (matrix[y][x + actual].velocity_x < 0) {
				matrix[y][x + actual].velocity_x = 0;
				return true;
			}
			else {
				matrix[y][x].velocity_x = 0;
			}
			return false;
		}
		else {
			matrix[y][x].velocity_x = 0;

		}
	}
	else // negative (-x)
	{
		if (x - 1 > 0 && matrix[y][x - 1].m_ID == 0 || x - 1 > 0 && matrix[y][x - 1].isgas) {
			for (int i = 0; i > desired; i--)
			{
				if (x - 1 > 0 && matrix[y][x - i].m_ID == 0 || x - i > 0 && matrix[y][x - i].isgas)
				{
					actual--;
				}
				else
				{
					break;
				}
			}
			if (actual == 0) {
				actual = -1;
			}
			if (matrix[y][x + actual].isgas) {
				swapelements(matrix, y, x, y, x + actual);
			}
			else
			{
				matrix[y][x + actual] = matrix[y][x];
				matrix[y][x] = AIR;

			}
			matrix[y][x + actual].wasupdated = true;
			matrix[y][x + actual].velocity_x += inertialresistance;
			if (matrix[y][x + actual].velocity_x > 0) {
				matrix[y][x + actual].velocity_x = 0;
			}
		}
		else {
			matrix[y][x].velocity_x = 0;
		}
	}
	return false;
}


inline bool Elements::moveDiagonallydown(Matrix& matrix, int y, int x) {


	if (getRandom(0,100) > 50)
	{
		if (y + 1 < worldheight && x + 1 < worldwidth) //move down right
		{
			if (matrix[y + 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0)
			{
				matrix[y + 1][x + 1] = matrix[y][x];
				matrix[y][x] = AIR;
				matrix[y + 1][x + 1].wasupdated = true;
				return true;
			}
			else if (matrix[y + 1][x + 1].isgas && matrix[y][x + 1].isgas)
			{
				swapelements(matrix, y, x, y + 1, x + 1);
				return true;
			}
		}
		else if (y + 1 < worldheight && x - 1 > 0) //move down left
		{
			if (matrix[y + 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0)
			{

				matrix[y + 1][x - 1] = matrix[y][x];
				matrix[y][x] = AIR;
				matrix[y + 1][x - 1].wasupdated = true;
				return true;

			}
			else if (matrix[y + 1][x - 1].isgas && matrix[y][x - 1].isgas)
			{
				swapelements(matrix, y, x, y + 1, x - 1);
				return true;
			}
		}
	}
	else
	{

		if (y + 1 < worldheight && x - 1 > 0) //move down left
		{
			if (matrix[y + 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0)
			{

				matrix[y + 1][x - 1] = matrix[y][x];
				matrix[y][x] = AIR;
				matrix[y + 1][x - 1].wasupdated = true;
				return true;

			}
			else if (matrix[y + 1][x - 1].isgas && matrix[y][x - 1].isgas)
			{
				swapelements(matrix, y, x, y + 1, x - 1);
				return true;
			}
		}
		else if (y + 1 < worldheight && x + 1 < worldwidth) //move down right
		{
			if (matrix[y + 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0)
			{
				matrix[y + 1][x + 1] = matrix[y][x];
				matrix[y][x] = AIR;
				matrix[y + 1][x + 1].wasupdated = true;
				return true;
			}
			else if (matrix[y + 1][x + 1].isgas && matrix[y][x + 1].isgas)
			{
				swapelements(matrix, y, x, y + 1, x + 1);
				return true;
			}
		}
	}
	return false;
}


inline bool Elements::moveDiagonallyup(Matrix& matrix, int y, int x) {
	if (y - 1 > 0 && x + 1 < worldwidth && matrix[y - 1][x + 1].m_ID == 0 && matrix[y][x + 1].m_ID == 0) //move up right
	{
		matrix[y - 1][x + 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x + 1].wasupdated = true;
		return true;
	}
	else if (y - 1 > 0 && x - 1 > 0 && matrix[y - 1][x - 1].m_ID == 0 && matrix[y][x - 1].m_ID == 0) //move up left
	{
		matrix[y - 1][x - 1] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x - 1].wasupdated = true;
		return true;
	}
	return false;
}
inline void Elements::swapelements(Matrix& matrix, int y, int x, int y2, int x2) {

	temp = matrix[y][x];
	matrix[y][x] = matrix[y2][x2];
	matrix[y2][x2] = temp;
	temp = AIR;

	matrix[y][x].wasupdated = true;
	matrix[y2][x2].wasupdated = true;

}

inline bool Elements::inverse_gravity(Matrix& matrix, int y, int x) {
	if (y - 1 > 0 && matrix[y - 1][x].m_ID == 0)
	{
		matrix[y - 1][x] = matrix[y][x];
		matrix[y][x] = AIR;
		matrix[y - 1][x].wasupdated = true;
		return true;
	}
	return false;
}


////////////////////////
//		 Solids
void MovableSolids::updateelement(Matrix& matrix, int y, int x) {

	if (y + 1 < worldheight && matrix[y + 1][x].isliquid)
	{
		swapelements(matrix, y, x, y + 1, x);
	}

	if (!gravity(matrix, y, x))
	{
		if (matrix[y][x].velocity_x != 0)
		{
			moveSideways(matrix, y, x);
		}
		if (!moveDiagonallydown(matrix, y, x))
		{
			matrix[y][x].hasmoved = false;
		}
	}

}

void ImmovableSolids::updateelement(Matrix& matrix, int y, int x) {
	if (matrix[y][x].hasmoved)
		getColor(colorPalette, matrix, y, x);
}


//	
////////////////////////


////////////////////////
//		LIQUIDS
void Liquids::updateelement(Matrix& matrix, int y, int x) {
	matrix[y][x].hasmoved = true;

	if (y - 1 > 0)
	{
		if (matrix[y][x].density < matrix[y - 1][x].density)
		{
			if (getRandom(0, 100) < 15)
			{
				swapelements(matrix, y, x, y - 1, x);
			}
		}
	}
	if (getRandom(0, 100) < 30) {
		if (x - 1 > 0 && x + 1 < worldwidth) {
			int rng = getRandom(-1, 1);
			if (/*matrix[y][x + rng].m_ID != 0 &&*/matrix[y][x + rng].isliquid && matrix[y][x + rng].m_ID != matrix[y][x].m_ID)
			{
				swapelements(matrix, y, x, y, x + rng);
			}

		}
	}

	if (!gravity(matrix, y, x)) {
		if (!moveDiagonallydown(matrix, y, x)) {
			if (!moveSideways2(matrix, y, x))
			{
				matrix[y][x].hasmoved = false;
			}
		}
	}
}
//		LIQUIDS
////////////////////////


////////////////////////
//		Gas

void Gas::updateelement(Matrix& matrix, int y, int x) {
	matrix[y][x].hasmoved = true;
	if (!inverse_gravity(matrix, y, x)) {
		if (!moveDiagonallyup(matrix, y, x)) {
			if (!moveSideways(matrix, y, x)) {
				matrix[y][x].hasmoved = false;
			}
		}
	}
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
	try_actOnOther(matrix, y, x);
	Liquids::updateelement(matrix, y, x);
}

void StaticFire::updateelement(Matrix& matrix, int y, int x) {

	getColor(colorPalette, matrix, y, x);



	matrix[y][x].health -= getRandom(1, 5) * 0.2;

	if (matrix[y][x].health < 0)
	{
		matrix[y][x] = AIR;
		matrix[y][x].wasupdated = true;
	}
	if (getRandom(0, 100) < 30)
	{
		try_applyHeat(matrix, y, x);

	}

	//random chance to spawn GasFire Particle
	if (getRandom(0, 100) < 50)
	{
		if (y - 1 > 0 && matrix[y - 1][x].m_ID == 0)
		{
			matrix[y - 1][x] = GASFIRE;
		}
		else if (y + 1 < worldheight && matrix[y + 1][x].m_ID == 0)
		{
			matrix[y + 1][x] = GASFIRE;
		}
		else if (x + 1 < worldwidth && matrix[y][x + 1].m_ID == 0)
		{
			matrix[y][x + 1] = GASFIRE;
		}
		else if (x - 1 > 0 && matrix[y][x - 1].m_ID == 0)
		{
			matrix[y][x - 1] = GASFIRE;
		}
	}

	ImmovableSolids::updateelement(matrix, y, x);


}

void GasFire::updateelement(Matrix& matrix, int y, int x) {

	//matrix[y][x].m_color = sf::Color(255, getRandom(0, 100), 0, getRandom(50, 255));

	getColor(colorPalette, matrix, y, x);

	matrix[y][x].health -= getRandom(0, 5);

	if (matrix[y][x].health < 0)
	{
		if (getRandom(0, 100) < 30)
		{
			matrix[y][x] = SMOKE;
		}
		else {
			matrix[y][x] = AIR;
		}
		matrix[y][x].wasupdated = true;
	}
	if (getRandom(0, 100) < 30)
	{
		try_applyHeat(matrix, y, x);
	}

	if (y - 1 > 0 && matrix[y - 1][x].m_ID == 4)
	{
		swapelements(matrix, y, x, y - 1, x);
	}
	Gas::updateelement(matrix, y, x);

}


void LiquidFire::updateelement(Matrix& matrix, int y, int x) {

	getColor(colorPalette, matrix, y, x);

	matrix[y][x].health -= getRandom(1, 5) * 0.2;

	if (matrix[y][x].health < 0)
	{
		matrix[y][x] = AIR;
		matrix[y][x].wasupdated = true;
	}
	if (getRandom(0, 100) < 30)
	{
		try_applyHeat(matrix, y, x);
	}
	//50% random chance to spawn GasFire Particle
	if (getRandom(0, 100) < 50)
	{
		if (y - 1 > 0 && matrix[y - 1][x].m_ID == 0)
		{
			matrix[y - 1][x] = GASFIRE;
		}
		else if (y + 1 < worldheight && matrix[y + 1][x].m_ID == 0)
		{
			matrix[y + 1][x] = GASFIRE;
		}
		else if (x + 1 < worldwidth && matrix[y][x + 1].m_ID == 0)
		{
			matrix[y][x + 1] = GASFIRE;
		}
		else if (x - 1 > 0 && matrix[y][x - 1].m_ID == 0)
		{
			matrix[y][x - 1] = GASFIRE;
		}
	}

	Liquids::updateelement(matrix, y, x);
}

void Lava::updateelement(Matrix& matrix, int y, int x) {
	try_actOnOther(matrix, y, x);
	try_applyHeat(matrix, y, x);
	Liquids::updateelement(matrix, y, x);
}




void Steam::updateelement(Matrix& matrix, int y, int x) {
	//turns into Water after a while
	if (health > 0) {
		matrix[y][x].health -= 1;
	}
	if (matrix[y][x].health < 0) {

		if (getRandom(0, 100000) == 10)
		{
			matrix[y][x] = WATER;
			matrix[y][x].getColor(WATER.colorPalette, matrix, y, x);

		}

	}

	Gas::updateelement(matrix, y, x);
}

void Cement::updateelement(Matrix& matrix, int y, int x) {

	if (!istouchedby(matrix, y, x, 2)) {
		matrix[y][x].lifetime -= getRandom(0, 5) * 0.1;
	}

	if (matrix[y][x].lifetime < 0)
	{
		if (!issurroundedby(matrix, y, x, 13) && !istouchedby(matrix, y, x, 2))
		{
			matrix[y][x] = STONE;
			matrix[y][x].getColor(STONE.colorPalette, matrix, y, x);
		}
	}
	if (matrix[y][x].isliquid)
		Liquids::updateelement(matrix, y, x);

}

void Ice::updateelement(Matrix& matrix, int y, int x) {
	ImmovableSolids::updateelement(matrix, y, x);
	try_actOnOther(matrix, y, x);

}

inline bool Ice::actOnOther(Matrix& matrix, int y, int x, int yt, int xt) {
	if (matrix[yt][xt].m_ID == 2) {
		matrix[yt][xt].temperature -= 1;
		if (matrix[yt][xt].temperature < 0)
		{
			matrix[yt][xt] = ICE;
			matrix[yt][xt].getColor(ICE.colorPalette, matrix, yt, xt);
		}
		return true;
	}
	else {
		return false;
	}

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

