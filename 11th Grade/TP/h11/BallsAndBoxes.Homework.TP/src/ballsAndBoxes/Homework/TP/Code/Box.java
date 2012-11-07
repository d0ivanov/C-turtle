package ballsAndBoxes.Homework.TP.Code;

import java.util.*;

public class Box {
	List<Ball> listOfBalls = new ArrayList<Ball>();
	int size;
	
	public Box(int value){
		size = value;
	}
	
	public void add(Ball ball){
		if (listOfBalls.size() < size) {
			listOfBalls.add(ball);
		}
	}
	
	public void remove(Ball ball){
		listOfBalls.remove(ball);
	}
	
	public int getCapacity(){
		return size - listOfBalls.size();
	}
	
	public int size(){
		return size;
	}
	
	public void clear(){
		listOfBalls.clear();
	}
	
	public boolean contains(Ball ball){
		return listOfBalls.contains(ball);
	}
}
