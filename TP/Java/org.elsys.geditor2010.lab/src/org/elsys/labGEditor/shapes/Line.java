package org.elsys.labGEditor.shapes;

import org.eclipse.swt.graphics.GC;

/**
 * @author Doromir Ivanov syliconsynapse@gmail.com
 * 
 */
public class Line extends Shape {

	public void paint(GC gc) {
		super.paint(gc);
		gc.drawLine(getX(), getY(), getX() + getWidth(), getY() + getHeight());
	}
}
