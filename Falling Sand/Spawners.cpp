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
			matrix[i + 1][j].getColor(SAND.colorPalette,matrix,i+1,j);
			break;
		case 2:
			matrix[i + 1][j] = WATER;
			matrix[i + 1][j].getColor(WATER.colorPalette, matrix, i + 1, j);
			break;
		case 4:
			matrix[i + 1][j] = SMOKE;
			matrix[i + 1][j].getColor(SMOKE.colorPalette, matrix, i + 1, j);
			break;
		case 5:
			matrix[i + 1][j] = ACID;
			matrix[i + 1][j].getColor(ACID.colorPalette, matrix, i + 1, j);
			break;
		case 6:
			matrix[i + 1][j] = FLAMMABLEGAS;
			matrix[i + 1][j].getColor(FLAMMABLEGAS.colorPalette, matrix, i + 1, j);
			break;
		case 9:
			matrix[i + 1][j] = STEAM;
			matrix[i + 1][j].getColor(STEAM.colorPalette, matrix, i + 1, j);
			break;
		case 11:
			matrix[i + 1][j] = LAVA;
			matrix[i + 1][j].getColor(LAVA.colorPalette, matrix, i + 1, j);
			break;
		case 12:
			matrix[i + 1][j] = OIL;
			matrix[i + 1][j].getColor(OIL.colorPalette, matrix, i + 1, j);
			break;
		case 20:
			matrix[i + 1][j] = STATICFIRE;
			matrix[i + 1][j].getColor(STATICFIRE.colorPalette, matrix, i + 1, j);
			break;
		default :
			break;
		}
	}
}

	
