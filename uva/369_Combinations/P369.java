/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  369  Java  "Big Integer, Math" */
import java.math.BigInteger;
import java.util.Scanner;

public class P369 {
	public static void main(String[] args) {
		int maxn = 110;
		BigInteger memo[][] = new BigInteger[maxn][maxn];
		for (int i = 0; i < maxn; i++) 
			for (int j = 0; j < maxn; j++)
				memo[i][j] = BigInteger.ZERO;
		memo[0][1] = BigInteger.ONE;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 101; j++)
				memo[i][j] = memo[i - 1][j - 1].add(memo[i - 1][j]);
		}
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			int n = in.nextInt();
			int m = in.nextInt();
			if (n == 0 || m == 0) break;
			System.out.println(String.format("%d things taken %d at a time is %s exactly.", n, m,memo[n][m + 1].toString()));
		}
	}
}