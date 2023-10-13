#include "pch.h"


Material::Material(std::string name, int id) : m_name(name), m_id(id) {}

void Material::gravity(std::vector<std::vector<int>>& matrix, int i, int j) {
    // Gravity logic (velocity)
}

void Material::updatematerial(std::vector<std::vector<int>>& matrix, int i, int j) {
    
	
	
	// Update material logic
	if (i + 1 < worldheight && matrix[i + 1][j] == 0)
	{
		// for debuging movement to the console
		/*	std::cout << "moving y: " << i;
			std::cout << "to y: " << i+1 ;
			std::cout << " Out of Max: " << worldheight << "\n";*/
		
		matrix[i][j] = 0;
		matrix[i + 1][j] = 1;


	}
	else if (i + 1 < worldheight && j+1 < worldwidth && matrix[i + 1][j + 1] == 0 && matrix[i][j + 1] == 0) //move down right
	{
		matrix[i][j] = 0;
		matrix[i + 1][j + 1] = 1;
	}
	else if (i + 1 < worldheight && j > 0 && matrix[i + 1][j - 1] == 0 && matrix[i][j - 1] == 0) //move down left
	{
		matrix[i][j] = 0;
		matrix[i + 1][j - 1] = 1;
	}
	

}

