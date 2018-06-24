#include "stdafx.h"
#include "tile.h"
#include <iostream>

Tile::Tile() {

}

Tile::Tile(int coo_x, int coo_y, sea_type type) {
	coord_x = coo_x;
	coord_y = coo_y;
	this->type = type;
}

std::vector<int> Tile::getCoord() {
	std::vector<int> coords(2);
	coords[0] = this->coord_x;
	coords[1] = this->coord_y;

	return coords;
}

void Tile::setCoord(int cx, int cy) {
	this->coord_x = cx;
	this->coord_y = cy;
}

sea_type Tile::getType() {
	return this->type;
}

void Tile::setType(sea_type type) {
	this->type = type;
}

void Tile::draw() {

	switch (type) {
		case sea:
			std::cout << "~";
			break;
		case ship:
			std::cout << "s";
			break;
		case hit:
			std::cout << "X";
			break;
		case miss:
			std::cout << "o";
			break;
	}
}

