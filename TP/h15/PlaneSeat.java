package org.elsys.airplanes;

public class PlaneSeat {

	private int row;
	private int column;
	private boolean isTaken;
	private Passanger passanger;
	private boolean isNextToTrail;
	
	public int getRow() {
		return row;
	}

	public void setRow(int row) {
		this.row = row;
	}

	public int getColumn() {
		return column;
	}

	public void setColumn(int column) {
		this.column = column;
	}

	public boolean isTaken() {
		return isTaken;
	}

	public void setTaken(boolean isTaken) {
		this.isTaken = isTaken;
	}

	public Passanger getPassanger() {
		return passanger;
	}

	public void setPassanger(Passanger passanger) {
		this.passanger = passanger;
	}

	public String seatToReadable() {
		String seatLetter = "";
		switch (column) {
		case 0:
			seatLetter = "A";
			break;
		case 1:
			seatLetter = "B";
			break;
		case 2:
			seatLetter = "C";
			break;
		case 3:
			seatLetter = "D";
			break;
		case 4:
			seatLetter = "E";
			break;
		case 5:
			seatLetter = "F";
			break;
		}
		return ((Integer)row).toString() + seatLetter;
	}

	public boolean seatEmpty(PlaneSeat seat) {
		return seat.isTaken;
	}

	public boolean isNextToTrail() {
		return isNextToTrail;
	}

	public void setNextToTrail(boolean isNextToTrail) {
		this.isNextToTrail = isNextToTrail;
	}
}
