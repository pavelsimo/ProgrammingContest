/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  713  C++  "String Manipulation, Simple Math" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	public static String format(String s) {
		int n = s.length();
		int index = 0;
		for (int i = 0; i < n; i++) {
			if(s.charAt(i) != '0') {
				index = i;
				break;
			}
		}
		return s.substring(index);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int TC = in.nextInt();
		while(TC-- > 0) {
			StringBuffer a = new StringBuffer(in.next());
			StringBuffer b = new StringBuffer(in.next());
			BigInteger x = new BigInteger(a.reverse().toString());
			BigInteger y = new BigInteger(b.reverse().toString());
			BigInteger z = x.add(y);
			String ans = new StringBuffer(z.toString()).reverse().toString();
			System.out.println(format(ans));
		}
	}	
}
