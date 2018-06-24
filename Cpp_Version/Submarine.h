#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "ship.h"
#include "tile.h"

class Submarine : public Ship
{

private:
	int size;

public:
	Submarine(Tile start_index, orientation ornt);
	bool placeShip(Tile start_index, orientation ornt, Board &brd);

};

#endif