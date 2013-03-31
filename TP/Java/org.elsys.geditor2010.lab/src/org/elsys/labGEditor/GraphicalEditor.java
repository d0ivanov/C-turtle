package org.elsys.labGEditor;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.MouseEvent;
import org.eclipse.swt.events.MouseListener;
import org.eclipse.swt.events.MouseMoveListener;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.graphics.Color;
import org.eclipse.swt.graphics.RGB;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.layout.GridLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.ColorDialog;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.swt.widgets.Group;
import org.elsys.labGEditor.shapes.IShape;
import org.elsys.labGEditor.tools.ITool;
import org.elsys.labGEditor.tools.LineTool;
import org.elsys.labGEditor.tools.RectangleTool;

/**
 * @author Kiril Mitov k.mitov@sap.com
 * 
 */
public class GraphicalEditor {

	private Button rectangleButton;
	
	private Button lineButton;

	private ITool tool;

	private Button fgColorButton;

	private Color fgColor;

	public void createGraphicalEditor(Composite parent) {
		Composite composite = new Composite(parent, SWT.NONE);
		composite.setLayout(new GridLayout(2, false));
		createButtonsComposite(composite);
		createCanvas(composite);
	}

	private void createCanvas(Composite parent) {
		Group composite = new Group(parent, SWT.NONE);
		final GridData layoutData = new GridData(GridData.FILL_BOTH);
		layoutData.grabExcessHorizontalSpace = true;
		layoutData.grabExcessVerticalSpace = true;
		composite.setLayoutData(layoutData);
		composite.setLayout(new FillLayout());
		createEditingArea(composite);
	}

	private void createEditingArea(Group composite) {
		final EditingArea area = new EditingArea(composite, SWT.NONE);
		area.addMouseListener(new MouseListener() {
			public void mouseDoubleClick(MouseEvent e) {
			}

			public void mouseDown(MouseEvent e) {
				if (tool == null)
					return;
				tool.startMoving(area, e.x, e.y);
			}

			public void mouseUp(MouseEvent e) {
				if (tool == null)
					return;
				IShape shape = tool.stopMoving(e.x, e.y);
				area.addShape(shape);
				area.redraw(shape.getX(), shape.getY(), shape.getWidth() + 1,
						shape.getHeight() + 1, false);
			}
		});
		area.addMouseMoveListener(new MouseMoveListener() {
			public void mouseMove(MouseEvent e) {
				if (tool == null)
					return;
				tool.moving(e.x, e.y);
			}
		});
	}

	private void createButtonsComposite(final Composite parent) {
		Composite composite = new Group(parent, SWT.NONE);
		composite.setLayout(new GridLayout(1, false));
		composite
				.setLayoutData(new GridData(GridData.VERTICAL_ALIGN_BEGINNING));
		createRectButton(composite);
		createFgColorButton(composite);
		createLineButton(composite);
	}

	private void createFgColorButton(final Composite composite) {
		fgColorButton = new Button(composite, SWT.PUSH);
		fgColorButton.setLayoutData(new GridData());
		fgColorButton.setText("Foreground Color");
		fgColorButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				ColorDialog dialog = new ColorDialog(composite.getShell());
				RGB rgb = dialog.open();
				if (rgb == null)
					return;
				fgColor = new Color(null, rgb);
				fgColorButton.setForeground(fgColor);
				if (tool != null)
					tool.setForegroundColor(fgColor);
			}
		});
	}

	private void createRectButton(Composite composite) {
		rectangleButton = new Button(composite, SWT.TOGGLE);
		rectangleButton.setLayoutData(new GridData());
		rectangleButton.setText("Rectangle"); //$NON-NLS-1$
		rectangleButton.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				selectShapeButton(rectangleButton);
			}

		});
	}
	
	private void createLineButton(Composite composite) {
		lineButton = new Button(composite, SWT.TOGGLE);
		lineButton.setLayoutData(new GridData());
		lineButton.setText("Line");
		lineButton.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				selectShapeButton(lineButton);
			}
		});
	}

	private void selectShapeButton(Button widget) {
//		MessageBox box = new MessageBox(widget.getShell());
//		String message = "Some message";
//		box.setMessage(message);
//		box.open();
		
		rectangleButton.setSelection(false);
		if (rectangleButton == widget) {
			tool = new RectangleTool();
		}
		
		if (lineButton == widget) {
			tool = new LineTool();
		}
		
		if (tool == null)
			return;
		widget.setSelection(true);
		if (fgColor != null)	
			tool.setForegroundColor(fgColor);
	}

}
