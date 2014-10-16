/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10925  C++  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int TC = 1;
		while (in.hasNext()) {
			int N = in.nextInt();
			int F = in.nextInt();
			if (N == 0 && F == 0) break;
			BigInteger sum = BigInteger.ZERO;
			for (int i = 0; i < N; ++i) {
				BigInteger x = in.nextBigInteger();
				sum = sum.add(x);
			}
			String out = String.format("Bill #%d costs %s: each friend should pay %s", TC++, sum.toString(), sum.divide(BigInteger.valueOf(F)));
			System.out.println(out);
			System.out.println();
		}

	}

}
