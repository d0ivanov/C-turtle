/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Програма за "пъхане" на хора в самолет.
*/

import java.util.Random;

public class Plane {
	
	private int[][] seats = new int[6][27];
	
	public void printSeats(){ // prints 2D array of 1/0 representing the seats
		for (int i = 0; i < 27; i++)
		{
			for (int k = 0; k < 6; k++)
			{
			 	System.out.print(seats[k][i]);
			 	System.out.print(" ");
			 	if (k == 2) System.out.print("  ");
			}
			System.out.print("\n");
		}
	}
	
	private boolean pushCheck(int group, int j, int i){ // checks if the group given can sit at the place given and it's neighbours
		if (j + group <= 6){ // to prevent out of bound exception
			if (group == 1){ // if 1
				if (seats[j][i] == 0){
					return true;
				}
			}else{
				if (group == 2){ // if 2
					if (seats[j][i] == 0 && seats[j+1][i] == 0 && neighbourSeats(group, j)){
						return true;					
					}
				}else{ // if 3
					if (seats[j][i] == 0 && seats[j+1][i] == 0 && seats[j+2][i] == 0 && neighbourSeats(group, j)){
						return true;
					}
				}
			}
		}
		return false;
	}
	
	private boolean neighbourSeats(int group, int j){ //checks if the seats are neighbours (dividing them by the path)
		if (j < 3){
			if (j + group <= 3) return true;
		}else{
			if (j + group <= 6) return true;
		}
		
		return false;
	}
	
	private void fill(int group, int j, int i){ // fills the seat that are taken with 1
		for (int j1 = j; j1 < j + group; j1++){
			seats[j1][i] = 1;
		}
	}
	
	public void push(int group){ // pushes people in the 2d array :D
		for (int i = 0; i < 27; i++) {
			for (int j = 0; j < 6; j++){
				if (pushCheck(group, j, i)){
					fill(group, j, i);
					seatsToTake(group, j, i);
					return;
				}
			}
		}
	}
	
	private void seatsToTake(int group, int j, int i){ // printing which seats does a group of people takes
		System.out.print("Group of " + group + " people. ");
		if (group == 1){
			System.out.println("Your place is: " + (i + 1) + "|" + (j + 1)); // +1 so that there is no row/col 0
		}else{
			if (group == 2){
				System.out.println(
					"Your place is: " + (i + 1) + "|" + (j + 1) + " & " +
					(i + 1) + "|" + (j + 2)
				);
			}else{
				System.out.println(
					"Your place is: " + (i + 1) + "|" + (j + 1) + " & " +
					(i + 1) + "|" + (j + 2) + " & " +
					(i + 1) + "|" + (j + 3)
				);
			}
		}
	}
	
	public int freeSeats(){ // returns the count of free seats
		int res = 0;
		
		for (int i = 0; i < 6; i++){
			for (int j = 0; j < 27; j++){
				if (seats[i][j] == 0){
					res++;
				}
			}
		}
		
		return res;
	}
	
	public static void main(String args[]) {
		
		Plane airPlane = new Plane();
		
		int people = 0;
		int j;
		
		for (j = 0; airPlane.freeSeats() != 0; j++){
			int rVal = new Random().nextInt(3) + 1;
			if (people + rVal <= 162) people += rVal;
			if (airPlane.freeSeats() != 0) {
				airPlane.push(rVal);
			}else{
				break;
			}
		}
		airPlane.printSeats();
		System.out.println(people);
		System.out.println(j);		
	}
}
