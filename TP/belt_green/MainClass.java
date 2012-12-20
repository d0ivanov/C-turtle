package org.elsys.exam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class MainClass {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		List<Widget> widgetList = generateWidgets();
		printWidgets(widgetList);
		while(true) {
			String[] text = parseArgs();
			if(text[0].equals("C")) {
				for(Widget widget : widgetList) {
					if (widget instanceof Button) {
						if(widget.getText().equals(text[1])) {
							((Button) widget).click();
						}
					}
				}
			}
			printWidgets(widgetList);
		}
	}
	
	private static String[] parseArgs() {
		String s;
		try {
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            s = br.readLine();
    		return s.split(",");
        } catch (IOException e) {
            e.printStackTrace();
        }
		return null;
	}
	
	private static List<Widget> generateWidgets() {
		List<Widget> widgetList = new ArrayList<Widget>();
		for(int i= 0; i < 3; i++) {
			String[] input = parseArgs();
			if(input[0].equals("B")) {
				int x = Integer.parseInt(input[2]);
				int y = Integer.parseInt(input[3]);
				Button button = new Button(input[1], x, y);
				widgetList.add(button);
			} else if (input[0].equals("L")) {
				int x = Integer.parseInt(input[2]);
				int y = Integer.parseInt(input[3]);
				Label label = new Label(input[1], x, y);
				widgetList.add(label);
			}
		}
		
		return widgetList;
	}
	
	private static void printWidgets(List<Widget> widgetList) {
		for(Widget widget : widgetList) {
			widget.print();
		}
	}

}
