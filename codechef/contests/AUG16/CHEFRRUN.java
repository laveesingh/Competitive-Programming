/*input
3
4
1 1 1 1
4
3 0 0 0
4
0 0 0 2
*/

import java.io.*;
import java.util.*;

class CHEFRRUN{
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
		while (t-- > 0){
			int n = input();
			int [] a = intarrinp();
			boolean isMagical[] = new boolean[n];
			Arrays.fill(isMagical, false);
			boolean isFuck[] = new boolean[n];
			Arrays.fill(isFuck, false);

			for (int i = 0; i < n; i += 1){
				Set<Integer> path = new HashSet<Integer>();
				Stack<Integer> st = new Stack<Integer>();
				int j = i;
				while (true){
					if(isMagical[j]){
						break;
					}else if(path.contains(j) && !st.empty()){
						isMagical[j] = true;
						isFuck[j] = false;
						int cur = st.pop();
						while(cur != j){
							isMagical[cur] = true;
							isFuck[cur] = false;
							cur = st.pop();
						}
						break;
					}else if(isFuck[j]){
						break;
					}else{
						path.add(j);
						st.push(j);
						isFuck[j] = true;
						j = (j + a[j] + 1) % n;
					}
				}
			}

			int cnt =0;
			for (int i = 0; i < n; i += 1){
				if (isMagical[i]){
					// System.out.println(i + " is magical");
					cnt++;
				}
			}
			System.out.println(cnt);
		}
	}

}

