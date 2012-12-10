package org.elsys.testExam;

public class Vehicle {

	protected Coordinate position;
	protected int registration;
	protected int load = 0;
	
	public Coordinate getPosition() {
		return position;
	}
	
	public void setPosition(Coordinate position) {
		this.position = position;
	}
	
	public int getRegistration() {
		return registration;
	}
	
	public int getLoad() {
		return load;
	}
	
	public void load(int load) {
		this.load = load;
	}
	
	public void print() {
		position.print();
		System.out.println("Vehicle: " + registration);
	}
}
