/*input
1
6
-10 -49 73 -67 -7 51
4 6
*/

import java.io.*;
import java.util.*;

class pair{
	public static int f, s;
	public pair(int a, int b){
		this.f = a;
		this.s = b;
	}
	public String toString(){
		return "Pair("+this.f+", "+this.s+")";
	}
}

class CHEFCRUN{
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


	// Here's the starting point

	public static int n;
	public static Map<pair, Integer> dist = new HashMap<pair, Integer>();

	public static int nex(int i){
		return (i+1)%n;
	}

	public static int prev(int i){
		return (i-1+n)%n;
	}

	public static int pay(int i, int j){
		if(dist.get(new pair(i,j)) != null){
			return dist.get(new pair(i,j));
		}
		return dist.get(new pair(i, j));
	}

	public static int solve(int start, int end){
		int ans = 0, cost = 0, cost2 = 0, j = 0, i = start;
		while (i != end){
			ans += pay(i, nex(i));
			i = nex(i);
		}
		i = start;
		 cost = ans;
		 cost2 = ans;
		 j = end;
		while (j != prev(i)){
			cost2 += 2*pay(j, nex(j));
			ans = Math.min(cost2, ans);
			j = nex(j);
		}
		j = end;
		Map<Integer, Integer> dp = new HashMap<Integer, Integer>(), dpd = new HashMap<Integer, Integer>();
		dp.put(end, 0);
		dpd.put(end, 0);
		while (j != prev(i)){
			dpd.put(nex(j), dpd.get(j)+2*pay(j,nex(j)));
			dp.put(nex(j), Math.min(dp.get(j), dpd.get(nex(j))));
			j = nex(j);
		}
		while (i != end){
			cost += 2*pay(i, prev(i));
			ans = Math.min(ans, cost);
			cost2 = cost;
			cost2 += dp.get(prev(i));
			ans = Math.min(ans, cost2);
			i = prev(i);
		}
		return ans;
	}

	public static void main(String args[])throws IOException{
		int t = input();
		while(t-- > 0){
			dist.clear();
			n = input();
			int [] a = intarrinp();
			for (int i = 0; i < n; i += 1){
				dist.put(new pair(i, nex(i)), a[i]);
				System.out.println(dist.get(new pair(i, nex(i))));
			}
			System.out.println("Here's the dist map");
			for (Map.Entry<pair, Integer> entry: dist.entrySet()){
				System.out.println(entry.getKey() + " : " + entry.getValue());
			}
			System.out.println("Let me print the map explicitly");
			for (int i = 0; i < n; i += 1){
				System.out.println(i + ", " + nex(i) + " "+ dist.get(new pair(i,nex(i))));
			}
			int b[] = intarrinp();
			int st = b[0]-1, en = b[1]-1;
			System.out.println(Math.min(solve(st, en), solve(en, st)));
		}
	}

}

