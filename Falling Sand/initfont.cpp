#include "pch.h"

void initfont()
{
	if (!font.loadFromFile("A:\\Rick\\Coding\\repos\\Falling-Sand\\Assets\\arial.ttf")) {
		std::cout << "error loading font!";
	}

}
