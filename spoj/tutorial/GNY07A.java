import java.io.*;
import java.util.*;

class Main{
	public static void main(String arg[]) throws IOException{
	//	BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		int game = 1;
		while(t-->0){
			int ind = input.nextInt();
			StringBuilder sb = new StringBuilder(input.next());
			sb.deleteCharAt(ind-1);
			System.out.println(game++ + " " + sb.toString());
		}
	}
}
