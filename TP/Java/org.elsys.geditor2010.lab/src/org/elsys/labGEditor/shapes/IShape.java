package org.elsys.labGEditor.shapes;

import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.graphics.GC;

/**
 * @author kiko
 * 
 */
public interface IShape {

	/**
	 * @return the x
	 */
	public abstract int getX();

	/**
	 * @return the y
	 */
	public abstract int getY();

	/**
	 * @return the width
	 */
	public abstract int getWidth();

	/**
	 * @return the height
	 */
	public abstract int getHeight();

	/**
	 * @param x
	 *            the x to set
	 */
	public abstract void setX(int x);

	/**
	 * @param y
	 *            the y to set
	 */
	public abstract void setY(int y);

	/**
	 * @param width
	 *            the width to set
	 */
	public abstract void setWidth(int width);

	/**
	 * @param height
	 *            the height to set
	 */
	public abstract void setHeight(int height);

	/**
	 * @param filled
	 *            the filled to be set
	 */
	public abstract void setFilled(boolean filled);

	/**
	 * @return
	 */
	public abstract boolean getFilled();

	/**
	 * @return
	 */
	public abstract Color getForegroundColor();

	/**
	 * @param color
	 */
	public abstract void setForegroundColor(Color color);

	/**
	 * @return
	 */
	public abstract Color getBackgroundColor();

	/**
	 * @param color
	 */
	public abstract void setBackgroundColor(Color color);

	/**
	 * @param gc
	 */
	public void paint(GC gc);
}