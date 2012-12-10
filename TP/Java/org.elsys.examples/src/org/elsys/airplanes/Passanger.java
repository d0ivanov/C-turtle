package org.elsys.airplanes;

import java.util.Random;

public class Passanger {

	private String name;
	private int gender;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getGender() {
		return gender;
	}

	public void setGender(int gender) {
		this.gender = gender;
	}

	public Passanger generateRandom() {
		Passanger passanger = new Passanger();
		passanger.setName(new RandomString(5).nextString());
		passanger.setGender(new Random().nextInt(2) + 1);
		return passanger;
	}
}
