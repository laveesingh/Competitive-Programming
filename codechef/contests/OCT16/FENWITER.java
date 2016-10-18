import java.io.*;

public class FENWITER{
	public static void main(String args[]) throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(input.readLine());
		while (t-- > 0){
			String a, b, c;
			int n;
			String temp[] = input.readLine().split(" ");
			a = temp[0];
			b = temp[1];
			c = temp[2];
			n = Integer.parseInt(temp[3]);
			long total = b.length()- b.replaceAll("1", "").length();
			total *= n;
			total += a.length() - a.replaceAll("1", "").length();
			total += c.length() - c.replaceAll("1", "").length();
			long first = 0, second = 0, third = 0;
			int i = c.length() - 1;
			while (i >= 0){
				if (c.charAt(i) == '0') break;
				i--;
			}
			third = c.length() - i - 1;
			if (third < c.length()){
				System.out.println(total - third + 1);
				continue;
			}
			i = b.length() - 1;
			while (i >= 0){
				if (b.charAt(i) == '0') break;
				i--;
			}
			second = b.length() - i - 1;
			if (second < b.length()){
				System.out.println(total - third-second + 1);
				continue;
			}
			i = a.length() - 1;
			while (i >= 0){
				if (a.charAt(i) == '0') break;
				i--;
			}
			first = a.length() - i - 1;
			System.out.println(total - first - second*n - third + 1);
		}
	}
}
