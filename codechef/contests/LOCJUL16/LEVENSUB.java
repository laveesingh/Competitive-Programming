import java.io.*;

public class LEVENSUB{

	///*
	public static BufferedReader input = new BufferedReader (new InputStreamReader(System.in));
	
	public static String raw_input()throws IOException{
		return input.readLine();
	}

	public static int input()throws IOException{
		return Integer.parseInt(input.readLine());
	}

	public static int[] arrinp(int n)throws IOException{
		String temp[] = input.readLine().split(" ");
		int [] a = new int[n];
		for (int i = 0; i < n; i += 1){
			a[i] = Integer.parseInt(temp[i]);
		}
		return a;
	}

	public static int arraysum(int a[]){
		int ans =  0;
		for (int x: a){
			ans += x;
		}
		return ans;		
	}
	//*/

	public static void main(String ars[])throws IOException{
		int t = input();
		while(t-- > 0){
			int n = input();
			int [] a = arrinp(n);
			int i = 0, j = n-1;
			int parity = arraysum(a);
			if (parity%2 == 0){
				System.out.println(n);
			}else{
				while (i < n && a[i]%2 == 0){
					i++;
				}
				int k = 0;
				while (j > 0 && a[j]%2 == 0){
					j--;
					k++;
				}
				
				int tod = Math.min(i,k);
				System.out.println(n-tod-1);
			}
		}

	}



}

