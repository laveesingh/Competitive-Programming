import java.io.*;
import java.util.*;

public class stringConstruction{
	public static void main(String args[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(input.readLine());
		while(t-- > 0){
			String a = input.readLine();
			Set<Character> set = new HashSet<Character>();
			for(int i = 0; i < a.length();i += 1){
				set.add(a.charAt(i));
			}
			int ans = set.size();
			System.out.println(ans);
		}
	}
}