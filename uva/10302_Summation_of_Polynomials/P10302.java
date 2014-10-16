/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10302  Java  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;

public class P10302 {
	
	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		int maxn = 50000;
		BigInteger a[] = new BigInteger[maxn+10];
		BigInteger ans = BigInteger.ZERO;;
		for (int i = 1; i <= maxn; i++) {
			ans = ans.add(BigInteger.valueOf(i).pow(3));
			a[i] = ans;
		}
		while(in.hasNext()) {
			int n = in.nextInt();
			System.out.println(a[n]);
		}		
	}
}
