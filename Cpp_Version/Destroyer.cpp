#include "stdafx.h"
#include "Destroyer.h"
#include "ship.h"
#include "board.h"
#include <iostream>

Destroyer::Destroyer(Tile start_index, orientation ornt) : Ship(start_index, ornt) {
	this->size = 2;
}

bool Destroyer::placeShip(Tile start_index, orientation ornt, Board &brd) {

	//std::vector< std::vector<Tile>> brdm = brd.getBrd();
	std::vector<int> st_coord = start_index.getCoord();
	
	bool place = checkLmt(st_coord, ornt, brd, 2);
	
	if (place == true) {
		// vertical placement
		if (ornt == vertical) {
			for (int i = st_coord[0]; i < (st_coord[0] + 2); i++) {
				brd.setBrd(i, st_coord[1], ship);
				//brd.getBrd()[i][st_coord[1]].setType(ship);
			}
		}
		// horizontal placement
		else {
			for (int i = st_coord[1]; i < (st_coord[1] + 2); i++) {
				brd.setBrd(st_coord[0], i, ship);
				//std::cout << brd.getBrd()[i][st_coord[1]].getType();
			}
			
		}
		printf("A Destroyer was created ! \n");
		return true;
	}
	else {
		printf("Limitations were not satisfied ! \n");
		return false;
	}

}