package org.elsys.exam;

public class Button extends Widget implements iClickable{
	
	public Button(String text, int x, int y) {
		this.text = text;
		this.x = x;
		this.y = y;
	}

	@Override
	public void click() {
		text = text.toUpperCase();
	}
}
