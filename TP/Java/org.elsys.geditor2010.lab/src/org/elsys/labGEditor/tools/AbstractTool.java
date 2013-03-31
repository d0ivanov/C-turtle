package org.elsys.labGEditor.tools;

import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.graphics.GC;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Display;
import org.elsys.labGEditor.shapes.IShape;

/**
 * @author kiko
 * 
 */
public abstract class AbstractTool implements ITool {

	private IShape movingShape;

	private GC movingShapeGc = null;

	private Canvas canvas = null;

	private boolean filled = false;

	private Color bgColor = Display.getDefault()
			.getSystemColor(SWT.COLOR_BLACK);

	private Color fgColor = Display.getDefault()
			.getSystemColor(SWT.COLOR_BLACK);

	public IShape moving(int x, int y) {
		if (movingShape == null)
			return null;
		drawOld(x, y);
		drawNew(x, y);
		return movingShape;
	}

	private void drawOld(int x, int y) {
		canvas.redraw();
		canvas.update();
	}

	private void drawNew(int x, int y) {
		movingShape.setWidth(x - movingShape.getX());
		movingShape.setHeight(y - movingShape.getY());
		movingShape.paint(movingShapeGc);
	}

	public IShape startMoving(Canvas area, int x, int y) {
		canvas = area;
		movingShape = createFigure(x, y, 0, 0);
		movingShape.setFilled(filled);
		movingShape.setBackgroundColor(bgColor);
		movingShape.setForegroundColor(fgColor);
		movingShapeGc = new GC(area);
		return movingShape;
	}

	public IShape stopMoving(int x, int y) {
		movingShapeGc.dispose();
		movingShapeGc = null;
		IShape result = movingShape;
		movingShape = null;
		return result;
	}

	public void setFilled(boolean filled) {
		this.filled = filled;
	}

	public void setBackgroundColor(Color bgColor) {
		this.bgColor = bgColor;
	}

	public void setForegroundColor(Color fgColor) {
		this.fgColor = fgColor;
	}
}
