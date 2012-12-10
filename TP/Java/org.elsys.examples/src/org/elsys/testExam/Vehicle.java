package org.elsys.testExam;

public class Vehicle {

	protected Coordinate position;
	protected int regPlate;
	protected int payLoad;
	
	public Coordinate getPosition() {
		return position;
	}

	public void setPosition(Coordinate position) {
		this.position = position;
	}
	
	public int getRegPlate() {
		return regPlate;
	}

	public void setRegPlate(int regPlate) {
		this.regPlate = regPlate;
	}
	
	public int getPayLoad() {
		return payLoad;
	}

	public void load(int payLoad) {
		this.payLoad = payLoad;
	}

	public void print() {
		System.out.println("CAR: " + regPlate + " ");
		position.dump();
	}
}
