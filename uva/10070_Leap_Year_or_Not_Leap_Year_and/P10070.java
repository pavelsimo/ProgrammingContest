/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10070  Java  "Math, Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class P10070 {

	public static boolean isleapyear(BigInteger year) {
		if (BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(400)))) return true;
		if (BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(100)))) return false;
		if (BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(4)))) return true;
		return false;
	}

	public static boolean ishuluculu(BigInteger year) {
		return BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(15)));
	}

	public static boolean isbulukulu(BigInteger year) {
		return isleapyear(year) && BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(55)));
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int opt;
		int tc = 0;
		while (in.hasNext()) {
			BigInteger n = in.nextBigInteger();
			if(tc++ > 0) System.out.println();
			opt = 0;
			if (isleapyear(n)) opt |= 1;
			if (ishuluculu(n)) opt |= 2;
			if (isbulukulu(n)) opt |= 4;
			if (opt == 0) System.out.println("This is an ordinary year.");
			if ((opt & 1)!=0) System.out.println("This is leap year.");
			if ((opt & 2)!=0) System.out.println("This is huluculu festival year.");
			if ((opt & 4)!=0) System.out.println("This is bulukulu festival year.");
		}
	}
}
