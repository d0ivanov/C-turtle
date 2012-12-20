package org.elsys.airplanes;

import java.util.ArrayList;
import java.util.List;

public class Plane {

	private List<PlaneSeat> seats;

	public Plane(){
		this.seats = new ArrayList<PlaneSeat>();
		for(int i = 0; i < 27; i++){
			for(int j = 0; j < 6; j++){
				PlaneSeat seat = new PlaneSeat();
				seat.setRow(i);
				seat.setColumn(j);
				seat.setTaken(false);
				if(j != 2 ){
					seat.setNextToTrail(false);
				}else{
					seat.setNextToTrail(true);
				}
				seats.add(seat);
			}
		}
	}
	
	public List<PlaneSeat> getSeats(){
		return this.seats;
	}

	public void addPassenger(Passanger passanger) {
		int avaiableSeat = findAvaiableSeat();
		if (avaiableSeat >= 0) {
			seats.get(avaiableSeat).setPassanger(passanger);
			seats.get(avaiableSeat).setTaken(true);
			String readableSeatAddress = seats.get(avaiableSeat).seatToReadable();
			System.out.println(readableSeatAddress + " is taken!");
		}
	}
	
	public void removePassanger(Passanger passanger){
		int passangerIndex = seats.indexOf(passanger);
		if(passangerIndex < 0){
			System.out.println("List does not contain this passanger!");
			return;
		}
		seats.remove(passangerIndex);
	}
	
	public void clear(){
		seats.clear();
	}
	
	public int getCapacity(){
		return seats.size();
	}
	
	public int femaleCount(){
		int femaleCount = 0;
		for(PlaneSeat seat : seats){
			if(seat.getPassanger().getGender() == 2){
				femaleCount++;
			}
		}
		return femaleCount;
	}
	
	public int maleCount(){
		int maleCount = 0;
		for(PlaneSeat seat : seats){
			if(seat.getPassanger().getGender() == 1){
				maleCount++;
			}
		}
		return maleCount;
	}

	public int findAvaiableSeat() {
		for (int i = 0; i < seats.size(); i++) {
			if (!seats.get(i).isTaken()) {
				return i;
			}
		}
		return -1;
	}
	
	public boolean planeFull(){
		for(PlaneSeat seat : seats){
			if(!seat.isTaken()){
				return false;
			}
		}
		return true;
	}
}
