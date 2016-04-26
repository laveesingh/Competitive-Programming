import java.util.Scanner;

public class C71a{

	public static String solve(String a){
		char b  = a.charAt(0);
		char e = a.charAt(a.length()-1);
		int length = a.length();
		String ans = b + String.valueOf(length-2) + e;
		return ans;
	}

	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while (t-- > 0){
			String a = input.next();
			if (a.length() <= 10) System.out.println(a);
			else System.out.println(solve(a));
		}
	}
}