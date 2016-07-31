import java.io.*;
import java.util.*;

public class EqualStacks{
	public static void main(String args[])throws IOException{
		BufferedReader input2 = new BufferedReader(new InputStreamReader(System.in));
		Scanner input = new Scanner(System.in);
		int an, bn, cn;

		String temp[] = input2.readLine().split(" ");
		an = Integer.parseInt(temp[0]);
		bn = Integer.parseInt(temp[1]);
		cn = Integer.parseInt(temp[2]);

		String a[] = input2.readLine().split(" ");
		String b[] = input2.readLine().split(" ");
		String c[] = input2.readLine().split(" ");
		
		Queue<Integer> aq = new LinkedList<Integer>();
		Queue<Integer> bq = new LinkedList<Integer>();
		Queue<Integer> cq = new LinkedList<Integer>();
		
		long as = 0, bs = 0, cs = 0;
		for (int i = 0; i < a.length; i += 1){
			int cur = Integer.parseInt(a[i]);
			aq.add(cur);
			as += cur;
		}
		for (int i = 0; i < b.length; i += 1){
			int cur = Integer.parseInt(b[i]);
			bq.add(cur);
			bs += cur;
		}
		for (int i = 0; i < c.length; i += 1){
			int cur = Integer.parseInt(c[i]);
			cq.add(cur);
			cs += cur;
		}
		// System.out.println("The three sums are " + as + " " + bs + " " + cs);
		while (as != bs || bs != cs){
			if (as > bs || as > cs){
				int cur = aq.poll();
				as -= cur;
				// System.out.println("as decreased by " + cur);
			}

			if (bs > as || bs > cs){
				int cur = bq.poll();
				bs -= cur;
				// System.out.println("bs decreased by " + cur);
			}
			if (cs > as || cs > bs){
				int cur = cq.poll();
				cs -= cur;
				// System.out.println("cs decreaed by " + cur);
			}
		}

		// System.out.println(as + " " + bs + " " + cs);
		System.out.println(as);


	}
}