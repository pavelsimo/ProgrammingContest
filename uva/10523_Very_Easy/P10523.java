/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10523  C++  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class Main {	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			int n = in.nextInt();
			int A = in.nextInt();
			BigInteger ans = BigInteger.ZERO;
			for(int i = 1; i <= n; ++i) {
				BigInteger x = new BigInteger(String.valueOf(A));
				x = x.pow(i);
				x = x.multiply(new BigInteger(String.valueOf(i)));
				ans = ans.add(x);
			}
			System.out.println(ans.toString());
		}
	}
}
