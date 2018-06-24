#ifndef CRUISER_H
#define CRUISER_H

#include "ship.h"
#include "tile.h"

class Cruiser : public Ship
{

private:
	int size;

public:
	Cruiser(Tile start_index, orientation ornt);
	bool placeShip(Tile start_index, orientation ornt, Board &brd);

};

#endif