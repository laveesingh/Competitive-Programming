import java.io.*;
import java.util.*;

class Main{

	public static void main(String args[]) throws IOException{
//		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while(t-- > 0){
			int c = input.nextInt(), k = input.nextInt(), w = input.nextInt();
			if(c*w <= k) System.out.println("yes");
			else System.out.println("no");
		}
	}
}

