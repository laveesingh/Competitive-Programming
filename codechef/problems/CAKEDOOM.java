/*input
1
2
??1?
*/

import java.io.*;
import java.util.*;

class CAKEDOOM{
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

	public static String solve(String a, int k){
		int n = a.length();
		if (n > 1 && k < 2) return "NO";
		char [] ac = a.toCharArray();
		for(int i = 0; i < n; i += 1){
			if(ac[i] == ac[(i+1)%n] && ac[i] != '?' && i != (i+1)%n){
				// System.out.println("i:"+i+"i+1%n"+((i+1)%n));
				return "NO";
			}
			if(ac[i] != '?' && ac[i]-'0' >= k){
				// System.out.println("a["+i+"]:"+ac[i]);
				return "NO";
			}

		}
		
		for(int i = 0; i < n; i += 1){
			if (ac[i] == '?'){
				if(ac[(i-1+n)%n] == '0' || ac[(i+1)%n] == '0'){
					if(k < 2) return "NO";
					if(ac[(i-1+n)%n] == '1' || ac[(i+1)%n] == '1'){
						if (k < 3) return "NO";
						ac[i] = '2';
					}else{
						ac[i] = '1';
					}
				}else{
					ac[i] = '0';
				}
			}
		}
		for(int i = 0; i < n; i += 1){
			if(ac[i] == ac[(i+1)%n] && ac[i] != '?' && i != (i+1)%n){
				return "NO";
			}
			if(ac[i]-'0' >= k) return "NO";
		}
		return new String(ac);
	}

	public static void main(String args[])throws IOException{
		int t = input();
		while (t-- > 0){
			int n = input();
			String a = raw_input();
			if(a.charAt(0) !='?'){
				System.out.println(solve(a, n));
			}else{
				String ans = "NO";
				for(int k = 0; k < n; k += 1){
					String first = String.valueOf(k);
					String temp = solve(first+a.substring(1), n);
					if(temp != "NO"){
						ans = temp;
						break;
					}else{
						// do nothing
					}
				}
				System.out.println(ans);
			}
		}
	}

}

