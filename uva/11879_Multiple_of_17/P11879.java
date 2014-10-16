/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11879  Java  "Ad Hoc, Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class P11879 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			BigInteger x = in.nextBigInteger();
			if (x.compareTo(BigInteger.ZERO) == 0)
				break;
			if (x.mod(BigInteger.valueOf(17)).compareTo(BigInteger.ZERO) == 0)
				System.out.println("1");
			else
				System.out.println("0");
		}
	}
}
