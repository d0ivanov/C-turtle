package org.elsys.testExam;

public class Car extends Vehicle implements iLoadable {

	public Car(int registration, Coordinate position) {
		this.registration = registration;
		this.position = position;
	}
	
	@Override
	public void load(int load) {
		if(this.load + load > 1) {
			System.out.print("Car full! Can't add more stuff!");
			return;
		}
		super.load(load);
	}
	
	@Override
	public void print() {
		position.print();
		System.out.println("Car: " + registration);
	}
}
