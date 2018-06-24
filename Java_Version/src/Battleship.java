import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random; 


public class Battleship {

	
	public static void main(String[] args) {
		
		Scanner reader = new Scanner(System.in);
		
		Player user = new Player("u");
		Player ai = new Player("digital_mind");

		Board u_brd = new Board();
		Board ai_brd = new Board();
		
		drawboards( u_brd, ai_brd);
		
		orientation ornta;
		//int cx, cy;
		List<Integer> coords_u = new ArrayList<Integer>();
		List<Integer> coords_pc = new ArrayList<Integer>();
		ai.placeAllShips(ai_brd);

		System.out.println("\n\n Do you want to place the ships randomly ? (Y or y for Yes // N or n for No)");
		boolean resu;
		int times;
		
		if (randomPlace(reader)) {
			user.placeAllShips(u_brd);
		}
		else {
			System.out.println(" So you desire to place each ship manually giving the coordinates and the orientation.");

			for (int i = 0; i < 5; i++) {
				List<Integer> cords = new ArrayList<Integer>();

					if (i == 0){
						times = 0;
						System.out.println("\n 1st Ship, a Carrier.");
						ornta = getOrientation(reader);
						
						System.out.println("Now, give the coordinates x,y to place the Carrier : \n");
						do {
							if(times>0)
								System.out.println("Please, give proper coordinates: ");
							cords = getInput(reader);

							Ship cr = new Carrier( u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), ornta);
						
							resu = user.placeShip( cr, u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), cr.getOrient(), u_brd);
							times++;
						}while(resu==false);
							
						drawboards( u_brd, ai_brd);

					}
					if (i == 1) {
						System.out.println("\n 2nd Ship, a Battleship.");
						ornta = getOrientation(reader);
						times = 0;
						System.out.println("Now, give the coordinates x,y to place the Battleship : \n");
						
						do {
							if(times>0)
								System.out.println("Please, give proper coordinates");
							cords = getInput(reader);
						
							Ship bs = new BattleS( u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), ornta);
						
							resu = user.placeShip( bs, u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), bs.getOrient(), u_brd);
							times++;
						}while(resu==false);
							
