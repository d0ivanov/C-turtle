public class HelloWorld {
	public static void main(String [] args) {
		System.out.println("Hello cruel World!");
		int res = 0;
		for (int i = 0; i <= 100; i++) {
			res += i;
		}
		System.out.println(res);
		
		int num = 0;
		int arr[] = new int[10];
		for (int i = 0; num < 10; i++){
			if (i % 2 == 0){
				arr[num] = i;
				System.out.println(arr[num]);
				num ++;
			}
		}
	}
}
