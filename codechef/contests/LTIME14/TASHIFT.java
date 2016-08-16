/*input
3
abc
def
*/

import java.io.*;
import java.util.*;

class TASHIFT{
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
		int n = input();
		String b = raw_input(), a = raw_input();
		a = a+a.substring(0,a.length()-1);
		int len = 0, i = 1;
		int lps[] = new int[a.length()];
		if(a.charAt(0) == b.charAt(0)){
			lps[0] = 1;
			len = 1;
		}else{
			lps[0] = 0;
		}
		while(i < a.length() && len < b.length()){
			// System.out.println("i " + i + " len " + len);
			if (a.charAt(i) == b.charAt(len)){
				lps[i++] = ++len;
			}else{
				if(len != 0){
					len = lps[len-1];
				}else{
					lps[i++] = 0;
				}
			}
		}
		int max = -1, ind = -1;
		for (i = 0; i < lps.length; i += 1){
			if (lps[i] > max){
				max = lps[i];
				ind = i;
			}
		}
		if(max == 0){
			System.out.println(0);
		}else{
			System.out.println(ind-lps[ind]+1);
		}
	}

}

