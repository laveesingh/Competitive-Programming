import java.io.*;
import java.util.*;

class Main{
	private static int N = 100001;
	private static int[] Array = new int[N];
	public static int bsearch(int x, int i, int j){
		if(i == j && Array[i] == x) return i;
		if(i == j && Array[i] != x) return -1;
		int mid = (i+j)/2;
		if(Array[mid] >= x) return bsearch(x, i, mid);
		return bsearch(x, mid+1, j);
	}

	public static void main(String args[]) throws IOException{
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		//Scanner input = new Scanner(System.in);
		String temp[];
		temp = input.readLine().split(" ");
		int n = Integer.parseInt(temp[0]), q = Integer.parseInt(temp[1]);
		temp = input.readLine().split(" ");
		for(int i = 0; i < n; i++)
			Array[i] = Integer.parseInt(temp[i]);	
		for(int i = 0; i < q; i++){
			int x = Integer.parseInt(input.readLine());
			System.out.println(bsearch(x, 0, n-1));
		}

	}
}

