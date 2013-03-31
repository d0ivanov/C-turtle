package org.elsys.labGEditor.tools;

import org.elsys.labGEditor.shapes.IShape;
import org.elsys.labGEditor.shapes.Line;

/**
 * @author Dobromir Ivanov syliconsynapse@gmail.com
 * 
 */
public class LineTool extends AbstractTool {

	public IShape createFigure(int x, int y, int x1, int y1) {
		final Line line = new Line();
		line.setX(x);
		line.setY(y);
		line.setWidth(x1);
		line.setHeight(y1);
		return line;
	}
}
