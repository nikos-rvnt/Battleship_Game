#ifndef CARRIER_H
#define CARRIER_H

#include "ship.h"
#include "tile.h"

class Carrier : public Ship
{

private:
	int size;

public:
	Carrier( Tile start_index, orientation ornt);
	bool placeShip(Tile start_index, orientation ornt, Board &brd) ;
	//bool placeShip(Tile start_index, orientation ornt, std::vector< std::vector<Tile>> &brd, int brdL);

};

#endif