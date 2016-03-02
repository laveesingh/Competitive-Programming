package solutions;
import java.io.*;
public class staircase {
	
	public static void print_hash(int n, int m){
		for (int i = 1; i <= m; i += 1){
			System.out.print(" " );
			
		}
		for (int i = 1; i <= n; i += 1){
			System.out.print("#");
		}
		System.out.println();
	}
	
	public static void main(String args[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(input.readLine());
		for (int i = 1; i <= n; i += 1){
			print_hash(i, n-i);
		}
	}
}
