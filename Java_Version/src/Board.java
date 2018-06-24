import java.util.List;
import java.util.ArrayList;

public class Board {
	private int length = 10;
	private	List< List < Tile > > brd_mat = new ArrayList< List < Tile > >(length);
	private	boolean hidden;
	private static int cntHide = 0 ;
	
	public Board() {

		for (int i = 0; i < this.length; i++) {
			brd_mat.add(new ArrayList<Tile>());
		    for (int j = 0; j<this.length; j++){
		        Tile til = new Tile( i, j, sea_type.sea);
		        brd_mat.get(i).add(til);
		        brd_mat.get(i).get(j).setType(sea_type.sea); //add(til);

		    }
		}
		++cntHide;
		if (cntHide == 1)
			hidden = false;
		else
			hidden = true;
	}
	
	public boolean getHide() {
		return this.hidden;
	}
	
	public List< List<Tile>> getBrd(){
	
		return this.brd_mat;
	}
	
	public int getLength() {
		return this.length;
	}
	
	public void setBrd( int inx, int iny, sea_type typ) {
		Tile ti = new Tile( inx, iny, typ);
		this.brd_mat.get(inx).get( iny).setType( typ );
	}


	public ArrayList<Tile> getAdjacentTiles(Tile t){
		
		// neighbour tiles
		ArrayList<Tile> neighbour = new ArrayList<Tile>();
		List<Integer> coords = t.getCoord();
		
		// upmost row
		if (coords.get(0) == 0) {
			// leftmost column
			if (coords.get(1) == 0) {
				neighbour.add( brd_mat.get(0).get(1) );
				neighbour.add( brd_mat.get(1).get(0) );
			}
			// rightmost column
			else if (coords.get(1) == (length - 1)) {
				neighbour.add( brd_mat.get(0).get(6) );
				neighbour.add( brd_mat.get(1).get(7) );
			}
			// in between
			else {
				neighbour.add( brd_mat.get( coords.get(0) ).get( coords.get(1)+1 )) ;
				neighbour.add( brd_mat.get( coords.get(0)+1).get( coords.get(1) )) ;
				neighbour.add( brd_mat.get( coords.get(0) ).get( coords.get(1)-1 ) ) ;
			}	
		} // downmost row
		else if (coords.get(0) == (length - 1)) {
			// leftmost column
			if (coords.get(1) == 0) {
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)+1) );
				neighbour.add( brd_mat.get( coords.get(0)-1 ).get(coords.get(1)) );
			}
			// rightmost column
			else if (coords.get(1) == (length - 1)) {
				neighbour.add( brd_mat.get( coords.get(0)-1 ).get( coords.get(1) ) );
				neighbour.add( brd_mat.get( coords.get(0) ).get(coords.get(1)-1) );
			}
			// in between
			else {
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)+1) ); 	
				neighbour.add( brd_mat.get(coords.get(0)-1).get(coords.get(1)) );
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)-1) );
			}
		} // leftmost column
		else if (coords.get(1) == 0) {
			// upmost row 
			if (coords.get(0) == 0) {
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)+1) );
				neighbour.add( brd_mat.get(coords.get(0)+1).get(coords.get(1)+1) );
			}
			// downmost row
			else if (coords.get(0) == (length - 1)) {
				neighbour.add( brd_mat.get(coords.get(0)-1).get(coords.get(1)) );
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)+1) );
			}
			// in between
			else {
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)+1) );
				neighbour.add( brd_mat.get(coords.get(0)-1).get(coords.get(1)) );
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)-1) );
			}
		} // rightmost column
		else if (coords.get(1) == (length - 1)) {
			// upmost row
			if (coords.get(0) == 0) {
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)-1) );
				neighbour.add( brd_mat.get(coords.get(0)+1).get(coords.get(1)) );
			}
			// downmost row
			else if (coords.get(0) == (length - 1)) {
				neighbour.add( brd_mat.get(coords.get(0)-1).get(coords.get(1)) );
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)-1) );

			}
			// in between
			else {
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)+1) );
				neighbour.add( brd_mat.get(coords.get(0)-1).get(coords.get(1)) );
				neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)-1) );

			}
		} 
		else {
			neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)+1) );
			neighbour.add( brd_mat.get(coords.get(0)+1).get(coords.get(1)) );
			neighbour.add( brd_mat.get(coords.get(0)).get(coords.get(1)-1) );
			neighbour.add( brd_mat.get(coords.get(0)-1).get(coords.get(1)) );
			
		}

	    return(neighbour);
	}
	
	public void placeAllShips() {
		
	}
	
	public boolean allShipsSunk() {

		boolean check = false;
		int num_tiles = (length*length);

		int cnt_non_ship = 0;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (brd_mat.get(i).get(j).getType() != sea_type.ship)
					cnt_non_ship++;
			}
		}

		if (cnt_non_ship == num_tiles)
			check = true;

		return check;
	}


}

