/*input
l 30
*/

import java.util.Scanner;

class test{

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		String a = sc.next();
		int b = sc.nextInt();
		System.out.printf("%15s%03d\n", a,b);
	}
}