package org.elsys.example1;

import org.elsys.balls.*;

public class MainClass {
	public static void main() {
		Ball b1 = new Ball();
		b1.setName("b1");
		Ball b2 = new Ball();
		b2.setName("b2");
		/* Using container with undefined space... */
		BallContainer bc = new BallContainer();
		try {
			bc.add(b1);
			bc.add(b2);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

		/* Using box with defined space */

		Box box = new Box(10);
		try {
			box.add(b1);
			box.add(b2);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
}
