import java.util.List;
import java.util.ArrayList;

enum orientation { horizontal, vertical};

public abstract class Ship {
	private Tile start_index;
	private	orientation ornt;

	public Ship() {
		
	}
	
	public Ship(Tile start_index, orientation ornt) {
		this.start_index = start_index;
		this.ornt = ornt;
	}
	
	public orientation getOrient() {
		return this.ornt;
	}
	
	//public abstract boolean placeShip( Tile start_index, orientation ornt, Board &brd) ;	
	public abstract boolean placeShip(Tile start_index, orientation ornt, Board brd) ;	
	
	public boolean checkLmt( List<Integer> st_coord, orientation ornt, Board brd, int size) {

			List< List<Tile>> brdm = brd.getBrd();
			
			boolean check = true;

			// check horizontally placing
			if (ornt == orientation.horizontal) {
				// check if out of border limits
				if ((st_coord.get(1) + size) <= brd.getLength()) {
					for (int i = st_coord.get(1); i < (st_coord.get(1) + size); i++) {	
						// check if another ship already exists
						if (brdm.get(st_coord.get(0)).get(i).getType() == sea_type.ship) {
							check = false;
							break;
						}
						
		 				// check if the ship touches another one already existing in a neighbour tile in front or back
						if (i==st_coord.get(1) && st_coord.get(1)!=0) {
							if (brd.getBrd().get( st_coord.get(0) ).get( st_coord.get(1) ).getType() == sea_type.ship) {
								check = false;
								break;
							}
						}
						
						// check if the ship touches another one already existing in a neighbour tile above or down
						if ( st_coord.get(0) < (brd.getLength()-1) ) {
							if ( brd.getBrd().get( st_coord.get(0)+1 ).get(i).getType() == sea_type.ship ) {
								check = false;
								break;
							}
						}
						
						if( st_coord.get(0) > 0 ) {
							if ( brd.getBrd().get( st_coord.get(0)-1 ).get(i).getType() == sea_type.ship ) {
								check = false;
								break;
							}
						}

					}
					
					if ((st_coord.get(1) + size) < brd.getLength()) {
						if (brd.getBrd().get(st_coord.get(0)).get(st_coord.get(1)+size).getType() == sea_type.ship){
							check = false;
						}
					}
				}
				else {
					check = false;
					//throw new OversizeException("Ship ending coordinates out of board !");
					
				}
				
				
			}
			// check vertically placing
			else {
				if ((st_coord.get(0) + size) <= brd.getLength()) {
					for (int i = st_coord.get(0); i < (st_coord.get(0) + size); i++) {
						// check if another ship already exists
						if (brd.getBrd().get(i).get(st_coord.get(1)).getType() == sea_type.ship) {
							check = false;
							break;
						}
						//

						// check if the ship touches another one already existing in a neighbour tile above
						if (i == st_coord.get(0) && st_coord.get(0) != 0) {
							if (brd.getBrd().get(st_coord.get(0)-1).get(st_coord.get(1)).getType() == sea_type.ship) {
								check = false;
								break;
							}
						}
						// check if the ship touches another one already existing in a neighbour tile in front
						if (st_coord.get(1) < (brd.getLength()-1)) {
							if ( brd.getBrd().get(i).get(st_coord.get(1)+1).getType() == sea_type.ship ) {
								check = false;
								break;
							}
							
						}
						// check if the ship touches another one already existing in a neighbour tile backside
						if (st_coord.get(1) > 0) {
							if ( brd.getBrd().get(i).get(st_coord.get(1)-1).getType() == sea_type.ship ) {
								check = false;
								break;
							}
						}
										
					}
					if ((st_coord.get(0) + size) < brd.getLength()) {
						if (brd.getBrd().get( st_coord.get(0) + size ).get( st_coord.get(1)).getType() == sea_type.ship)
							check = false;
						//break;
					}
					
				}
				else {
					check = false;
				}
			}
			
			return check;
	}
	
}
