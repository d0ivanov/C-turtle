package org.elsys.labGEditor.tools;

import org.elsys.labGEditor.shapes.IShape;
import org.elsys.labGEditor.shapes.Rectangle;

/**
 * @author Kiril Mitov k.mitov@sap.com
 * 
 */
public class RectangleTool extends AbstractTool {

	public IShape createFigure(int x, int y, int width, int height) {
		final Rectangle rectangle = new Rectangle();
		rectangle.setX(x);
		rectangle.setY(y);
		rectangle.setWidth(width);
		rectangle.setHeight(height);
		return rectangle;
	}

}
