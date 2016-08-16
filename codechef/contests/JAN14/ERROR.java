/*input
2
11111110
10101010101010
*/

import java.io.*;
import java.util.*;

class ERROR{
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
			String a = raw_input();
			String ans = "Bad";
			for (int i = 1; i < a.length()-1; i += 1){
				if (a.charAt(i) == '1' && a.charAt(i-1) == '0' && a.charAt(i+1) == '0'){
					ans = "Good";
					break;
				}else if(a.charAt(i) == '0' && a.charAt(i-1) == '1' && a.charAt(i+1) == '1' ){
					ans = "Good";
					break;
				}
			}
			System.out.println(ans);
		}
	}

}

