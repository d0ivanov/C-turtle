package c13;

public class Airplane extends Vehicle {

	int x = 0;
	int y = 0;

	public void move(int x, int y) {
		this.x += x;
		this.y += y;
	}

	public void moveWings() {

	}
}
