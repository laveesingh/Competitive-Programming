import java.util.Scanner;

public class CHEFPATH{
	public static boolean solve(long n, long m){
		if (n == 1){
			if (m == 2) return true;
			return false;
		}
		if (m == 1){
			if (n == 2) return true;
			return false;
		}
		return (n%2 == 0) || (m%2 == 0);
	}
	public static void main(String argsum[]){
		Scanner input = new Scanner(System.in);
		int t;
		long  m, n;
		t = input.nextInt();
		while (t-- > 0){
			m = input.nextLong();
			n = input.nextLong();
			boolean ans = solve(m, n);
			if (ans){
				System.out.println("Yes");
			}else{
				System.out.println("No");
			}
		}
	}
}