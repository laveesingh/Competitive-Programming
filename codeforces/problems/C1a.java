import java.util.Scanner;

public class C1a{
	public static void main(String argss[]){
		Scanner input = new Scanner(System.in);
		long n, m, a, ans;
		n = input.nextLong();
		m = input.nextLong();
		a = input.nextLong();
		ans = (long)(Math.ceil((double)n/a) * Math.ceil((double)m/a));
		System.out.println(ans);
	}
}