import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.events.MouseMoveListener;
import org.eclipse.swt.events.PaintEvent;
import org.eclipse.swt.events.PaintListener;
import org.eclipse.swt.graphics.GC;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Canvas;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;

public class Drawing {

	private DrawingPoint start;
	private DrawingPoint end;
	private DrawingPoint movePoint;

	public static void main(String[] args) {
		Drawing d = new Drawing();
		d.createCanvas();
	}

	public void createCanvas() {
		Display d = new Display();
		Shell shell = new Shell(d);
		shell.setLayout(new FillLayout());
		Shell shell2 = new Shell(d);
		shell2.setSize(300, 100);
		final Text text = new Text(shell2, SWT.BORDER);
		shell2.setLayout(new FillLayout());

		Button compute = new Button(shell2, SWT.PUSH);
		compute.setText("Compute");
		
		shell2.open();
		final Canvas canvas = new Canvas(shell, SWT.BORDER);
		canvas.setBackground(Display.getDefault().getSystemColor(
				SWT.COLOR_WHITE));
		final List<DrawingPoint> points = new ArrayList<DrawingPoint>();
		final List<DrawingPoint> foundPts = new ArrayList<DrawingPoint>();
		
		compute.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event e) {
				List<String> names = parseText(text.getText());
				for (DrawingPoint p : points) {
					if (names.contains(p.title)) {
						foundPts.add(p);
						names.remove(p.title);
					}
				}
				canvas.redraw();
			}
		});
		
		canvas.addPaintListener(new PaintListener() {
			@Override
			public void paintControl(PaintEvent e) {
				if(foundPts.size() > 0) {
					//Alpha
					double alpha = findAngle(foundPts.get(2),foundPts.get(0),foundPts.get(1));
					e.gc.drawText(Double.toString(alpha), foundPts.get(0).x + 14, foundPts.get(0).y + 18);
					//Beta
					double beta = findAngle(foundPts.get(0),foundPts.get(1),foundPts.get(2));
					e.gc.drawText(Double.toString(beta), foundPts.get(1).x + 14, foundPts.get(1).y + 18);
					//Gamma
					double gamma = findAngle(foundPts.get(0),foundPts.get(2),foundPts.get(1));
					e.gc.drawText(Double.toString(gamma), foundPts.get(2).x + 14, foundPts.get(2).y + 18);
				}
			}
		});
		
		canvas.addMouseMoveListener(new MouseMoveListener() {

			@Override
			public void mouseMove(MouseEvent e) {
				end = new DrawingPoint(e.x, e.y);
				canvas.redraw();
			}

		});
		canvas.addMouseListener(new MouseListener() {

			@Override
			public void mouseDoubleClick(MouseEvent e) {
			}

			@Override
			public void mouseDown(MouseEvent e) {
				if (e.button == 1) {
					start = new DrawingPoint(e.x, e.y);
				} else if (e.button == 3) {
					movePoint = findPoint(points, e.x, e.y);
				}
			}

			@Override
			public void mouseUp(MouseEvent e) {
				if (e.button == 1) {
					points.add(start);
					start.title = "p" + Integer.toString(points.size());
					// points.add(new Point(e.x, e.y));
					// start = null;
					canvas.redraw();
				} else if (e.button == 3) {
					movePoint = null;
				}
			}

		});
		canvas.addPaintListener(new PaintListener() {

			@Override
			public void paintControl(PaintEvent e) {
				drawLines(points, e.gc);
			}
		});
		shell.open();

		while (!shell.isDisposed()) {
			if (!d.readAndDispatch()) {
				d.sleep();
			}
		}
	}

	private DrawingPoint findPoint(List<DrawingPoint> points, int x, int y) {
		for (DrawingPoint p : points) {
			if (Math.abs(p.x - x) < 5 && Math.abs(p.y - y) < 5)
				return p;
		}
		return null;
	}

	private void drawLines(final List<DrawingPoint> points, GC gc) {
		if (movePoint != null) {
			movePoint.x = end.x;
			movePoint.y = end.y;
		}
		// if (start != null && end != null) {
		// gc.drawLine(start.x, start.y, end.x, end.y);
		// }
		for (int i = 0; i < points.size(); i++) {
			DrawingPoint p1 = points.get(i);
			gc.drawOval(p1.x - 4, p1.y - 4, 8, 8);
			gc.drawText(p1.title, p1.x + 4, p1.y + 4);
			for (int k = i + 1; k < points.size(); k++) {
				DrawingPoint p2 = points.get(k);
				int xnew;
				int ynew;
				if (p1.x > p2.x) {
					xnew = (p1.x - p2.x) / 2 + p2.x;
				} else {
					xnew = (p2.x - p1.x) / 2 + p1.x;
				}
				if (p1.y > p2.y) {
					ynew = (p1.y - p2.y) / 2 + p2.y;
				} else {
					ynew = (p2.y - p1.y) / 2 + p1.y;
				}
				int distance = (int) Math.pow(
						(Math.pow(Math.abs(p1.x - p2.x), 2) + Math.pow(
								Math.abs(p1.y - p2.y), 2)), 0.5);
				gc.drawText(Integer.toString(distance) + "px", xnew, ynew);
				gc.drawLine(p1.x, p1.y, p2.x, p2.y);
			}
		}
		// for (int i = 0; i < points.size(); i++) {
		// Point start = points.get(i);
		// Point end = points.get(++i);
		// gc.drawLine(start.x, start.y, end.x, end.y);
		// }
	}
	
	private final List<String> parseText(String command) {
		command.toLowerCase();
		command = command.replaceAll(" ", "");
		String data[] = command.split(",");
		return new ArrayList<String>(Arrays.asList(data));
	}

	private final int findDistance(DrawingPoint p1, DrawingPoint p2) {

		return (int) Math.pow(
				(Math.pow(Math.abs(p1.x - p2.x), 2) + Math.pow(
						Math.abs(p1.y - p2.y), 2)), 0.5);
	}
	
	private final double findAngle(DrawingPoint p1, DrawingPoint p2, DrawingPoint p3) {
		double cos;
		cos = -(Math.pow(findDistance(p1, p3), 2)- Math.pow(findDistance(p1, p2), 2)- Math.pow(findDistance(p2, p3), 2));
		cos /= 2*findDistance(p1,p2)*findDistance(p2,p3);
		return 180*Math.acos(cos)/Math.PI;
	}
	
	private final DrawingPoint findBisector(DrawingPoint p1, DrawingPoint p2, DrawingPoint p3) {
		//TODO!
		return null;
	}
}
