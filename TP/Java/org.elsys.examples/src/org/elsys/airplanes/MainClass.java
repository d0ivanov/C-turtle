package org.elsys.airplanes;

import java.util.Random;

public class MainClass {

	public static void main(String[] args) {
		Plane plane = new Plane();
		Integer people = 0;
		while(!plane.planeFull()){
			Passanger passanger = new Passanger();
			int rval = new Random().nextInt(3) + 1;
			
			Passanger randomPerson = passanger.generateRandom();
			
			if(people + rval <= 162){
				people += rval;
			}
			plane.addPassenger(randomPerson);
		}
		
		System.out.println(people.toString() + " people boarded the plane!");
	}
}
