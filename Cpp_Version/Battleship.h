#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "ship.h"
#include "tile.h"

class Battleship : public Ship
{

private:
	int size;

public:
	Battleship(Tile start_index, orientation ornt);
	bool placeShip(Tile start_index, orientation ornt, Board &brd);

};

#endif