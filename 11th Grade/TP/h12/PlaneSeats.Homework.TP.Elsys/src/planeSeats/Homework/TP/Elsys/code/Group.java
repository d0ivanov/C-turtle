package planeSeats.Homework.TP.Elsys.code;

import java.util.*;

public class Group {
	private int count, id;
	private List<Human> people = new ArrayList<Human>();
	private static int currentId = 1;
	
	Group(){
		id = currentId;
		currentId++;
	}
	
	public void add(Human human){
		if (count < 3){
			people.add(human);
			count += 1;
		}
	}
	
	public int getCount(){
		return count;
	}
	
	public int getId(){
		return id;
	}
	
	public List<Human> getPeople(){
		return people;
	}
}
