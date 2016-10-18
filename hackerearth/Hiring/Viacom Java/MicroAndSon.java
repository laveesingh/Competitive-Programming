import java.io.*;

public class MicroAndSon{
	static boolean ispal(String a){

		String rev = new StringBuilder(a).reverse().toString();
//		System.out.println("Comparing " + a + " and " + rev );
		return a.equals(rev);
	}
	public static void main(String args[])throws IOException{
		int [] dp = new int[2400];
		dp[0] = 1;
		for(int i = 1; i < 2400; i += 1){
			String si = String.format("%04d", i);
			if(ispal(si)) dp[i] = dp[i-1] + 1;
			else dp[i] = dp[i-1];
		}
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(input.readLine());
		for(int test = 0; test < T; test += 1){
			String temp[] = input.readLine().split(" ");
			int a = Integer.parseInt(temp[0]);
			int b = Integer.parseInt(temp[1]);
			int ans = 0;
			if (a == 0) ans = dp[b];
			else ans = dp[b] - dp[a-1];
			System.out.println(ans);
		}
	}
}
