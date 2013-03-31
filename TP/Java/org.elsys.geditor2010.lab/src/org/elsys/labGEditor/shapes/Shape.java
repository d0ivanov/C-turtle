package org.elsys.labGEditor.shapes;

import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.graphics.GC;

/**
 * @author Kiril Mitov k.mitov@sap.com
 * 
 */
public abstract class Shape implements IShape {

	private int x;
	private int y;
	private int width;
	private int height;
	private boolean filled;
	private Color bgColor;
	private Color fgColor;

	/**
	 * @return the x
	 */
	public final int getX() {
		return x;
	}

	/**
	 * @return the y
	 */
	public final int getY() {
		return y;
	}

	/**
	 * @return the width
	 */
	public final int getWidth() {
		return width;
	}

	/**
	 * @return the height
	 */
	public final int getHeight() {
		return height;
	}

	/**
	 * @param x
	 *            the x to set
	 */
	public final void setX(int x) {
		this.x = x;
	}

	/**
	 * @param y
	 *            the y to set
	 */
	public final void setY(int y) {
		this.y = y;
	}

	/**
	 * @param width
	 *            the width to set
	 */
	public final void setWidth(int width) {
		this.width = width;
	}

	/**
	 * @param height
	 *            the height to set
	 */
	public final void setHeight(int height) {
		this.height = height;
	}

	public boolean getFilled() {
		return filled;
	}

	public void setFilled(boolean filled) {
		this.filled = filled;
	}

	public Color getBackgroundColor() {
		return bgColor;
	}

	public Color getForegroundColor() {
		return fgColor;
	}

	public void setBackgroundColor(Color color) {
		this.bgColor = color;
	}

	public void setForegroundColor(Color color) {
		this.fgColor = color;
	}

	public void paint(GC gc) {
		gc.setBackground(bgColor);
		gc.setForeground(fgColor);
	}

}
