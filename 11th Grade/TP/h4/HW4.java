/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се създаде програма, която да изкарва на екрана стойността на системните свойства по
зададени от командния ред имена на свойствата. Програмата трябва да приема и
невалидни имена. Ако последния подаден аргумент от командния ред е up то стойностите
показани в изхода трябва да са сортиран във възходящ ред. Ако последната стойност е
down изходът трябва да е сортиран в низходящ ред. Стойността по подразбиране, ако не е
посочено up или down, е up.
*/

import java.util.*;
import java.util.Arrays;

public class HW4 {
	public static void main(String[] args){
		Vector<String> args_ = new Vector<String>(); // vector for args
		int argc = 0; // arg count (inspired by C++)
		boolean order = true; // false = up (default sort is up)
		
// ######### Reading arguments and filling them in array (if they are valid) #########
		
		for (String str : args) {
			if (str.equals("down")){ // if the current arg == sort order
				order = false; // if the order is down then order = false (down)
			}else{
				if (System.getProperty(str) != null){ // if the current arg is valid property name
					args_.add(str); // add the valid property name
					argc++;
				}else{
					System.out.println("The argument '" + str + "' is invalid. How can you give me invalid arguments! I can not work like this! Strike!");
				}
			}
		}

// ######### Sorting results #########
		
		String[] arr = new String[args_.size()]; // array of strings for arguments
		args_.toArray(arr); // vector to array
		String[] arrRes = new String[args_.size()]; // array of strings for results
		
		for (int i = 0; i < argc; i++){ // filling array of results with the results
			arrRes[i] = System.getProperty(arr[i]);
		}
		
		if (order){
			Arrays.sort(arrRes, Collections.reverseOrder()); // sorting in down order
		}else{
			Arrays.sort(arrRes); // sorting in default (up) order
		}
		
		String temp;
		for (int i = 0; i < argc; i++){ // rearanging array of arguments so that System.getProperty(arr[i]) == arrRes[i]
			for (int j = 0; j < argc; j++){
				if (System.getProperty(arr[i]) == arrRes[j]){
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		
		for (int i = 0; i < argc; i++){ // showing the results
			System.out.println("\t" + arr[i] + " --- " + System.getProperty(arr[i]));
		}
	}
}
