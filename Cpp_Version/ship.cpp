#include "stdafx.h"
#include "ship.h"
#include "tile.h"

#include <iostream>
#include <exception>

using namespace std;

struct OversizeException : public exception {
	const char * what() const throw () {
		return "Oversize Exception";
	}
};

struct OverlapTilesException : public exception {
	const char * what() const throw () {
		return "Overlap Tiles Exception";
	}
};

struct AdjacentTilesException : public exception {
	const char * what() const throw () {
		return "Adjacent Tiles Exception";
	}
};

/*
	try {
		throw MyException();
	}
	catch (MyException& e) {
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch (std::exception& e) {
		//Other errors
	}
*/

Ship::Ship() {

}

Ship::Ship(Tile start_index, orientation ornt) {
	this->start_index = start_index;
	this->ornt = ornt;
}

orientation Ship::getOrient() {
	return this->ornt;
}

bool Ship::placeShip(Tile start_index, orientation ornt, Board &brd) {
	
	return true;
}
/*
bool Ship::placeShip(Tile start_index, orientation ornt, std::vector< std::vector<Tile>> &brd, int brdL) {

	return true;
}*/


bool Ship::checkLmt(std::vector<int> st_coord, orientation ornt, Board brd, int size) {

	std::vector< std::vector<Tile>> brdm = brd.getBrd();
	
	bool check = true;

	// check horizontally placing
	if (ornt == horizontal) {
		// check if out of border limits
		if ((st_coord[1] + size) <= brd.getLength()) {
			for (int i = st_coord[1]; i < (st_coord[1] + size); i++) {	
				// check if another ship already exists
				//printf("tii0401");
				if (brdm[st_coord[0]][i].getType() == 1) {
					//printf("tii0488801");
					check = false;
					break;
				}
				//printf("tii001");
				
 				// check if the ship touches another one already existing in a neighbour tile in front or back
				if (i==st_coord[1] && st_coord[1]!=0) {
					if (brd.getBrd()[st_coord[0]][st_coord[1] - 1].getType() == 1) {
						check = false;
						break;
					}
				}
				//printf("tii1");
				// check if the ship touches another one already existing in a neighbour tile above or down
				if ( st_coord[0] < (brd.getLength()-1) ) {
					if ( brd.getBrd()[st_coord[0] + 1][i].getType() == 1 ) {
						check = false;
						break;
					}
				}
				//printf("tii2");

				if( st_coord[0] > 0 ) {
					if ( brd.getBrd()[st_coord[0] - 1][i].getType() == 1 ) {
						check = false;
						break;
					}
				}

			}
			//printf("tii3");

			if ((st_coord[1] + size) < brd.getLength()) {
				if (brd.getBrd()[st_coord[0]][st_coord[1] + size ].getType() == ship){
					check = false;
				}
			}
		}
		else {
			check = false;
		}
		//printf("tii4");
		
	}
	// check vertically placing
	else {
		if ((st_coord[0] + size) <= brd.getLength()) {
			for (int i = st_coord[0]; i < (st_coord[0] + size); i++) {
				// check if another ship already exists
				if (brd.getBrd()[i][st_coord[1]].getType() == 1) {
					check = false;
					break;
				}
				//printf("tii5");

				// check if the ship touches another one already existing in a neighbour tile above
				if (i == st_coord[0] && st_coord[0] != 0) {
					if (brd.getBrd()[st_coord[0] - 1][st_coord[1]].getType() == 1) {
						check = false;
						break;
					}
				}
				// check if the ship touches another one already existing in a neighbour tile in front
				if (st_coord[1] < (brd.getLength()-1)) {
					if ( brd.getBrd()[i][st_coord[1] + 1].getType() == 1 ) {
						check = false;
						break;
					}
					//printf("tii6");

				}
				// check if the ship touches another one already existing in a neighbour tile backside
				if (st_coord[1] > 0) {
					if ( brd.getBrd()[i][st_coord[1] - 1].getType() == 1 ) {
						check = false;
						break;
					}
				}
				//printf("tii7");
			
			}
			if ((st_coord[0] + size) < brd.getLength()) {
				if (brd.getBrd()[ st_coord[0] + size ][ st_coord[1] ].getType() == 1)
					check = false;
				//break;
			}
			//printf("tii8");

		}
		else {
			//printf("tii9");

			check = false;
		}
	}
	
	return check;
}
