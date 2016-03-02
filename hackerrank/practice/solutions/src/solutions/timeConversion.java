package solutions;
import java.io.*;
public class timeConversion {

	public static void main(String args[])throws IOException{
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		String time  = input.readLine();
		String flag = time.substring(8);
		String hour;
		int h1 = Integer.parseInt(time.substring(0, 2));
		if (flag.equals("PM")){
			if (h1 != 12){
				h1 += 12;
			}
			hour = String.valueOf(h1);
		}
		else{
			if (h1 == 12) hour = "00";
			else{
				hour = time.substring(0,2);
			}
		}
		String ntime = hour + time.substring(2, 8);
		System.out.println(ntime);
	}
}
