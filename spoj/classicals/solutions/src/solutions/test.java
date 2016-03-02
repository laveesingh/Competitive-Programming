package solutions;

import java.util.Scanner;

public class test {
	
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		while (true){
			
			int n = input.nextInt();
			if (n == 42) break;
			System.out.println(n);
		}
	}

}
