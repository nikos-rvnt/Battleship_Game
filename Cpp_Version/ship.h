#ifndef SHIP_H
#define SHIP_H

#include "tile.h"
#include "board.h"

enum orientation { horizontal, vertical};

class Ship
{

private:
	Tile start_index;
	orientation ornt;

public:
	Ship();
	Ship(Tile start_index, orientation ornt);
	orientation getOrient();
	virtual bool placeShip( Tile start_index, orientation ornt, Board &brd) ;
	bool checkLmt( std::vector<int> st_coord, orientation ornt, Board brd, int size);

};

#endif