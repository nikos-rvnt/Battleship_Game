#pragma once
#ifndef TILE_H
#define TILE_H

#include <vector>

enum sea_type { sea, ship, hit, miss};

class Tile
{

private:
	int coord_x;
	int coord_y;
	sea_type type;

public:
	Tile();
	Tile( int coo_x, int coo_y, sea_type type);
	std::vector<int> getCoord();
	void setCoord( int xx, int yy);
	sea_type getType();
	void setType(sea_type type);
	void draw();
};

#endif
