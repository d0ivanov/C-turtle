package ballsAndBoxes.Homework.TP.Code;

public class Box extends BallContainer {
	int size;
	
	public Box(int value){
		size = value;
	}
	
	public void add(Ball ball){
		if (listOfBalls.size() < size && !listOfBalls.contains(ball)) {
			listOfBalls.add(ball);
		}
	}
	
	public int getCapacity(){
		return size - listOfBalls.size();
	}
	
	public int size(){
		return size;
	}
}
