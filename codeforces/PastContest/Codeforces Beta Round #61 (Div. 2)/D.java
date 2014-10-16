import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static int MAXN = 1002;
	public static boolean prime[] = new boolean[1002];
	public static long PF[] = new long[1002];
	public static int M = 0;

	public static void sieve() {
		for (int i = 0; i < MAXN; ++i)
			prime[i] = true;
		prime[0] = prime[1] = false;
		for (int i = 2; i < MAXN; ++i) {
			if (prime[i]) {
				PF[M++] = i;
				for (int j = i + i; j < MAXN; j += i)
					prime[j] = false;
			}
		}
	}

	public static void main(String[] args) {
		sieve();
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		if (n == 2) {
			System.out.println("-1");
		} else {
			BigInteger X[] = new BigInteger[1002];
			for (int i = 0; i < n; ++i) {
				BigInteger prod = BigInteger.ONE;
				for (int k = 0; k < 2; ++k)
					prod = prod.multiply(BigInteger.valueOf(PF[i + k]));
				X[i] = prod;
			}
			for (int i = 0; i < n; ++i) {
				for (int j = i + 2; j < n; ++j)
					X[j] = X[j].multiply(BigInteger.valueOf(PF[i]));
				System.out.println(X[i]);
			}
		}
	}
}
