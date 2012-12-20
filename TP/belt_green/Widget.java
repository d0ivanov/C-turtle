package org.elsys.exam;

public class Widget {

	protected String text;
	protected int x;
	protected int y;
	
	public String getText() {
		return text;
	}
	
	public void setText(String text) {
		this.text = text;
	}
	
	public int getX() {
		return x;
	}
	
	public void setX(int x) {
		this.x = x;
	}
	
	public int getY() {
		return y;
	}
	
	public void setY(int y) {
		this.y = y;
	}
	
	public void print() {
		System.out.println("Widget: " + "X: " + x + "Y: " + y + "text: " + text );
	}
}