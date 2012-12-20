package org.elsys.balls;

import java.util.*;

import org.elsys.balls.Ball;

public class BallContainer {

	protected LinkedList<Ball> containerSpace;

	public void add(Ball ball) throws Exception {
		if (!contains(ball)) {
			containerSpace.add(ball);
		} else {
			throw new Exception("Ball already inside!");
		}
	}

	public void remove(Ball ball) {
		containerSpace.remove(containerSpace.indexOf(ball));
	}

	public int size() {
		return containerSpace.size();
	}

	public void clear() {
		containerSpace.clear();
	}

	public boolean contains(Ball ball) {
		return containerSpace.contains(ball);
	}
}
