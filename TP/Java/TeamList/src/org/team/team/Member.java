package org.team.team;

public class Member implements Comparable<Member> {

	private String gender;
	private String name;
	private int age;

	public Member(String gender, String name, int age) {
		this.gender = gender;
		this.name = name;
		this.age = age;
	}
	
	public String getGender() {
		return gender;
	}

	public String getName() {
		return name;
	}

	public int getAge() {
		return age;
	}

	@Override
	public int compareTo(Member other) {
		return this.age - other.age;
	}
}