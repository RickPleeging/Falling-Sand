#include "pch.h"



void updatematrix(std::vector<std::vector<int>>& matrix, int worldheight, int worldwidth, sf::RenderWindow& window)
{


	for (int i = worldheight - 1; i >= 0; i--)
		for (int j = worldwidth - 1; j >= 0; j--)
		{
			switch (matrix[i][j])
			{
			case 0:
				break;
			case 1:
				Sand.updatematerial(matrix, i, j);
				
				break;
			case 2:
				break;
			case 3:
				Water.updatematerial(matrix, i, j);
				
			}
		}
}

