#include "stdafx.h"
#include "player.h"
#include "ship.h"
#include "Carrier.h"
#include "Submarine.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battleship.h"
#include "tile.h"
#include <ctime>
#include "board.h"

void Player::setName(char* s1) {
	this->name = s1;
}

void Player::placeAllShips(Board &br) {

	orientation orien;
	int ori, xi, yi;
	std::vector< int > crds(2);
	Ship *cr, *bs, *cu, *ds, *sm;
	bool plc;

	std::srand(std::time(nullptr));
	for (int i = 1; i <= 5; i++) {
		
		ori = 0;
		if (i == 1) {
			do{
				
				ori = std::rand() / ((RAND_MAX + 1u) / 2);
				if (ori == 1)
					orien = vertical;
				else
					orien = horizontal;


				xi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				yi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				crds[0] = xi;
				crds[1] = yi;

				Ship* cr = new Carrier(br.getBrd()[xi][yi], orien);
				plc = placeShip(cr, br.getBrd()[xi][yi], cr->getOrient(), br);
			} while (plc==false);
		}
		else if (i == 2) {
			do {
				
				ori = std::rand() / ((RAND_MAX + 1u) / 2);
				if (ori == 1)
					orien = vertical;
				else
					orien = horizontal;

				xi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				yi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				crds[0] = xi;
				crds[1] = yi;

				Ship* bs = new Battleship(br.getBrd()[xi][yi], orien);
				plc = placeShip(bs, br.getBrd()[xi][yi], bs->getOrient(), br);
			} while (plc==false);
		}
		else if (i == 3) {
			do {
				
				ori = std::rand() / ((RAND_MAX + 1u) / 2);
				if (ori == 1)
					orien = vertical;
				else
					orien = horizontal;

				xi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				yi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				crds[0] = xi;
				crds[1] = yi;

				Ship* cu = new Cruiser(br.getBrd()[xi][yi], orien);
				plc = placeShip(cu, br.getBrd()[xi][yi], cu->getOrient(), br);
			} while (plc==false);
		}
		else if (i == 4) {
			do {
				
				ori = std::rand() / ((RAND_MAX + 1u) / 2);
				if (ori == 1)
					orien = vertical;
				else
					orien = horizontal;

				xi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				yi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				crds[0] = xi;
				crds[1] = yi;

				Ship* ds = new Destroyer(br.getBrd()[xi][yi], orien);
				plc = placeShip(ds, br.getBrd()[xi][yi], ds->getOrient(), br);
			} while (plc==false);
		}
		else if (i == 5) {
			do {
				
				ori = std::rand() / ((RAND_MAX + 1u) / 2);
				if (ori == 1)
					orien = vertical;
				else
					orien = horizontal;

				xi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				yi = std::rand() / ((RAND_MAX + 1u) / br.getLength());
				crds[0] = xi;
				crds[1] = yi;

				Ship* sm = new Submarine(br.getBrd()[xi][yi], orien);
				plc = placeShip(sm, br.getBrd()[xi][yi], sm->getOrient(), br);
			} while (plc==false);
		}
	}
}

bool Player::placeShip(Ship* sh, Tile coord, orientation ornt, Board &br) {

	//printf("aaa21aaa");
	bool res = sh->placeShip(coord, ornt, br);
	//printf( "fffff" );

	return res;
}

void Player::statsInit() {
	this->hit_shots = 0;
	this->missed_shots = 0;
	this->repeated_shots = 0;
	this->shots = 0;
}

void Player::getStats() {
	printf("Player %s has: \n\t %d / %d hit shots !", this->name, this->hit_shots, this->shots);
	printf("\n\t %d / %d missed shots !", this->missed_shots, this->shots);
	printf(" \n\t and %d / %d repeated shots ! \n", this->repeated_shots, this->shots);
}

bool Player::fire(Board &brd, std::vector<int> coord) {
	
	bool check = false;

	sea_type target = brd.getBrd()[coord[0]][coord[1]].getType();
	// hit
	if (target == ship) {
		brd.setBrd(coord[0], coord[1], hit);
		printf(" * Hit ! * ");
		this->shots++;
		this->hit_shots++;
		check = true;
	}
	// already hit
	else if (target == hit) {
		brd.setBrd( coord[0], coord[1], hit); //brd[coord[0]][coord[1]].setType(hit);
		printf(" * Already Hit ! * ");
		this->repeated_shots++;
		this->shots++;
		check = true;
	}
	// already miss
	else if (target == miss) {
		brd.setBrd(coord[0], coord[1], miss); //brd[coord[0]][coord[1]].setType(hit);
		printf(" * Already Miss ! * ");
		this->repeated_shots++;
		this->shots++;
	}
	// miss
	else if (target == sea) {
		brd.setBrd(coord[0], coord[1], miss); //brd[coord[0]][coord[1]].setType(miss);
		printf(" * Miss ! * ");
		this->missed_shots++;
		this->shots++;
	}

	return check;
}
