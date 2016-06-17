import java.io.*;

public class SALARY{
	public static int sum(int[] a){
		int sum = 0;
		for (int i = 0; i < a.length; i += 1){
			sum += a[i];
		}
		return sum;
	}
	public static int min(int[] a){
		int min = 100000;
		for (int i = 0; i < a.length; i += 1){
			if(a[i] < min) min = a[i];
		}
		return min;
	}
	public static void main(String args[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(input.readLine());
		while(t-- > 0){
			int n = Integer.parseInt(input.readLine());
			String[] inputArray = input.readLine().split(" ");
			int[] intInputArray = new int[n];
			for (int i = 0; i < n; i += 1){
				intInputArray[i] = Integer.parseInt(inputArray[i]);
			}
			int summation = sum(intInputArray);
			int minimum = min(intInputArray);
			System.out.println(summation-(minimum*n));
		}
	}
}