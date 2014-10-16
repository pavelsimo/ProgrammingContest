/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10220  C++  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class P10220 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			int n = in.nextInt();
         int ans = 0;
			BigInteger x = BigInteger.ONE;
			for (int i = 1; i <= n; ++i)
				x = x.multiply(new BigInteger(String.valueOf(i)));
			String s = x.toString();
			for (int i = 0; i < s.length(); i++)
				ans += s.charAt(i) - '0';
			System.out.println(ans);
		}
	}
}
