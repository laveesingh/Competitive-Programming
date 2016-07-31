import java.util.*;
import java.io.*;

public class treeMapVsHashMap{
	public static int M = 1000000;
	public static void main(String args[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		TreeMap<Integer, Integer> tm = new TreeMap<Integer, Integer>();


		// long start = System.currentTimeMillis();

		for(int i = 0; i < M; i += 1){
			hm.put(i, i/2);
		}

		// long end = System.currentTimeMillis();
		// System.out.println("HashMap took " + (end-start) + " time!");

		// start = System.currentTimeMillis();

		// for(int i = 0; i < M; i += 1){
		// 	tm.put(i, i/2);
		// }ja

		// end = System.currentTimeMillis();

		// System.out.println("TreeMap took " + (end-start) + " time!");

	}
}