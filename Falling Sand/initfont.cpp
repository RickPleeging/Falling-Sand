#include "pch.h"

void initfont()
{
	if (!font.loadFromFile("..\\Assets\\arial.ttf")) {
		std::cout << "error loading font!";
	}

}
