import java.io.*;

public class CamelCase{

	public static void main(String args[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String a = input.readLine();
		int cnt = 0;
		for (int i = 0; i < a.length(); i += 1){
			char x = a.charAt(i);
			if (Character.isUpperCase(x)){
				cnt += 1;
			}
		}
		System.out.println(cnt+1);
	}
}