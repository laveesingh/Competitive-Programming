/*input
3
5
1 4 6 8 10
3
2 2 9
2
156 13
*/


import java.io.*;
import java.util.*;

class dual_issues{
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
	
	public static int isprime[] = new int[10000];

	public static void sieve(){
		Arrays.fill(isprime, 1);
		isprime[1] = 0;
		isprime[0] = 0;
		for (int i = 2; i <= 100; i += 1){
			if(isprime[i] == 1){
				for (int j = i*i; j < 10000; j += i){
					isprime[j] = 0;
				}
			}
		}
	}

	public static void main(String args[])throws IOException{
		int t = input();
		sieve();
		while(t-- > 0){
			int n = input();
			int a[] = intarrinp();
			Arrays.sort(a);
			int ans = -1;
			for (int i = n-1; i >= 0; i -= 1){
				if (isprime[a[i]] == 1){
					ans = a[i]*a[i];
					break;
				}
			}
			System.out.println(ans);
		}
	}

}

