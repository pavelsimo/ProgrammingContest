/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  424  C++  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger ans = BigInteger.ZERO;
		while (in.hasNext()) {
			BigInteger x = in.nextBigInteger();
			if (BigInteger.ZERO.equals(x))
				break;
			ans = ans.add(x);
		}
		System.out.println(ans.toString());
	}
}
