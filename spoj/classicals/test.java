import java.util.Scanner; 
public class test{ 
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int sum = 0;
		for (int i = 0; i < 10; i += 1){
			sum += input.nextInt();
		}
		System.out.println("The total sum is: " + sum );
	}
}
