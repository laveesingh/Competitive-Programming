import java.util.Scanner;

public class C4a{
	public static void main(String arguments[]){
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		if (n < 4 || n%2 == 1){
			System.out.println("NO");
		}else{
			System.out.println("YES");
		}
	}
}