import java.util.List;
import java.util.ArrayList;

public class BattleS extends Ship{

	private int size;
	
	/*public BattleS(){
		// TODO Auto-generated constructor stub
	}*/
	
	public BattleS( Tile start_index, orientation ornt){
		super( start_index, ornt);
		this.size = 4;
	}
	
	@Override
	public boolean placeShip(Tile start_index, orientation ornt, Board brd) {
		
		
		List<Integer> st_coord = start_index.getCoord();
		
		boolean place = checkLmt( st_coord, ornt, brd, 4);
		//boolean place = true;
		
		if (place == true) {
			// vertical placement
			if (ornt == orientation.vertical) {
				for (int i = st_coord.get(0); i < (st_coord.get(0) + 4); i++) {
					brd.setBrd( i, st_coord.get(1), sea_type.ship);
					//brd.getBrd()[i][st_coord[1]].setType(ship);
				}
			}
			// horizontal placement
			else {
				for (int i = st_coord.get(1); i < (st_coord.get(1) + 4); i++) {
					brd.setBrd( st_coord.get(0), i, sea_type.ship);
					//System.out.println( brd.getBrd().get(i).get(st_coord.get(1)).getType());
				}
				
			}
			System.out.println("A Battleship was created !");
			return true;
		}
		else {
			System.out.println("Limitations were not satisfied !");
			return false;
		}

		
	}

}

