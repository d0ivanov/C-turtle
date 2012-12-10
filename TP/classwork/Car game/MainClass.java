package org.elsys.testExam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class MainClass {

	public static void main(String[] arg) {
		List<Vehicle> vehicleList = generateVehicles(5);
		printVehicles(vehicleList);
		while(true) {
			String[] args = parseArgs();
			if(args.length == 3) {
				for(Vehicle vehicle : vehicleList) {
					int registration = Integer.parseInt(args[0]);
					int x = Integer.parseInt(args[1]);
					int y = Integer.parseInt(args[2]);
					if(vehicle.getRegistration() == registration) {
						Coordinate position = new Coordinate();
						position.setX(x);
						position.setY(y);
						vehicle.setPosition(position);
					}
				}
			} else if (args.length == 4) {
				for(Vehicle vehicle : vehicleList) {
					int registration = Integer.parseInt(args[0]);
					int x = Integer.parseInt(args[1]);
					int y = Integer.parseInt(args[2]);
					int load = Integer.parseInt(args[3]);
					if(vehicle.getRegistration() == registration) {
						Coordinate position = new Coordinate();
						position.setX(x);
						position.setY(y);
						vehicle.setPosition(position);
						vehicle.load(load);
					}
				}
			}
			printVehicles(vehicleList);
		}
	}
	
	
	private static List<Vehicle> generateVehicles(int count) {
		List<Vehicle> vehicleList = new ArrayList<Vehicle>();
		for(int i = 0; i < count; i++) {
			Coordinate pos = new Coordinate();
			
			Vehicle car = new Car(i+1, pos);
			Vehicle truck = new Truck(i+5, pos);
			
			vehicleList.add(car);
			vehicleList.add(truck);
		}
		return vehicleList;
	}
	
	private static void printVehicles(List<Vehicle> vehicles) {
		for(Vehicle vehicle : vehicles) {
			vehicle.print();
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
}
