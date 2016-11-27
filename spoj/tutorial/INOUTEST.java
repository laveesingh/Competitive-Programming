import java.io.*;
import java.util.*;

class Main{

	public static void main(String args[]) throws IOException{
		BufferedReader input=new BufferedReader(new InputStreamReader(System.in));
		//Scanner input = new Scanner(System.in);
		int t= Integer.parseInt(input.readLine());
		while(t-- > 0){
			String temp[] = input.readLine().split(" ");
			System.out.println(Long.parseLong(temp[0]) * Long.parseLong(temp[1]));
		}

	}
}