						drawboards(u_brd, ai_brd);

					}
					if (i == 2) {
						
						System.out.println("\n 3rd Ship, a Cruiser.");
						ornta = getOrientation(reader);
						times = 0;
						System.out.println("Now, give the coordinates x,y to place the Cruiser : \n");
						
						do {
							if(times>0)
								System.out.println("Please, give proper coordinates: ");
							cords = getInput(reader);

							Ship cru = new Cruiser(u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), ornta);

							resu = user.placeShip( cru, u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), cru.getOrient(), u_brd);
							times++;
						}while(resu==false);
						drawboards(u_brd, ai_brd);

					}
					if (i == 3) {
						times = 0;
						System.out.println("\n 4rd Ship, a Submarine.");
						ornta = getOrientation(reader);

						System.out.println("Now, give the coordinates x,y to place the Submarine : \n");
						do {	
							if(times>0)
								System.out.println("Please, give proper coordinates: ");
							cords = getInput(reader);
							Ship sm = new Submarine( u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), ornta);

							resu = user.placeShip( sm, u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), sm.getOrient(), u_brd);
							times++;
						}while(resu==false);
						
						drawboards(u_brd, ai_brd);

					}
					if (i == 4) {
						times = 0;	
						System.out.println("\n 5th Ship, a Destroyer. ");
						ornta = getOrientation(reader);

						System.out.println("Now, give the coordinates x,y to place the Destroyer : \n");
						do {
							if(times>0)
								System.out.println("Please, give proper coordinates:");
							cords = getInput(reader);

							Ship ds = new Destroyer( u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), ornta);

							resu = user.placeShip( ds, u_brd.getBrd().get(cords.get(0)).get(cords.get(1)), ds.getOrient(), u_brd);
							times++;
						}while(resu==false);
						drawboards(u_brd, ai_brd);

					}
			}
		}
		
			drawboards( u_brd, ai_brd);
			
			user.statsInit();
			ai.statsInit();
			int i = 0;
			List<Tile> neighbour = new ArrayList<Tile>(4);
			boolean checkPC = false, checkMe;
			Random rand = new Random();

			while (!u_brd.allShipsSunk() && !ai_brd.allShipsSunk()) {
				
				// user input x, y coordinates
				System.out.println("\n Give the coordinates x,y where you want to fire : \n");
				coords_u = getInput(reader);
				// user fire
				checkMe = user.fire( ai_brd, coords_u);

				// pc random input x,y coordinates
				coords_pc = getRandInput();
				
				// smart shooting -> if previous shot was Hit then shoot at one of the neighbour tiles
				if (i>0 && checkPC) {
						neighbour = ai_brd.getAdjacentTiles( ai_brd.getBrd().get(coords_pc.get(0)).get(coords_pc.get(1)) );
						 int tmp = rand.nextInt(4) + 0;
						 //cout << "Toso" << tmp;
						 coords_pc = neighbour.get(tmp).getCoord();
				}
				else {
					// pc random input x,y coordinates
					coords_pc = getRandInput();
				}
				
				// pc fire
				checkPC = ai.fire( u_brd, coords_pc);

				drawboards( u_brd, ai_brd);
				i++;
			}
			if (ai_brd.allShipsSunk())
				System.out.println("\n Congratulations. You Won ! ");
			else
				System.out.println("\n PC Won. Sweep your tears. ");

			System.out.println("\n Your stats are the below : \n");
			user.getStats();
			System.out.println("\n Opponent's stats are the below : \n");
			ai.getStats();

		
		reader.close();
		
	}


	public static List<Integer> getInput(Scanner sc1) {
		
		List<Integer> crd = new ArrayList<Integer>();
		
//		Scanner sc1 = null;
	//	try {
	//	    sc1 = new Scanner(System.in);
		    		
		    int xx = sc1.nextInt();
		    int yy = sc1.nextInt();
		
		    crd.add(xx);
		    crd.add(yy);

		return(crd);
	}

	public static List<Integer> getRandInput() {
		
		List<Integer> crd = new ArrayList<Integer>();
		
		Random rand = new Random();
		int xx = rand.nextInt(8) + 0;
		int yy = rand.nextInt(8) + 0;
		
		crd.add(xx);
		crd.add(yy);

		return(crd);
	}

	public static orientation getOrientation(Scanner sc2) {
		orientation orient;
		
		System.out.println( "Do you want to place it vertically or horizontally ? (V or v for vertically // H or h for horizontally) " );
		
		//Scanner sc2 = null;
    	orient = orientation.horizontal;

		//try {
		    //sc2 = new Scanner(System.in);
		    String anser_ornt = sc2.next();
		
		    if (anser_ornt.charAt(0) == 'V' || anser_ornt.charAt(0) == 'v') {
		    	orient = orientation.vertical;
			    return orient;

		    }
		    else if (anser_ornt.charAt(0) == 'H' || anser_ornt.charAt(0) == 'h') {
		    	orient = orientation.horizontal;
			    return orient;

		    }
		    
		    return orient;

		    
	}

	public static boolean randomPlace(Scanner sc) {
		
		//Scanner sc = null;
		//try {
		    //sc = new Scanner(System.in);
		    char anser = sc.next().charAt(0);
		
		    if (anser == 'Y' || anser == 'y')
		    	return true;
		    else
		    	return false;
	
		//}

	}
	
	public static void drawboards( Board brd1, Board brd2) {

		System.out.println("\n - - - - - - - - - - U - - - - - - - - ");
		System.out.print("\t   ");
		for (int j = 0; j < brd1.getLength(); j++) {
			System.out.print(" " + j);
		}
		for (int i = 0; i < brd1.getLength(); i++) {
			System.out.print("\n\t   " + i);
			for (int j = 0; j < brd1.getLength(); j++) {
				brd1.getBrd().get(i).get(j).draw();
				System.out.print(" ");
			}
		}
		System.out.println("\n");
		System.out.println("  - - - - - - - - - PC - - - - - - - -");
		System.out.print("\t   ");
		for (int j = 0; j < brd1.getLength(); j++) {
			System.out.print(" "+ j);
		}
		for (int ii = 0; ii < brd2.getLength(); ii++) {
			System.out.print("\n\t   "+ ii);
			for (int jj = 0; jj < brd2.getLength(); jj++) {
				//brd2.getBrd().get(ii).get(jj).setType(sea_type.sea);
				if(brd2.getHide() == true && brd2.getBrd().get(ii).get(jj).getType() == sea_type.ship)
					System.out.print("~");
				else
					brd2.getBrd().get(ii).get(jj).draw();
				System.out.print(" ");
			}
		}
		System.out.println("\n");
	}
	
}
