/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10494  C++  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			BigInteger a = in.nextBigInteger();
			String opt = in.next();
			BigInteger b = in.nextBigInteger();
			if (opt.contains("%"))
				System.out.println(a.mod(b).toString());
			else
				System.out.println(a.divide(b).toString());
		}
	}
}
