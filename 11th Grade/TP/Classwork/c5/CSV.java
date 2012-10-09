import java.io.*;
import java.util.Arrays;

public class CSV{

	public static void main(String[] arg) throws Exception {
		
		BufferedReader CSVFile = new BufferedReader(new FileReader("example.csv"));

	  	String dataRow = CSVFile.readLine();
		
		int res = 0;
		
		boolean bool = true;
		
		while (dataRow != null){
			if (bool){
				bool = false;
			} else {
				String[] dataArray = dataRow.split(",");
	
				res += Integer.parseInt(dataArray[5]);
			}
			dataRow = CSVFile.readLine();
		}

		CSVFile.close();
		System.out.println(res);
	}
}
