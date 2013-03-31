package org.elsys.labGEditor.shapes;

import org.eclipse.swt.graphics.GC;

/**
 * @author Kiril Mitov k.mitov@sap.com
 * 
 */
public class Rectangle extends Shape {

	public void paint(GC gc) {
		super.paint(gc);
		if (getFilled())
			gc.fillRectangle(getX(), getY(), getWidth(), getHeight());
		else
			gc.drawRectangle(getX(), getY(), getWidth(), getHeight());
	}

}
