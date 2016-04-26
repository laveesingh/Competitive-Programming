import java.util.Scanner;

public class BYTESM2{
	public static void main(String arguments[]){
		Scanner input = new Scanner(System.in);
		int [][]a = new  int[111][111];
		int t, m, n;
		t = input.nextInt();
		while (t-- > 0){
			m = input.nextInt();
			n = input.nextInt();
			for (int i = 1; i <= m; i += 1){
				for (int j = 1; j <= n; j += 1){
					a[i][j] = input.nextInt();
				}
			}
			for (int i = 2; i <= m; i += 1){
				for (int j = 1; j <= n; j += 1){
					a[i][j] += Math.max(a[i-1][j], Math.max(a[i-1][j-1], a[i-1][j+1]));
				}
			}
			int temp = a[m][0];
			for (int i = 1; i <= n; i += 1){
				if (a[m][i] > temp) temp = a[m][i];
			}
			System.out.println(temp);
		}
	}
}