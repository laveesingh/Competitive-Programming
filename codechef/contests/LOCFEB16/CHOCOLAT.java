import java.io.*;
import java.util.Scanner;

public class CHOCOLAT{

	public static void main(String args[])throws IOError{
		//BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while (t-- > 0){
			int n = input.nextInt();
			int m = input.nextInt();
			if (n > m) System.out.println("Bipin " + (n-m));
			else if (n == m) System.out.println("No Winner");
			else System.out.println("Balaji " + (m-n));
		}

	}
}