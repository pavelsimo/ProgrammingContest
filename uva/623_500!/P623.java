/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  623  C++  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			int n = in.nextInt();
			BigInteger ans = BigInteger.ONE;
			for (int i = 1; i <= n; ++i)
				ans = ans.multiply(new BigInteger(String.valueOf(i)));
			System.out.println(String.format("%d!", n));
			System.out.println(ans);
		}
	}
}
