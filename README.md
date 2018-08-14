# Battleship_Game
C++ &amp; Java version of Battleship Game

Battle Game implementation both on C++ and Java. The user plays against the PC as opponent. The game ends when either the user's ships or the PC's ships get sinked. 

The program includes the following classes:

  - Tile Class: describes each cell of the board where the ships of each player are placed on. Includes as variable members the                   coordinates of the cell and the type, that is one of the sea, ship, hit or miss enumeration types. Also includes a draw() function where the symbol of the cell type is printed.
  
  - Ship Class: is an abstract class that describes each ship type. Includes as variable members the starting cell on the board, the orientation (vertically or horizontally) and the length of the ship. Ship class is the base class from whom inherit stuff the subclasses:
      - Carrier Subclass(5 cells length ship), 
      - Battleship Subclass(4 cells length ship), 
      - Cruiser Subclass(3 cells length ship), 
      - Submarine Subclass(3 cells length ship) and 
      - Destroyer Subclass(2 cells length ship). 
      
      Also, placeShip() function is included but implemented on each subclass (polymorphism). This function places each ship on the board from the respective starting cell, considering the length of the ship) and the orientation of placement of the ship. 
  
  - Board Class: describes a 10x10 2D matrix of (tile class) cells. Includes the functions drawboards() - prints the 2 boards every time a ship is placed or every time a shot is thrown (obviously the PCs board prints only hit/miss cells and not where the ships are placed), getAdjacentTiles() - returns the neighborhood of a cell, placeAllShips() - creates and places all the ships in a random manner considering the on-board placement limitations, allShipsSunk() - checks if all ships of a player have been sunk, that is there is no type ship cell on the board (if true is returned the game ends). 
  
  - Player Class: two objects are created, one for each player. Includes diagnostic variables such as hit shots, missed shots etc. The function of this class are placeAllShips() function - calls player boards placeAllShip(), placeShip() function - calls placeShip() of Ship Class and places the ship, fire() function - fires a shot on the opponent's board and brings up to date diagnostics counters, getStats() function which returns the diagnostics.
  
  - Main (main() in Battleship.cpp file and Battleship.java class for C++ and Java respectively): the two players are created and the PCs ships are placed randomly. The program asks the user if he wants to place the ships randomly or manually one by one.  
Drawboards() function is called after ships placement. Then, in a while loop of allsShipsSunk() function condition, that is while at least one ship of both players is "alive", the following are implemented: 
      - a shot is fired at user chosen coordinates,
      - a shot is fired at pc's randomly chosen coordinates (if previously a hit shot was fired then PC is going to fire at the neighborhood cells),
      - the two boards are printed.
  
  More specific instructions on how to use, are included on Cpp_Version and Java_Version subfolders respectively. 
  
  
  
  
  
