/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10992  Java  "Ad Hoc, Big Num" */
import java.math.BigInteger;
import java.util.Scanner;

public class P10992 {

	public static boolean isLeapYear(BigInteger year) {
		if (BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(400))))
			return true;
		if (BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(100))))
			return false;
		if (BigInteger.ZERO.equals(year.mod(BigInteger.valueOf(4))))
			return true;
		return false;
	}

	public static boolean isDivisible(BigInteger n, int x) {
		return n.mod(BigInteger.valueOf(x)).compareTo(BigInteger.ZERO) == 0;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int TC = 0;
		int[] year = { 2, 5, 7, 11, 15, 20, 28, 36, 0 };
		String[] ghost = { "Tanveer Ahsan", "Shahriar Manzoor", "Adrian Kugel",
				"Anton Maydell", "Derek Kisman", "Rezaul Alam Chowdhury",
				"Jimmy Mardell", "Monirul Hasan", "K. M. Iftekhar" };
		while (in.hasNext()) {
			BigInteger n = in.nextBigInteger();
			if (n.compareTo(BigInteger.ZERO) == 0) break;
			if (TC > 0) System.out.println();
			TC++;
			boolean found = false;
			System.out.println(n);
			if (n.compareTo(BigInteger.valueOf(2148)) >= 0) {
				BigInteger x = n.subtract(BigInteger.valueOf(2148));
				for (int i = 0; i < ghost.length-1; i++) {
					if (isDivisible(x, year[i])) {
						found=true;
						System.out.println(String.format("Ghost of %s!!!",ghost[i]));
					}
				}
				if (isLeapYear(n)) {
					found = true;
					System.out.println(String.format("Ghost of %s!!!",ghost[8]));
				}
			}
			if (!found) System.out.println("No ghost will come in this year");
		}
	}

}
