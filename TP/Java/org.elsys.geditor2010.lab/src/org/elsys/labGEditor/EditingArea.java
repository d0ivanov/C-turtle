package org.elsys.labGEditor;

import java.util.ArrayList;
import java.util.Collection;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.PaintEvent;
import org.eclipse.swt.events.PaintListener;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Display;
import org.elsys.labGEditor.shapes.IShape;

/**
 * @author Kiril Mitov k.mitov@sap.com
 * 
 */
public class EditingArea extends Canvas {

	private Collection<IShape> shapes = new ArrayList<IShape>();

	public EditingArea(Composite parent, int style) {
		super(parent, style);
		this.addPaintListener(new PaintListener() {
			public void paintControl(PaintEvent e) {
				handlePaint(e);
			}
		});
		this.setBackground(Display.getDefault().getSystemColor(SWT.COLOR_WHITE));
	}

	public void addShape(IShape shape) {
		shapes.add(shape);
	}

	public void removeShape(IShape shape) {
		shapes.remove(shape);
	}

	//To be removed. Exposes to much information. Probably.
	public Collection<IShape> getShapes() {
		return shapes;
	}
	
	private void handlePaint(PaintEvent e) {
		for (IShape shape : shapes) {
			shape.paint(e.gc);
		}
	}
}
