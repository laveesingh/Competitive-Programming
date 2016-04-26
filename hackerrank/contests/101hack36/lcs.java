import java.util.*;
public class lcs{
    public static int arr[][];
    public static void lcs(String s1, String s2) {
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                else
                    arr[i][j] = Math.max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    public static Set<String> lcs(String s1, String s2, int len1, int len2) {
        if (len1 == 0 || len2 == 0) {
            Set<String> set = new HashSet<String>();
            set.add("");
            return set;
        }
        if (s1.charAt(len1 - 1) == s2.charAt(len2 - 1)) {
            Set<String> set = lcs(s1, s2, len1 - 1, len2 - 1);
            Set<String> set1 = new HashSet<>();
            for (String temp : set) {
                temp = temp + s1.charAt(len1 - 1);
                set1.add(temp);
            }
            return set1;
        } else {
            Set<String> set = new HashSet<>();
            Set<String> set1 = new HashSet<>();
            if (arr[len1 - 1][len2] >= arr[len1][len2 - 1]) {
                set = lcs(s1, s2, len1 - 1, len2);
            }
            if (arr[len1][len2 - 1] >= arr[len1 - 1][len2]) {
                set1 = lcs(s1, s2, len1, len2 - 1);
            }
            for (String temp : set) {
                set1.add(temp);
            }
            //System.out.println("In lcs" + set1);
            return set1;

        }
    }


    public static void main(String[] args) {
        String s1 = "acabe";
        String s2 = "aabce";
        arr = new int[s1.length() + 1][s2.length() + 1];
        lcs(s1, s2);
        System.out.println(lcs(s1, s2, s1.length(), s2.length()));
    }
}