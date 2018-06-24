#ifndef DESTROYER_H
#define DESTROYER_H

#include "ship.h"
#include "tile.h"

class Destroyer : public Ship
{

private:
	int size;

public:
	Destroyer(Tile start_index, orientation ornt);
	bool placeShip(Tile start_index, orientation ornt, Board &brd);

};

#endif