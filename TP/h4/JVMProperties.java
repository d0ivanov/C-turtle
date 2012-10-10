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
