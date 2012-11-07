/*Технологично училище Електронни системи - http://www.elsys-bg.org/
 *клас : 11Б
 *номер : 22
 *име : Михаил Михайлов Здравков
 *задача : Да се разработи програма, в която има клас Контейнер и клас Топка, които имат следните методи 
 *(виж кода) и взаимодействат помежду си. 
 */
package ballsAndBoxes.Homework.TP.Code;

public class Main {
	
	public static void main(String[] args) {
		Ball b1 = new Ball(1);
		Box box = new Box(7);
		System.out.println(box.size()); // prints 7
		System.out.println(box.getCapacity()); // prints 7
		box.add(b1); 
		System.out.println(box.size()); // prints 7
		System.out.println(box.getCapacity()); // prints 6
		System.out.println(box.contains(b1)); // prints true
		Ball b2 = new Ball(2);
		box.add(b2);
		System.out.println(box.getCapacity()); // prints 5
		System.out.println(box.contains(b2)); // prints true
		box.remove(b1);
		System.out.println(box.getCapacity()); // prints 6
		System.out.println(box.contains(b1)); // prints false
	}

}
