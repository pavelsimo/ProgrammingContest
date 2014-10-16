/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  495  C++  "Bignum, Simple Math" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int maxn = 5010;
		BigInteger DP[] = new BigInteger[maxn];
		DP[0] = BigInteger.ZERO;
		DP[1] = BigInteger.ONE;
		for (int i = 2; i < maxn; i++)
			DP[i] = DP[i - 1].add(DP[i - 2]);
		while (in.hasNext()) {
			int n = in.nextInt();
			String out = String.format("The Fibonacci number for %d is %s", n,DP[n].toString());
			System.out.println(out);
		}
	}

}
