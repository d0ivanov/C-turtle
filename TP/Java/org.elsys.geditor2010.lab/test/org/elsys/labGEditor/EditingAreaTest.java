/**
 * 
 */
package org.elsys.labGEditor;

import static org.junit.Assert.*;

import org.eclipse.swt.SWT;
import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.graphics.GC;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Shell;
import org.elsys.labGEditor.shapes.IShape;
import org.elsys.labGEditor.shapes.Rectangle;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * @author kireto
 * 
 */
public class EditingAreaTest {

	private Shell shell;
	private Display d;

	@Before
	public void setUp() {
		d = new Display();
		shell = new Shell(d);
	}

	@After
	public void tearDown() {
		d.dispose();
	}

	private EditingArea createFixture() {
		return new EditingArea(shell, SWT.NONE);
	}

	@Test 
	public void testPaintAllShapes() {
		EditingArea area = createFixture();
		
		DummyShape shape = new DummyShape();
		area.addShape(shape);
		
		Event event = new Event();
		area.notifyListeners(SWT.Paint, event);
		assertTrue(shape.isPaintCalled);
	}
	
	@Test
	public void testPaintListenerExists() {
		EditingArea area = createFixture();
		assertTrue(area.isListening(SWT.Paint));
	}
	
	@Test
	// EditingAreaTest tests add shape not null
	public void testAddShapeNotNull() {
		EditingArea area = createFixture();

		IShape shape = new Rectangle();
		area.addShape(shape);
		assertTrue(area.getShapes().contains(shape));
	}

	@Test
	public void testRemoveShape() {
		EditingArea area = createFixture();

		IShape shape = new Rectangle();
		area.addShape(shape);
		area.removeShape(shape);
		assertFalse(area.getShapes().contains(shape));
	}

	@Test
	public void testBackground() {
		EditingArea area = createFixture();
		assertEquals(Display.getDefault().getSystemColor(SWT.COLOR_WHITE),
				area.getBackground());
	}
	
	
}

class DummyShape implements IShape {

	public boolean isPaintCalled = false;
	
	public void paint(GC gc) {
		isPaintCalled = true;
	}

	public int getX() {
		return 0;
	}

	public int getY() {
		return 0;
	}

	public int getWidth() {
		return 0;
	}

	public int getHeight() {
		// TODO Auto-generated method stub
		return 0;
	}

	public void setX(int x) {
		// TODO Auto-generated method stub
		
	}

	public void setY(int y) {
		// TODO Auto-generated method stub
		
	}

	public void setWidth(int width) {
		// TODO Auto-generated method stub
		
	}

	public void setHeight(int height) {
		// TODO Auto-generated method stub
		
	}

	public void setFilled(boolean filled) {
		// TODO Auto-generated method stub
		
	}

	public boolean getFilled() {
		// TODO Auto-generated method stub
		return false;
	}

	public Color getForegroundColor() {
		// TODO Auto-generated method stub
		return null;
	}

	public void setForegroundColor(Color color) {
		// TODO Auto-generated method stub
		
	}

	public Color getBackgroundColor() {
		// TODO Auto-generated method stub
		return null;
	}

	public void setBackgroundColor(Color color) {
		// TODO Auto-generated method stub
		
	}

	
}











