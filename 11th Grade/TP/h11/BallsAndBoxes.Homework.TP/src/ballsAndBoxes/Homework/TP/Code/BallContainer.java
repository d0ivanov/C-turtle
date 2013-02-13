package ballsAndBoxes.Homework.TP.Code;

import java.util.ArrayList;
import java.util.List;

public class BallContainer {
	List<Ball> listOfBalls = new ArrayList<Ball>();
	
	public void add(Ball ball){
		if (!listOfBalls.contains(ball)){
			listOfBalls.add(ball);
		}
	}
	
	public void remove(Ball ball){
		listOfBalls.remove(ball);
	}
	
	public void clear(){
		listOfBalls.clear();
	}
	
	public boolean contains(Ball ball){
		return listOfBalls.contains(ball);
	}
}
