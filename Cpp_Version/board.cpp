#include "stdafx.h"
#include "board.h"
#include <iostream>

Board::Board() {

	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->length; j++) {
			brd_mat[i][j] = Tile(i, j, sea);
		}
	}

	++cntHide;
	if (cntHide == 1)
		hidden = false;
	else
		hidden = true;
}

void drawboards( Board brd1, Board brd2) {
	printf("\n\n");
	printf("\n - - - - - - - - - - - U - - - - - - - - - - - \n");
	printf("\n\t   ");
	for (int j = 0; j < brd1.getLength(); j++) {
		printf("%d ", j);
	}
	for (int i = 0; i < brd1.getLength(); i++) {
		printf("\n\t %d ", i);
		for (int j = 0; j < brd1.getLength(); j++) {
			brd1.getBrd()[i][j].draw();
			printf(" ");
		}
	}

	printf("\n");
	printf("\n\n - - - - - - - - - - - PC - - - - - - - - - - -\n");
	printf("\n\t   ");
	for (int j = 0; j < brd1.getLength(); j++) {
		printf("%d ", j);
	}
	for (int ii = 0; ii < brd2.getLength(); ii++) {
		printf("\n\t %d ", ii);
		for (int jj = 0; jj < brd2.getLength(); jj++) {
			/*if(brd2.hidden == true && brd2.getBrd()[ii][jj].getType() == 1)
				std::cout << "~";
			else*/
				brd2.getBrd()[ii][jj].draw();
			printf(" ");
		}
	}
	printf("\n\n\n");
}

std::vector< std::vector<Tile>> Board::getBrd() {
	return this->brd_mat;
}

int Board::getLength() {
	return length;
}

std::vector<Tile> Board::getAdjacentTiles(Tile t) {
	// neighbour tiles
	std::vector<Tile> neighbour;
	std::vector<int> coords = t.getCoord();
	
	// upmost row
	if (coords[0] == 0) {
		// leftmost column
		if (coords[1] == 0) {
			neighbour.push_back(brd_mat[0][1]);
			neighbour.push_back(brd_mat[1][0]);
		}
		// rightmost column
		else if (coords[1] == (length - 1)) {
			neighbour.push_back(brd_mat[0][6]);
			neighbour.push_back(brd_mat[1][7]);
		}
		// in between
		else {
			neighbour.push_back(brd_mat[coords[0]][coords[1] + 1]);
			neighbour.push_back(brd_mat[coords[0]+1][coords[1]]);
			neighbour.push_back(brd_mat[coords[0]][coords[1] - 1]);
		}	
	} // downmost row
	else if (coords[0] == (length - 1)) {
		// leftmost column
		if (coords[1] == 0) {
			neighbour.push_back(brd_mat[coords[0]][coords[1]+1]);
			neighbour.push_back(brd_mat[coords[0]-1][coords[1]]);
		}
		// rightmost column
		else if (coords[1] == (length - 1)) {
			neighbour.push_back(brd_mat[coords[0]-1][coords[1]]);
			neighbour.push_back(brd_mat[coords[0]][coords[1]-1]);
		}
		// in between
		else {
			neighbour.push_back(brd_mat[coords[0]][coords[1] + 1]);
			neighbour.push_back(brd_mat[coords[0]-1][coords[1]]);
			neighbour.push_back(brd_mat[coords[0]][coords[1] - 1]);
		}
	} // leftmost column
	else if (coords[1] == 0) {
		// upmost row 
		if (coords[0] == 0) {
			neighbour.push_back(brd_mat[coords[0]][coords[1] + 1]);
			neighbour.push_back(brd_mat[coords[0] + 1][coords[1]]);
		}
		// downmost row
		else if (coords[0] == (length - 1)) {
			neighbour.push_back(brd_mat[coords[0] - 1][coords[1]]);
			neighbour.push_back(brd_mat[coords[0]][coords[1] + 1]);
		}
		// in between
		else {
			neighbour.push_back(brd_mat[coords[0]][coords[1] + 1]);
			neighbour.push_back(brd_mat[coords[0] - 1][coords[1]]);
			neighbour.push_back(brd_mat[coords[0]][coords[1] - 1]);
		}
	} // rightmost column
	else if (coords[1] == (length - 1)) {
		// upmost row
		if (coords[0] == 0) {
			neighbour.push_back(brd_mat[coords[0]][coords[1] - 1]);
			neighbour.push_back(brd_mat[coords[0] + 1][coords[1]]);
		}
		// downmost row
		else if (coords[0] == (length - 1)) {
			neighbour.push_back(brd_mat[coords[0] - 1][coords[1]]);
			neighbour.push_back(brd_mat[coords[0]][coords[1] - 1]);
		}
		// in between
		else {
			neighbour.push_back(brd_mat[coords[0]][coords[1] + 1]);
			neighbour.push_back(brd_mat[coords[0] - 1][coords[1]]);
			neighbour.push_back(brd_mat[coords[0]][coords[1] - 1]);
		}
	} 
	else {
		neighbour.push_back(brd_mat[coords[0]][coords[1] + 1]);
		neighbour.push_back(brd_mat[coords[0] + 1][coords[1]]);
		neighbour.push_back(brd_mat[coords[0]][coords[1] - 1]);
		neighbour.push_back(brd_mat[coords[0] - 1][coords[1]]);
	}

	return neighbour;
}

void Board::placeAllShips() {

}

void Board::setBrd(int inx, int iny, sea_type seat) {
	this->brd_mat[inx][iny].setType(seat);
}


bool Board::allShipsSunk() {
	bool check = false;
	int num_tiles = (length*length);

	int cnt_non_ship = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (brd_mat[i][j].getType() != ship)
				cnt_non_ship++;
		}
	}

	if (cnt_non_ship == num_tiles)
		check = true;

	return check;
}

