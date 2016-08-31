/*input
5 5
2 4 9 2 5
*/

import java.io.*;
import java.util.*;

class TWODOGS{
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
		int inp[] = intarrinp();
		int n = inp[0], k = inp[1];
		int a[]  = intarrinp();
		Map<Integer, Integer> d = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i += 1){
			int x = (i < n/2 ? i+1 : n-i);
			if (d.get(a[i]) == null){
				d.put(a[i], x);
			}else{
				d.put(a[i], Math.min(d.get(a[i]), x));
			}
		}
		int inf = 100000000;
		int ans = inf;
		for(int i = 0; i < n; i += 1){
			if (d.get(k-a[i]) != null && a[i] != (k-a[i])){
				ans = Math.min(ans, Math.max(d.get(a[i]), d.get(k-a[i])));
			}
		}

		System.out.println((ans==inf) ? -1 : ans) ;

	}

}

