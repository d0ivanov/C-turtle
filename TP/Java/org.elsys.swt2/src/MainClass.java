import java.util.Random;

import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;

public class MainClass {

	public static void main(String[] args) {
		Display d = new Display();
		final Shell shell = new Shell(d);
		shell.setText("Hello world");
		shell.setSize(600, 400);
		shell.setLayout(new FillLayout());
		
		Text text = new Text(shell, SWT.BORDER);
		text.setBounds(40, 40, 100, 20);

		Button b = new Button(shell, SWT.PUSH);
		b.setText("Click me!");
		b.setLocation(200, 200);
		b.setSize(50, 50);
		b.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				Button b = new Button(shell, SWT.PUSH);
				b.setText("New button");
				Random r = new Random();
				
				b.setBounds(r.nextInt(600), r.nextInt(400), 100, 100);
				shell.layout(true);
			}
		});

		shell.open();

		while (!shell.isDisposed()) {
			if (!d.readAndDispatch())
				d.sleep();
		}
	}
}
