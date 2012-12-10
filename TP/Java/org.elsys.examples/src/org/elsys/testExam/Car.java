package org.elsys.testExam;

public class Car extends Vehicle {

	public Car(int plate, Coordinate coord) {
		regPlate = plate;
		position = coord; 
	}
	
	@Override
	public void load(int payLoad) {
		if(payLoad + this.payLoad > 1) {
			System.out.println("Cannot load more than a ton!");
			return;
		}
		super.load(payLoad);
	}
}
