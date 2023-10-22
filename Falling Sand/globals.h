#pragma once


//externals
extern int height;
extern int width;

extern int worldwidth;
extern int worldheight;
extern int pixelsize;
extern double worldarraysize;


extern sf::Font font;

extern int cursorsize;
extern int cursorsize_max;
extern int increaserate;

extern int pixelsize;

extern float dt;

extern bool fullscreen;
extern bool nodraw;
extern bool pause;

extern int selectedID;

extern int selectedbrush;
extern bool steponce;

class Elements;
class Solids;
class MovableSolids;
class ImmovableSolids;
class Liquids;

class Sand;
class Water;
class Stone;


extern Elements AIR;
extern Elements selection;
extern Elements temp;

extern Sand SAND;
extern Water WATER;
extern Stone STONE;

using Matrix = std::vector<std::vector<Elements>>;