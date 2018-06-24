#include "stdafx.h"
#include "Battleship.h"
#include "ship.h"
#include "board.h"
#include <iostream>

Battleship::Battleship(Tile start_index, orientation ornt) : Ship(start_index, ornt) {
	this->size = 4;
}

bool Battleship::placeShip(Tile start_index, orientation ornt, Board &brd) {  
	
	//std::vector< std::vector<Tile>> brdm = brd.getBrd();
	std::vector<int> st_coord = start_index.getCoord();

	bool place = checkLmt(st_coord, ornt, brd, 4);

	if (place == true) {
		// vertical placement
		if (ornt == vertical) {
			for (int i = st_coord[0]; i < (st_coord[0] + 4); i++) {
				brd.setBrd(i, st_coord[1], ship);
				//brd.getBrd()[i][st_coord[1]].setType(ship);
			}
		}
		// horizontal placement
		else {
			for (int i = st_coord[1]; i < (st_coord[1] + 4); i++) {
				brd.setBrd(st_coord[0], i, ship);
				//std::cout << brd.getBrd()[i][st_coord[1]].getType();
			}
			
		}
		printf("A Battleship was created ! \n");
		return true;
	}
	else {
		printf("Limitations were not satisfied ! \n");
		return false;
	}
	
}
