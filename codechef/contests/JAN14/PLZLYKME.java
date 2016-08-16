/*input
2
5 1 5 1
10 2 2 2
*/

import java.io.*;
import java.util.*;

class PLZLYKME{
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	

	public static int[] intarrinp()throws IOException{
		String temp[]  = br.readLine().split(" ");
		int n = temp.length;
		int a[] = new int[n];
		for (int i = 0; i < n; i += 1){
			a[i] = Integer.parseInt(temp[i]);
		}
		return a;
	}

	public static String[] strarrinp()throws IOException{
		String temp[] = br.readLine().split(" ");
		return temp;
	}

	public static int input()throws IOException{
		return Integer.parseInt(br.readLine());
	}

	public static String raw_input()throws IOException{
		return br.readLine();
	}

	public static Scanner sc = new Scanner(System.in);


	public static void main(String args[])throws IOException{
		long t = sc.nextLong();
		while (t-- > 0){
			long l, d, s, c;
			l = sc.nextLong();
			d = sc.nextLong();
			s = sc.nextLong();
			c = sc.nextLong();
			String ans = l > s ? "DEAD AND ROTTING" : "ALIVE AND KICKING";
			while (d-- > 1){
				s *= (1+c);
				if (s >= l){
					ans = "ALIVE AND KICKING";
					break;
				}

			}
			System.out.println(ans);
		}

	}

}

