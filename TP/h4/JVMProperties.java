/*
/*
#school - ТУЕС
#class - 11Б
#num - 15
#name - Добромир Иванов
#task - Да се създаде програма, която да изкарва на екрана стойността на системните свойства по
зададени от командния ред имена на свойствата. Програмата трябва да приема и
невалидни имена. Ако последния подаден аргумент от командния ред е up то стойностите
показани в изхода трябва да са сортиран във възходящ ред. Ако последната стойност е
down изходът трябва да е сортиран в низходящ ред. Стойността по подразбиране, ако не е
посочено up или down, е up.c
*/

import java.util.*;
import java.util.Arrays;

public class JVMProperties{

	public static void main(String[] args) {
		boolean sortUp = true;
		Vector<String> results = new Vector<String>();
		
		for (String arg : args) {
			if (arg.equals("down")) {
				sortUp = false;
			}
			if (System.getProperty(arg) != null) {
				results.add(System.getProperty(arg));
			}
		}
		
		String[] resArr = new String[results.size()];
		resArr = results.toArray(resArr);
		if(sortUp){
			Arrays.sort(resArr);
		}else{
			Arrays.sort(resArr, Collections.reverseOrder());
		}
		
		for( int i = 0; i < resArr.length; i++ ){
			System.out.println(resArr[i]);
		}
	}
}
