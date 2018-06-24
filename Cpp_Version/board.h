#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include <vector>

static int cntHide = 0;

class Board
{

private:
	int length = 10;
	std::vector < std::vector < Tile > > brd_mat = std::vector < std::vector < Tile > >( length, std::vector< Tile >( length ));
	bool hidden;

public:
	Board();
	std::vector< std::vector<Tile>> getBrd();
	int getLength();
	void setBrd( int inx, int iny, sea_type);
	friend void drawboards( Board brd1, Board brd2);
	std::vector<Tile> getAdjacentTiles(Tile t);
	void placeAllShips();
	bool allShipsSunk();

};

#endif
