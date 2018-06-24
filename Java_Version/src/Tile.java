import java.util.List;
import java.util.ArrayList;

enum sea_type { sea, ship, hit, miss};

public class Tile {

	
	private	int coord_x;
	private int coord_y;
	private sea_type type;
	
	public Tile() {
		
	};
	
	public Tile( int coo_x, int coo_y, sea_type typ) {
		this.coord_x = coo_x;
		this.coord_y = coo_y;
		this.type = type;
	};
	
	public List<Integer> getCoord(){
		List<Integer> cords = new ArrayList<Integer>();
	    cords.add(this.coord_x);
	    cords.add(this.coord_y);
	 
	    return(cords);
	};
	
	public void setCoord( int xx, int yy) {
		this.coord_x = xx;
		this.coord_y = yy;
	};
	
	public sea_type getType() {
		return this.type;
	};
	
	public void setType(sea_type type) {
		this.type = type;
	};
	
	public void draw() {
		
		if( this.type == sea_type.sea) {
				System.out.print("~");
				//break;
		}
		else if( this.type == sea_type.ship) {
				System.out.print("s");
				//break;
		}
		else if( this.type == sea_type.hit) {
				System.out.print("X");
				//break;
		}
		else if( this.type == sea_type.miss) {
				System.out.print("o");
				//break;
		}
	}
	
}



