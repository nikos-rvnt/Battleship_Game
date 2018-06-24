#ifndef PLAYER_H
#define PLAYER_H

#include "tile.h"
#include "ship.h"
#include "board.h"

class Player
{

private:
	//std::string name;
	char* name;
	int shots ;
	int missed_shots ;
	int hit_shots ;
	int repeated_shots ;

public:
	void setName(char* s1);
	void placeAllShips(Board &br);
	bool placeShip(Ship* sh, Tile coord, orientation ornt, Board &br);
	//void placeShip(Ship* sh, Tile coord, orientation ornt, std::vector< std::vector<Tile>> &br);
	//void fire(std::vector< std::vector<Tile>> brd, std::vector<int> coord);
	bool fire( Board &brd, std::vector<int> coord);
	void getStats();
	void statsInit();
};

#endif