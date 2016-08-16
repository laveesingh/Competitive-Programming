/*input
5
1 1
1 2
2 2
1 3
2 3
*/

import java.io.*;
import java.util.*;

class CHCHCL{
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

	public static void main(String args[])throws IOException{
		int t = input();
		while(t-- > 0){
			int n, m;
			int a[] = intarrinp();
			n = a[0];
			m = a[1];
			if(n%2 == 0 || m%2 == 0){
				System.out.println("Yes");
			}else{
				System.out.println("No");
			}
		}
	}


}

