
import java.util.*;

class MyMapNode{
	private char key;
	private int val;
	public MyMapNode(char k, int v){
		this.key = k;
		this.val  = v;
	}


}

public class STRPALIN{
	public static boolean solve(String a, String b){
		HashMap<Character, Object> am = new HashMap<Character, Object>();
		HashMap<Character, Object> bm = new HashMap<Character, Object>();
		for (char x: a.toCharArray()){
			am.put(x, 1);
		}
		for (char x: b.toCharArray()){
			bm.put(x, 1);
		}
		String alphs = "abcdefghijklmnopqrstuvwxyz";
		for (char x: alphs.toCharArray()){
			if (am.containsKey(x) && bm.containsKey(x)) return true;
		}
		return false;
	}
	public static void main(String argsg[]){
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		while (t-- > 0){
			String a  = input.next();
			String b = input.next();
			System.out.println(solve(a, b) ? "Yes" : "No");

		}
	}

}