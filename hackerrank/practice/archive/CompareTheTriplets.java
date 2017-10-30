import java.util.*;

public class CompareTheTriplets{
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int [] a = new int[3];
		int [] b = new int[3];
		for (int i = 0; i < 3; i += 1){
			a[i] = input.nextInt();
		}
		for (int i = 0; i < 3; i += 1){
			b[i] = input.nextInt();
		}
		int as = 0, bs = 0;
		for (int i = 0; i < 3; i += 1){
			if (a[i] < b[i]){
				bs += 1;
			}else if(a[i] > b[i]){
				as += 1;
			}
		}
		System.out.println(as + " " + bs);
	}
}