package planeSeats.Homework.TP.Elsys.code;

import java.util.*;

public class Plane {
	
	private int[][] seats = new int[6][27];
	List <Group> groups = new ArrayList<Group>();
	
	public void add(Group group){
		Seat firstSeatForGroup = findSeats(group);
		if (firstSeatForGroup.getColumn() == -1){
			return; // there is no place for this group.
		}
		if (group.getCount() == 1){
			seats[firstSeatForGroup.getColumn()][firstSeatForGroup.getRow()] = group.getId();
		}else if (group.getCount() == 2){
			seats[firstSeatForGroup.getColumn()][firstSeatForGroup.getRow()] = group.getId();
			seats[firstSeatForGroup.getColumn()+1][firstSeatForGroup.getRow()] = group.getId();
		}else{
			seats[firstSeatForGroup.getColumn()][firstSeatForGroup.getRow()] = group.getId();
			seats[firstSeatForGroup.getColumn()+1][firstSeatForGroup.getRow()] = group.getId();
			seats[firstSeatForGroup.getColumn()+2][firstSeatForGroup.getRow()] = group.getId();
		}
		groups.add(group);
	}
	
	public void remove(Group group) {
		for (int i = 0; i < 27; i++){
			for (int j = 0; j < 6; j++){
				if (seats[j][i] == group.getId()){
					seats[j][i] = 0;
				}
			}
		}
		groups.remove(group);
	}
	
	public void clear() {
		for (int i = 0; i < 27; i++){
			for (int j = 0; j < 6; j++){
				seats[j][i] = 0;
			}
		}
		groups.clear();
	}
	
	public int getCapacity() {
		int result = 0;
		for (int i = 0; i < 27; i++){
			for (int j = 0; j < 6; j++){
				if (seats[j][i] == 0){
					result ++;
				}
			}
		}
		return result;
	}
	
	public int getGender(String gender){
		int result = 0;
		for(Group group : groups){
			for(Human human : group.getPeople()){
				if (human.getGender() == gender){
					result ++;
				}
			}
		}
		return result;
	}
	
	public void printSeats(){
		for (int i = 0; i < 27; i++){
			for (int j = 0; j < 6; j++){
				System.out.print(seats[j][i]);
				if (j == 2){
					System.out.print(" ");
				}
			}
			System.out.println();
		}
	}
	
	private Seat findSeats(Group group){
		for (int i = 0; i < 27; i++){
			for (int j = 0; j < 6; j++){
				if (j + group.getCount() <= 6){ // prevent out of bound exception
					if (group.getCount() == 1){ // if group has 1 member
						if (seats[j][i] == 0){
							return new Seat(j, i);
						}
					}else if (group.getCount() == 2){ // if group has 2 members
						if (seats[j][i] + seats[j+1][i] == 0){
							return new Seat(j, i);
						}
					}else{ // if group has 3 members
						if (seats[j][i] + seats[j+1][i] + seats[j+2][i] == 0){
							return new Seat(j, i);
						}
					}
				}
			}
		}
		return new Seat(-1, -1);
	}
}
