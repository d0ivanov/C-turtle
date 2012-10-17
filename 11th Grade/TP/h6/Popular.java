import java.io.*;
import java.util.Arrays;

class Person{
	int number, written = 0;
	int[] from = new int[29], to = new int[29];
	
	Person(int num){
		this.number = num;
		this.written = 0;
	}
	
	Person(){
		this(0);
	}
	
	public int getNumber(){
		return number;
	}
	
	public int getWritten(){
		return written;
	}
	
	public int getFrom(int i){
		return from[i];
	}
	
	public int getTo(int i){
		return to[i];
	}
	
	public void setNumber(int val){
		 number = val;
	}
	
	public void setWritten(int val){
		 written = val;
	}
	
	public void setFrom(int index){
		 from[index] += 1;
	}
	
	public void setTo(int index){
		 to[index] += 1;
	}
	
	public void writtenPP(){
		written += 1;
	}
}

public class Popular {
	public static void main(String[] args) throws Exception{
		
		Person[] people = new Person[29];
		for(int i = 0; i < people.length; i++)
   	 	{
        		people[i] = new Person();
   		}
   		
		BufferedReader CSV = new BufferedReader(new FileReader("csvs/1.csv"));;
		
		for (int i = 1; i <= 29; i++) {
		 	File file=new File("csvs/" + (i + "") + ".csv");
			if (!file.exists()){
				continue;
			}
			
			CSV = new BufferedReader(new FileReader("csvs/" + (i + "") + ".csv"));
			String dataRow = CSV.readLine();
			
			for (int j = 0; j < 30; j++) {
				people[Integer.parseInt(dataRow)].writtenPP();
				System.out.println(people[Integer.parseInt(dataArray[j])].getWritten());
				if (j > 0){
					people[Integer.parseInt(dataArray[j])].setFrom(Integer.parseInt(dataArray[j-1]));
				}
				if (j + 1 < dataArray.length){
					people[Integer.parseInt(dataArray[j])].setTo(Integer.parseInt(dataArray[j+1]));
				}
			}
		}
		
		CSV.close();
		
//		for (int i = 0; i < people.length; i++){
//			System.out.println("Number " + i + ": ");
//			System.out.println(people[i].getWritten());
//			System.out.println();
//			for (int j = 0; j < people.length; j++){
//				System.out.printf("%d ", people[i].getFrom(j));
//			}
//			for (int j = 0; j < people.length; j++){
//				System.out.printf("%d ", people[i].getFrom(j));
//			}
//			System.out.println();
//		}
	}
}
