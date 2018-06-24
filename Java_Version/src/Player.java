import java.util.List;
import java.util.Random;
import java.util.ArrayList;

public class Player {

	private int shots = 0;
	private int missed_shots = 0;
	private int hit_shots = 0;
	private int repeated_shots = 0;

	private String name;
	
	public Player(String name) {
		this.name = name;
	}

	public void placeAllShips(Board br) {

		orientation orien;
		int ori, xi = 0, yi = 0;
		List< Integer > crds = new ArrayList< Integer >(2);
		crds.add(0);
		crds.add(1);
		
		boolean plc;

		Random rand = new Random();
		
		for (int i = 1; i <= 5; i++) {
			
			ori = 0;
			if (i == 1) {
				do{
					
					ori = rand.nextInt(2) + 0;
					if (ori == 1)
						orien = orientation.vertical;
					else
						orien = orientation.horizontal;

					xi = rand.nextInt(br.getLength()) + 0;
					//System.out.print("AAA"+xi+"AAA");
					yi = rand.nextInt(br.getLength()) + 0;
					crds.set(0,xi);
					crds.set(1,yi);

					Ship cr = new Carrier(br.getBrd().get(xi).get(yi), orien);
					plc = placeShip(cr, br.getBrd().get(xi).get(yi), cr.getOrient(), br);
				} while (plc==false);
			}
			else if (i == 2) {
				do {
					
					ori = rand.nextInt(2) + 0;
					if (ori == 1)
						orien = orientation.vertical;
					else
						orien = orientation.horizontal;

					xi = rand.nextInt(br.getLength()) + 0;
					yi = rand.nextInt(br.getLength()) + 0;
					
					crds.set(0,xi);
					crds.set(1,yi);

					BattleS bs = new BattleS(br.getBrd().get(xi).get(yi), orien);
					plc = placeShip(bs, br.getBrd().get(xi).get(yi), bs.getOrient(), br);
				} while (plc==false);
			}
			else if (i == 3) {
				do {

					ori = rand.nextInt(2) + 0;
					if (ori == 1)
						orien = orientation.vertical;
					else
						orien = orientation.horizontal;

					xi = rand.nextInt(br.getLength()) + 0;
					yi = rand.nextInt(br.getLength()) + 0;
					crds.set(0,xi);
					crds.set(1,yi);

					Ship cu = new Cruiser(br.getBrd().get(xi).get(yi), orien);
					plc = placeShip(cu, br.getBrd().get(xi).get(yi), cu.getOrient(), br);
				} while (plc==false);
			}
			else if (i == 4) {
				do {
					
					ori = rand.nextInt(2) + 0;
					if (ori == 1)
						orien = orientation.vertical;
					else
						orien = orientation.horizontal;

					xi = rand.nextInt(br.getLength()) + 0;
					yi = rand.nextInt(br.getLength()) + 0;
					crds.set(0,xi);
					crds.set(1,yi);

					Ship ds = new Destroyer(br.getBrd().get(xi).get(yi), orien);
					plc = placeShip(ds, br.getBrd().get(xi).get(yi), ds.getOrient(), br);
				} while (plc==false);
			}
			else if (i == 5) {
				do {

					ori = rand.nextInt(2) + 0;
					if (ori == 1)
						orien = orientation.vertical;
					else
						orien = orientation.horizontal;

					xi = rand.nextInt(br.getLength()) + 0;
					yi = rand.nextInt(br.getLength()) + 0;
					crds.set(0,xi);
					crds.set(1,yi);

					Ship sm = new Submarine(br.getBrd().get(xi).get(yi), orien);
					plc = placeShip(sm, br.getBrd().get(xi).get(yi), sm.getOrient(), br);
				} while (plc==false);
			}
		}
	}
	
	
	public boolean placeShip( Ship sh, Tile coord, orientation ornt, Board br) {
	
		//System.out.println("aaa21aaa");
		boolean res = sh.placeShip( coord, ornt, br);
		//System.out.println( "fffff" );
	
		return res;
	}

	public void statsInit() {
		this.hit_shots = 0;
		this.missed_shots = 0;
		this.repeated_shots = 0;
		this.shots = 0;
	}

	public void getStats() {
		System.out.println("Player "+ this.name +" has: \n\t "+ this.hit_shots +" / "+ this.shots +" hit shots !");
		System.out.println("\n\t "+ this.missed_shots + " / " + this.shots + " missed shots !");
		System.out.println(" \n\t and " + this.repeated_shots + " / " + this.shots + " repeated shots ! \n" );
	}
	
	public boolean fire( Board brd, List<Integer> coord) {

		boolean check = false;
		
		sea_type target = brd.getBrd().get( coord.get(0) ).get( coord.get(1) ).getType();
		// hit
		if (target == sea_type.ship) {
			this.shots++;
			this.hit_shots++;
			brd.setBrd( coord.get(0), coord.get(1), sea_type.hit);
			System.out.println(" * Hit ! * ");
			check = true;
		}
		// already hit
		else if (target == sea_type.hit) {
			this.shots++;
			this.repeated_shots++;
			brd.setBrd( coord.get(0), coord.get(1), sea_type.hit); //brd[coord[0]][coord[1]].setType(hit);
			System.out.println(" * Already Hit ! * ");
			check = true;
		}
		// already miss
		else if (target == sea_type.miss) {
			this.shots++;
			this.repeated_shots++;
			brd.setBrd(coord.get(0), coord.get(1), sea_type.miss); //brd[coord[0]][coord[1]].setType(hit);
			System.out.println(" * Already Miss ! * ");
		}
		// miss
		else if (target == sea_type.sea) {
			this.shots++;
			this.missed_shots++;
			brd.setBrd(coord.get(0), coord.get(1), sea_type.miss); //brd[coord[0]][coord[1]].setType(miss);
			System.out.println(" * Miss ! * ");
		}
		
		return check;
	}
	
	
}

