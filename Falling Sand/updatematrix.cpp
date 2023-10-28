#include "pch.h"


void updatematrix(std::vector<std::vector<Elements>>& matrix, int worldheight, int worldwidth, sf::RenderWindow& window)
{
	//reset wasupdated for every Element
	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			matrix[i][j].wasupdated = false;
		}



	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			if (matrix[i][j].wasupdated == false) {

				switch (matrix[i][j].m_ID)
				{
				case 0:
					break;
				case 1:
					SAND.updateelement(matrix, i, j);
					break;
				case 2:
					WATER.updateelement(matrix, i, j);
					break;
				case 3:
					STONE.updateelement(matrix, i, j);
					break;
				case 4:
					SMOKE.updateelement(matrix, i, j);
					break;
				case 5:
					ACID.updateelement(matrix, i, j);
					break;
				case 6:
					FLAMMABLEGAS.updateelement(matrix, i, j);
					break;
				case 7:
					GLASS.updateelement(matrix, i, j);
					break;
				case 8:
					WOOD.updateelement(matrix, i, j);
					break;
				case 10:
					BLACKHOLE.updateelement(matrix, i, j);
					break;
				case 100:
					SPAWNER.updateelement(matrix, i, j);
					break;
				}
			}
		}


}

