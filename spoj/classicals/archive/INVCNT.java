import java.io.*;
import java.util.*;

class Main{
	private static int N = 200001;
	private static long [] a = new long[N], temp = new long[N];
	public static void main(String args[]) throws IOException{
//		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		Scanner input = new Scanner(System.in);
//		long t = Integer.parseInt(input.readLine()), n;
		long n,t = input.nextInt();
		while(t-- > 0){
			//n = Integer.parseInt(input.readLine());
			n = input.nextInt();
			for(int i = 0; i < n; i += 1)
				a[i] = input.nextInt();
//				a[i] = Integer.parseInt(input.readLine());
			System.out.println(mergeSort(0, n-1));
		}
	}
	private static long mergeSort(long i, long j){
		long count = 0;
		if(i < j){
			long mid = (i+j)/2;
			count += mergeSort(i, mid);
			count += mergeSort(mid+1, j);
			count += merge((int)i, (int)j);
		}
		return count;
	}
	private static long merge(int left, int right){
		long mid = (left + right)/2;
		int  i = left, j = (int)mid+1, k = left;
		long count = 0;
		while(i <= mid && j <= right){
			if(a[i] <= a[j]){
				temp[k++] = a[i++];
			}else{
				temp[k++] = a[j++];
				count += (mid - i + 1);
			}
		}
		while(i <= mid) temp[k++] = a[i++];
		while(j <= right) temp[k++] = a[j++];
		for(i = left; i <= right; i++) a[i] = temp[i];
		return count;
	}
}

