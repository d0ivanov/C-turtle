package c13;

public class Vehicle extends Machine {

	public int x = 0;
	public int y = 0;
	
	public void move(int x, int y){
		this.x += x;
		this.y += y;
	}
}
