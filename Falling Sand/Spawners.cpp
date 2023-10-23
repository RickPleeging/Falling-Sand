#pragma once
#include "pch.h"
#include "Spawners.h"

Spawners::Spawners() {
	m_color = sf::Color(236, 66, 245, 255);
	m_ID = 100;

}

void Spawners::updateelement(Matrix& matrix, int i, int j)
{
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

	}
}

	
