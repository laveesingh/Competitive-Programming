import java.math.*;
import java.io.*;

class _13{

	public static void main(String args[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int n  = Integer.parseInt(input.readLine());
		BigInteger ans = new BigInteger("0");
		for(int i = 0; i < n; i += 1){
			ans = ans.add(new BigInteger(input.readLine()));
		}
		String res = String.valueOf(ans);
		System.out.println("res: " + res );
		for(int i = 0; i < 10; i += 1){
			System.out.print(res.charAt(i));
		}
		System.out.println();
	}

}
