import java.util.*;

public class CircularArrayRotation{
	public static void main(String arg[]){
		Scanner input = new Scanner(System.in);
		int n, q, k, m, temp;
		n = input.nextInt();
		k = input.nextInt();
		q = input.nextInt();


		Deque<Integer> a = new ArrayDeque<Integer>();

		for (int i = 0; i < n; i += 1){
			temp = input.nextInt();
			a.addLast(temp);
		}

		for (int i = 0; i < k; i += 1){
			temp = a.pollLast();
			a.addFirst(temp);
		}

		Iterator<Integer> it = a.iterator();

		int b[] = new int[n];
		for (int i = 0; i < n; i += 1){
			b[i] = it.next();
		}

		for(int i = 0; i < q; i += 1){
			m = input.nextInt();
			System.out.println(b[m]);
		}

	}
}