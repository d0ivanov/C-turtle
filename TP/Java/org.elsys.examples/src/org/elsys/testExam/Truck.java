package org.elsys.testExam;

public class Truck extends Vehicle {
	
	private int payLoad;
	
	public Truck(int plate, Coordinate coord) {
		regPlate = plate;
		position = coord;
	}
	
	@Override
	public void load(int payLoad) {
		if(payLoad + this.payLoad > 10) {
			System.out.println("Cannot load more than a ton!");
			return;
		}
		super.load(payLoad);
	}
}
