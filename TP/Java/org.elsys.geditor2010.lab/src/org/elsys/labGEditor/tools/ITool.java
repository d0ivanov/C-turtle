package org.elsys.labGEditor.tools;

import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.widgets.Canvas;
import org.elsys.labGEditor.shapes.IShape;

/**
 * @author Kiril Mitov k.mitov@sap.com
 * 
 */
public interface ITool {

	public IShape createFigure(int x, int y, int width, int height);

	public IShape startMoving(Canvas area, int x, int y);

	public IShape moving(int x, int y);

	public IShape stopMoving(int x, int y);

	public void setFilled(boolean filled);

	public void setBackgroundColor(Color bgColor);

	public void setForegroundColor(Color fgColor);

}
