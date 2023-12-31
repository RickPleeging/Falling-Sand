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
extern int FPS;

extern bool fullscreen;
extern bool nodraw;
extern bool pause;

extern int selectedID;
extern int selectedmat;
extern int spawnID;
extern int selectedbrush;
extern bool steponce;
extern sf::Color BackgroundColor;


class Elements;
class Solids;
class MovableSolids;
class ImmovableSolids;
class Liquids;
class Gas;

class Spawners;

class Sand;
class Water;
class Stone;
class Smoke;
class Acid;
class FlammableGas;
class Glass;
class Wood;
class BlackHole;
class StaticFire;
class LiquidFire;
class GasFire;
class Steam;
class Lava;
class Oil;
class Cement;
class Ice;

extern Elements AIR;
extern Elements selection;
extern Elements temp;
extern Elements target;
extern Elements current;


extern Sand SAND;
extern Water WATER;
extern Stone STONE;
extern Smoke SMOKE;
extern Acid ACID;
extern FlammableGas FLAMMABLEGAS;
extern Glass GLASS;
extern Wood WOOD;
extern BlackHole BLACKHOLE;
extern StaticFire STATICFIRE;
extern LiquidFire LIQUIDFIRE;
extern GasFire GASFIRE;
extern Steam STEAM;
extern Lava LAVA;
extern Oil OIL;
extern Cement CEMENT;
extern Ice ICE;

extern Spawners SPAWNER;

using Matrix = std::vector<std::vector<Elements>>;