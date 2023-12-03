#pragma once
#include "pch.h"

std::random_device random100;
std::mt19937 gen(random100());
std::uniform_int_distribution<int> distribution100(0, 100);
std::uniform_int_distribution<int> distribution05(0,5);
std::uniform_int_distribution<int> distribution255(0, 255);


int getRandom100() {
	return distribution100(gen);
}

int getRandom05() {
	return distribution05(gen);
}
int getRandom255() {
	return distribution255(gen);
}

int getRandom(int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(gen);
}