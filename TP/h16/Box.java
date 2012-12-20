package org.elsys.balls;

import org.elsys.balls.Ball;

public class Box extends BallContainer {

	private int size;

	public Box(int size){
		this.size = size;
	}
	
	public void add(Ball ball) throws Exception {
		if (size() < size && !contains(ball)) {
			containerSpace.add(ball);
		} else {
			throw new Exception(
					"Not enough space int the box! Or ball already inside!");
		}
	}

	public Ball getBallsFromSmallest() {
		return new Ball();
	}
}
