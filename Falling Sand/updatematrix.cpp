#include "pch.h"



void updatematrix(std::vector<std::vector<Elements>>& matrix, int worldheight, int worldwidth, sf::RenderWindow& window)
{
	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			matrix[i][j].m_wasupdated = false;
		}


	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			if (matrix[i][j].m_wasupdated == false) {

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
				}
			}
		}


}

