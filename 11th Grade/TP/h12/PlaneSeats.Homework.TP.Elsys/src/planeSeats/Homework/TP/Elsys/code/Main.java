/*
#school - ТУЕС - www.elsys-bg.org
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се реализираза задачата за подредба на пътници в самолет, но обектно ориентирано.
*/

package planeSeats.Homework.TP.Elsys.code;

public class Main {
	public static void main(String[] args) {
		Group g1 = new Group(); // group1 with unique id '1'
		Group g2 = new Group(); // group2 with unique id '2'
		Group g3 = new Group(); // group3 with unique id '3'
		Plane airbus = new Plane();
		Human h1 = new Human("Pesho", "Male");
		Human h2 = new Human("Gesho", "Male");
		Human h3 = new Human("Kesho", "Male");
		g1.add(h1);
		g1.add(h2);
		g1.add(h3);
		airbus.add(g1);
		Human h4 = new Human("Pena", "Female");
		g2.add(h4);
		airbus.add(g2);
		Human h5 = new Human("Gena", "Female");
		Human h6 = new Human("Nenka", "Female");
		Human h7 = new Human("Dancheto", "Female");
		g3.add(h5);
		g3.add(h6);
		g3.add(h7);
		airbus.add(g3);
		airbus.printSeats(); // 111 200
							 // 333 000
							 // ...
		Human h8 = new Human("Genadii", "Male");
		Human h9 = new Human("Neofritii", "Male");
		Group g4 = new Group();
		g4.add(h8);
		g4.add(h9);
		airbus.add(g4);
		airbus.printSeats(); // 111 244
							 // 333 000
							 // ...
		System.out.println(airbus.getGender("Female")); // 4
	}

}
