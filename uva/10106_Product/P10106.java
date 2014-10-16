/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10106  C++  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			BigInteger a = in.nextBigInteger();
			BigInteger b = in.nextBigInteger();
			System.out.println(a.multiply(b).toString());
		}
	}	
}
