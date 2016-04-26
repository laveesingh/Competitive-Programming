import java.io.*;

class ACRONYM{

	public static boolean isUpper(String a){
		if (a.length() < 2) return false;
		char [] arr = a.toCharArray();

		for (char x: arr){
			if (!Character.isUpperCase(x)){
				return false;
			}
		}
		return true;
	}

	public static void main(String ars[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String a = input.readLine();
		//String b = "This is a sentence to be considered!";
		int count = 0;
		for (String s: a.split(" ")){
			if (isUpper(s)) count += 1;
		}
		System.out.println(count);
	}
}