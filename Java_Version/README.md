## Java Version of Battleship Game

Implemented on Eclipse IDE 4.7.2

Here is described the implementation of the Java version of Battleship game, with all the classes that are described on Battleship_Game/README.md file. 

User player object is named as "U" and PC player object is named as "Digital_Mind". 

Here, the game flow is described step by step through screenshots :

As a welcome image the user sees the following :

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Java_Version/battleship_0.png)

So initially, the following are printed if the user chooses to randomly place the ships:

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Java_Version/battleship_1.png)

...or the following if the user decides to place the ships one by one:

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Java_Version/battleship_1b.png)

Then the program in a while loop asks the user to give the shot coordinates, while the PC shots randomly unless the previous shot was a hit (so the PC shots at the neighborhood of the previous hit shot). After both players have shot, the 2 refreshed boards are printed.

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Java_Version/battleship_2.png)

Finally, when one of the two players loose all the ships, the program ends and the diagnostics of both players are printed as shown below:

![](https://raw.githubusercontent.com/nikos-rvnt/Battleship_Game/master/Java_Version/battleship_3.png)


