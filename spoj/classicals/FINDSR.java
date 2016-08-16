/*input
abcabcabcabc
abcdefgh012
aaaaaaaaaa
abcab
aaaabbbbaaaabbbbaaaa
aaaabbbbaaaabbbbaaaa
*
*
*/

import java.io.*;
import java.util.*;

class FINDSR{
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

	public static Vector<Integer> LPS(String a){
		int n = a.length();
		Integer lps[] = new Integer[n];
		int len = 0, i = 1;
		lps[0] = 0;
		while(i < n){
			if(a.charAt(i) == a.charAt(len)){
				lps[i++] = ++len;
			}else{
				if(len != 0){
					len = lps[len-1];
				}else{
					lps[i++] = 0;
				}
			}
		}
		return(new Vector<Integer>(Arrays.asList(lps)));
	}

	public static void main(String args[])throws IOException{
		while (true){
			String a = raw_input();
			if (a.equals("*")) break;
			Vector<Integer> lps = LPS(a);
			// System.out.println("LPS Array: " + lps);
			int n = lps.lastIndexOf(0)+1;
			// System.out.println("last index is " + n);
			if(lps.elementAt(a.length()-1)%n != 0){
				System.out.println(1);
			}else{
				n = lps.elementAt(a.length()-1)/(n) + 1;
				System.out.println(n);
			}

		}
	}

}

