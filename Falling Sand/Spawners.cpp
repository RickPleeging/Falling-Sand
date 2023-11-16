#pragma once
#include "pch.h"
#include "Spawners.h"

Spawners::Spawners() {
	m_color = sf::Color(236, 66, 245, 100);
	m_ID = 100;

}

void Spawners::updateelement(Matrix& matrix, int i, int j)
{
	if (i + 1 < worldheight && matrix[i+1][j].m_ID == 0) {

		switch (matrix[i][j].m_spawnID)
		{
		case 1:
			matrix[i + 1][j] = SAND;
			break;
		case 2:
			matrix[i + 1][j] = WATER;
			break;
		case 4:
			matrix[i + 1][j] = SMOKE;
			break;
		case 5:
			matrix[i + 1][j] = ACID;
			break;
		case 6:
			matrix[i + 1][j] = FLAMMABLEGAS;
			break;
		case 9:
			matrix[i + 1][j] = STEAM;
		case 11:
			matrix[i + 1][j] = LAVA;
			break;
		case 12:
			matrix[i + 1][j] = OIL;
			break;
		case 20:
			matrix[i + 1][j] = STATICFIRE;
			break;

		}
	}
}

	
