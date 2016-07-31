import java.io.*;
import java.util.*;

public class CHSGMNTS{
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

	public static int input()throws IOException{
		return Integer.parseInt(br.readLine());
	}

	public static String raw_input()throws IOException{
		return br.readLine();
	}

	public static int process(int a){
		return (a*(a+1))/2;
	}

	public static int solve(int a[]){
		int n = a.length;
		int ans = 0;
		for (int k = 1; k < n; k += 1){
			Set<Integer> set = new HashSet<Integer>();
			for (int l = k; l < n; l += 1){
				set.add(a[l]);
				// int bool[] = new int[k];
				Vector<Integer> v = new Vector<Integer>();
				for (int i = 0; i < k; i += 1){
					if (set.contains(a[i])){
						// bool[i] = 1;
						v.add(i);
					}else{
						// bool[i] = 0;
					}
				}
				int cur = 0;
				if (v.size() == 0) cur += process(k);
				if(v.size() >= 1){
					cur += process(v.firstElement());
					cur += process(k-v.lastElement()-1);
				}
				if(v.size() >= 2){
					for (int i = 0; i < v.size()-1; i += 1){
						cur += process(v.get(i+1)-v.get(i)-1);
					}
				}
				ans += cur;
			}
		}
		return ans;
	}

	public static void main(String args[])throws IOException{
		int t = input();
		while (t-- > 0){
			int n = input();
			int a[] = intarrinp();
			System.out.println(solve(a));
		}
	}
}