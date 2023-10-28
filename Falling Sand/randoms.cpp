#pragma once
#include "pch.h"

std::random_device random100;
std::mt19937 gen(random100());
std::uniform_int_distribution<int> distribution(0, 100);
std::uniform_int_distribution<int> distribution1(0,5);


int getRandom() {
	return distribution(gen);
}

int getRandom1() {
	return distribution1(gen);
}