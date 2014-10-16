import java.util.Arrays;
import java.util.Scanner;

public class ACMSCORE {

	public static int T[] = new int[1002];

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int TC = in.nextInt();
		int D, P, t_elapsed, penalty, n;
		for (int tc = 1; tc <= TC; ++tc) {
			D = in.nextInt();
			P = in.nextInt();
			for (int i = 0; i < P; ++i)
				T[i] = in.nextInt();
			Arrays.sort(T, 0, P);
			t_elapsed = 5;
			penalty = 0;
			for (n = 0; n < P; ++n) {
				if (t_elapsed + T[n] > D) break;
				t_elapsed += T[n];
				penalty += t_elapsed;
			}
			System.out.println(String.format("Case #%d: %d %d", tc, n, penalty));
		}
	}
}
