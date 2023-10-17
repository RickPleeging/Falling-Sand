#pragma once
#include "pch.h"


class Elements
{
public:
	Elements();

};

class Solids : public Elements {
public:

	Solids();

};

class MovableSolids : public Solids {
public:

	MovableSolids();

};

class ImmovableSolids : public Solids {
public:

	ImmovableSolids();
};


