// Battleship_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "player.h"
#include "tile.h"
#include "board.h"
#include "ship.h"
#include "Carrier.h"
#include "Submarine.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Battleship.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

vector<int> getInput() {
	int xx, yy;
	vector<int> crd;
	cin >> xx >> yy;
	crd.push_back(xx);
	crd.push_back(yy);

	return crd;
}

vector<int> getRandInput() {
	int xx, yy;
	vector<int> crd;

	std::srand(std::time(nullptr));
	xx = std::rand() / ((RAND_MAX + 1u) / 8);
	yy = std::rand() / ((RAND_MAX + 1u) / 8);
	crd.push_back(xx);
	crd.push_back(yy);

	return crd;
}

orientation getOrientation() {
	orientation orient;
	
	char ans_ornt;
	cout << "Do you want to place it vertically or horizontally ? (V or v for vertically // H or h for horizontally) " << endl;
	cin >> ans_ornt;
	if (ans_ornt == 'V' || ans_ornt == 'v')
		orient = vertical;
	else
		orient = horizontal;

	return orient;
}

bool randomPlace() {

	char anser;
	cin >> anser;
	if (anser == 'Y' || anser == 'y')
		return true;
	else
		return false;
}

/*
//Board u_brd = new Board();
Board u_brd;
//Board ai_brd = new Board();
Board ai_brd;
*/

int main()
{

	Player user;
	user.setName("u");
	Player ai;
	ai.setName("digital_mind");

	//Board u_brd = new Board();
	Board u_brd;
	//Board ai_brd = new Board();
	Board ai_brd;
	drawboards( u_brd, ai_brd);

	std::vector< std::vector<Tile>> brdm = u_brd.getBrd();

	orientation ornta;
	vector<int> coords_u, coords_pc;
	ai.placeAllShips(ai_brd);

	cout << "\n\n Do you want to place the ships randomly ? (Y or y for Yes // N or n for No)" << endl;
	bool resu = false;
	int times = 0;

	if (randomPlace()) {
		user.placeAllShips(u_brd);
		printf(" -- bella ciao -- ");
	}
	else {
		cout << "So you desire to place each ship manually giving the coordinates and the orientation." << endl;

		for (int i = 0; i < 5; i++) {
			vector<int> cords;

			if (i == 0) {

				printf("\n 1st Ship, a Carrier.");
				ornta = getOrientation();
				times = 0;

				printf("Now, give the coordinates x,y to place the Carrier : \n");
				do {
					if (times > 0)
						printf("Please give proper coordinates: ");
					cords = getInput();

					Ship* cr = new Carrier(u_brd.getBrd()[cords[0]][cords[1]], ornta);

					resu = user.placeShip(cr, u_brd.getBrd()[cords[0]][cords[1]], cr->getOrient(), u_brd);
					times++;
				} while (resu==false);

				drawboards( u_brd, ai_brd);

			}
			if (i == 1) {

				times = 0;
				printf("\n 2nd Ship, a Battleship.");
				ornta = getOrientation();

				printf("Now, give the coordinates x,y to place the Battleship : \n");
				do {
					if (times > 0)
						printf("Please, give proper coordinates: ");
					cords = getInput();

					Ship* bs = new Battleship(u_brd.getBrd()[cords[0]][cords[1]], ornta);

					resu = user.placeShip(bs, u_brd.getBrd()[cords[0]][cords[1]], bs->getOrient(), u_brd);
					times++;
				} while (resu == false);
				drawboards( u_brd, ai_brd);

			}
			if (i == 2) {

				printf("\n 3rd Ship, a Cruiser.");
				ornta = getOrientation();

				printf("Now, give the coordinates x,y to place the Cruiser : \n");
				do{
					if (times > 0)
						printf("Please, give proper coordinates: ");
					cords = getInput();

					Ship* cru = new Cruiser(u_brd.getBrd()[cords[0]][cords[1]], ornta);

					resu = user.placeShip(cru, u_brd.getBrd()[cords[0]][cords[1]], cru->getOrient(), u_brd);
					times++;
				}while (resu == false);
				drawboards( u_brd, ai_brd);

			}
			if (i == 3) {

				printf("\n 4rd Ship, a Submarine.");
				ornta = getOrientation();

				printf("Now, give the coordinates x,y to place the Submarine : \n");
				do {
					if (times>0)
						printf("Please, give proper coordinates: ");
					cords = getInput();
					Ship* sm = new Submarine(u_brd.getBrd()[cords[0]][cords[1]], ornta);

					resu = user.placeShip(sm, u_brd.getBrd()[cords[0]][cords[1]], sm->getOrient(), u_brd);
					times++;
				} while (resu == false);
				drawboards(u_brd, ai_brd);

			}
			if (i == 4) {
				times = 0;
				printf("\n 5th Ship, a Destroyer. ");
				ornta = getOrientation();

				printf("Now, give the coordinates x,y to place the Destroyer : \n");
				do {
					if (times > 0)
						printf("Please, give proper coordinates: ");
					cords = getInput();

					Ship* ds = new Destroyer(u_brd.getBrd()[cords[0]][cords[1]], ornta);

					resu = user.placeShip(ds, u_brd.getBrd()[cords[0]][cords[1]], ds->getOrient(), u_brd);
					times++;
				} while (resu == false);
				

			}
		}
	}
		drawboards(u_brd, ai_brd);

		user.statsInit();
		ai.statsInit();
		int i = 0;
		vector<Tile> neighbour;
		bool checkInPC = false, checkInMe;
		std::srand(std::time(nullptr));

		while (!u_brd.allShipsSunk() && !ai_brd.allShipsSunk()) {
			
			// user input x, y coordinates
			printf("\n Give the coordinates x,y where you want to fire : \n");
			coords_u = getInput();
			// user fire
			checkInMe = user.fire( ai_brd, coords_u);

			// smart shooting -> if previous shot was Hit then shoot at one of the neighbour tiles
			if (i>0 && checkInPC) {
					neighbour = ai_brd.getAdjacentTiles( ai_brd.getBrd()[coords_pc[0]][coords_pc[1]] );
					 int tmp = std::rand() / ((RAND_MAX + 1u) / 4);
					 cout << "Toso" << tmp;
					 coords_pc = neighbour[tmp].getCoord();
			}
			else {
				// pc random input x,y coordinates
				coords_pc = getRandInput();
			}
			// pc fire
			checkInPC = ai.fire( u_brd, coords_pc);

			drawboards( u_brd, ai_brd);
			i++;
		}

		if (ai_brd.allShipsSunk())
			printf("\nCongratulations. You Won ! \n");
		else
			printf("\nPC Won. Sweep your tears. \n");

		printf("\nYour stats are the below : \n");
		user.getStats();
		printf("\n\nOpponent's stats are the below : \n");
		ai.getStats();

	
    return 0;

}

