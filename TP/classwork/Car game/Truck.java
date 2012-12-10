package org.elsys.testExam;

public class Truck extends Vehicle implements iLoadable {
	
	public Truck(int registration, Coordinate position) {
		this.registration = registration;
		this.position = position;
	}
	
	@Override
	public void load(int load) {
		if(this.load + load > 100) {
			System.out.println("Truck full, sorry!");
			return;
		}
		super.load(load);
	}
	
	@Override
	public void print() {
		position.print();
		System.out.println("Truck: " + registration);
	}
}
