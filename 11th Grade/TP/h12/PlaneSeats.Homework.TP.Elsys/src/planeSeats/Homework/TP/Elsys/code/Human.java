package planeSeats.Homework.TP.Elsys.code;

public class Human {
	private String name;
	private String gender;
	
	Human(String value1, String value2){
		name = value1;
		gender = value2;
	}
	
	public void setName(String value) { name = value; }
	
	public void setGender(String value) { gender = value; }
	
	public String getName() { return name; }
	
	public String getGender() { return gender; }
}
