
## C++ Version of Battleship Game

Implemented on Visual Studio 2017

Here is described the implementation of the C++ version of Battleship game, with all the classes that are described on Battleship_Game/README.md file. 

User player object is named as "U" and PC player object is named as "Digital_Mind". 

Here the game flow is described step by step through screenshots :

So initially, the following are printed if the user chooses to randomly place the ships:

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Cpp_Version/battleship_1a.png)

...or the following if the user decides to place the ships one by one:

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Cpp_Version/battleship_1bb.png)

Then the program in a while loop asks the user to give the shot coordinates, while the PC shots randomly unless the previous shot was a hit (so the PC shots at the neighborhood of the previous hit shot). After both players have shot, the 2 refreshed boards are printed.

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Cpp_Version/battleship_2a.png)

Finally, when one of the two players loose all the ships, the program ends and the diagnostics of both players are printed as shown below:

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Cpp_Version/battleship_3.png)

