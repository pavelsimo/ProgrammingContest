import java.math.BigInteger;

public class PerfectSequences {
	
	public String fixIt(int[] a) {
		String res = "No";
		int n = a.length;
		if(n==1) return "Yes";
		for (int i = 0; i < n; ++i) {
			BigInteger sum = BigInteger.ZERO;
			BigInteger prod = BigInteger.ONE;
			for (int j = 0; j < n; ++j) {
				if (i==j) continue;
				sum = sum.add(BigInteger.valueOf(a[j]));
				prod = prod.multiply(BigInteger.valueOf(a[j]));
			}
			if(prod.compareTo(BigInteger.ONE)==0) continue;
			BigInteger C = sum.divide(prod.subtract(BigInteger.ONE));
			if(C.compareTo(BigInteger.ZERO) >= 0 && BigInteger.valueOf(a[i]).compareTo(C)!=0) {
				if(sum.remainder(prod.subtract(BigInteger.ONE)).compareTo(BigInteger.ZERO)==0)
					return "Yes";
			}
		}
		return res;
	}

	// BEGIN CUT HERE
	public static void main(String[] args) {
		if (args.length > 0)
			for (int i = 0; i < args.length; ++i) {
				int casenum;
				try {
					casenum = Integer.parseInt(args[i]);
				} catch (NumberFormatException ex) {
					System.err.println("Illegal test case " + args[i]);
					continue;
				}
				PerfectSequencesHarness.run_test(casenum);
			}
		else
			PerfectSequencesHarness.run_test();
	}
	// END CUT HERE
}

// BEGIN CUT HERE
class PerfectSequencesHarness {
	public static void run_test() {
		run_test(-1);
	}

	public static void run_test(int casenum) {
		if (casenum != -1) {
			if (runTestCase(casenum) == -1)
				System.err.println("Illegal input! Test case " + casenum
						+ " does not exist.");
			return;
		}

		int correct = 0, total = 0;
		for (int i = 0;; ++i) {
			int x = runTestCase(i);
			if (x == -1) {
				if (i >= 100)
					break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			System.err.println("No test cases run.");
		} else if (correct < total) {
			System.err.println("Some cases FAILED (passed " + correct + " of "
					+ total + ").");
		} else {
			System.err.println("All " + total + " tests passed!");
		}
	}

	static boolean compareOutput(String expected, String result) {
		return expected.equals(result);
	}

	static String formatResult(String res) {
		return String.format("\"%s\"", res);
	}

	static int verifyCase(int casenum, long starttime, String expected,
			String received) {
		System.err.print("Example " + casenum + "... ");
		if (compareOutput(expected, received)) {
			System.err.print("PASSED");
			System.err.print("  " + (System.currentTimeMillis() - starttime)
					+ "ms");
			System.err.println();
			return 1;
		} else {
			System.err.print("FAILED");
			System.err.println("  " + (System.currentTimeMillis() - starttime)
					+ "ms");
			System.err.println("    Expected: " + formatResult(expected));
			System.err.println("    Received: " + formatResult(received));
			return 0;
		}
	}

	static int runTestCase(int casenum__) {
		long starttime__ = System.currentTimeMillis();
		switch (casenum__) {
		case 0: {
			int[] seq = { 1, 3, 4 };
			String expected__ = "Yes";

			return verifyCase(casenum__, starttime__, expected__,
					new PerfectSequences().fixIt(seq));
		}
		case 1: {
			int[] seq = { 1, 2, 3 };
			String expected__ = "No";

			return verifyCase(casenum__, starttime__, expected__,
					new PerfectSequences().fixIt(seq));
		}
		case 2: {
			int[] seq = { 1, 4, 2, 4, 2, 4 };
			String expected__ = "No";

			return verifyCase(casenum__, starttime__, expected__,
					new PerfectSequences().fixIt(seq));
		}
		case 3: {
			int[] seq = { 1000000, 1, 1, 1, 1, 2 };
			String expected__ = "Yes";

			return verifyCase(casenum__, starttime__, expected__,
					new PerfectSequences().fixIt(seq));
		}
		case 4: {
			int[] seq = { 8 };
			String expected__ = "Yes";

			return verifyCase(casenum__, starttime__, expected__,
					new PerfectSequences().fixIt(seq));
		}
		case 5: {
			int[] seq = { 2, 0, 2 };
			String expected__ = "No";

			return verifyCase(casenum__, starttime__, expected__,
					new PerfectSequences().fixIt(seq));
		}
		case 6: {
			int[] seq = 	{1, 1, 1, 1, 1, 1, 2};
			String expected__ = "Yes";

			return verifyCase(casenum__, starttime__, expected__,
					new PerfectSequences().fixIt(seq));
		}
			// custom cases

			/*
			 * case 6: { int[] seq = ; String expected__ = ;
			 * 
			 * return verifyCase( casenum__, starttime__, expected__, new
			 * PerfectSequences().fixIt( seq ) ); }
			 */
			/*
			 * case 7: { int[] seq = ; String expected__ = ;
			 * 
			 * return verifyCase( casenum__, starttime__, expected__, new
			 * PerfectSequences().fixIt( seq ) ); }
			 */
			/*
			 * case 8: { int[] seq = ; String expected__ = ;
			 * 
			 * return verifyCase( casenum__, starttime__, expected__, new
			 * PerfectSequences().fixIt( seq ) ); }
			 */
		default:
			return -1;
		}
	}
}

// END CUT HERE
