#pragma once
#include "pch.h"

int FPS=0;

int pixelsize = 1;
int cursorsize = 1;

bool fullscreen;
bool pause = false;
bool nodraw = false;

int selectedID = 1;
int spawnID = 0;
int selectedbrush = 1;

bool steponce = false;

Elements AIR;
Elements selection;
Elements temp;
Elements target;
Elements current;

Spawners SPAWNER;

Sand SAND;
Water WATER;
Stone STONE;
Smoke SMOKE;
BlackHole BLACKHOLE;
Acid ACID;
FlammableGas FLAMMABLEGAS;