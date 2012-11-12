package planeSeats.Homework.TP.Elsys.code;

public class Seat {
	private int column, row;
	
	Seat(int value1, int value2){
		column = value1;
		row = value2;
	}
	
	public int getColumn(){
		return column;
	}
	
	public int getRow(){
		return row;
	}
}
