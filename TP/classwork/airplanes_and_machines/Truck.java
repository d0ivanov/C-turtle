package c13;

public class Truck extends Vehicle {

	public void move(int x, int y){
		x += 14;
		y += 12;
		super.move(x, y);
	}
}

class Truck1 {
	
}