public class NinePuzzle {
	public int getMinimumCost(String init, String goal) {
		int res = 0;
		char color[] = { 'R', 'B', 'G', 'Y' };
		int N = init.length();
		int M = color.length;
		int a[] = new int[255];
		int b[] = new int[255];
		for (int i = 0; i < N; ++i) {
			if (init.charAt(i) != '.')
				a[init.charAt(i)]++;
			if (goal.charAt(i) != '.')
				b[goal.charAt(i)]++;
		}
		for (int i = 0; i < M; i++) {
			if (a[color[i]] != b[color[i]])
				res += Math.abs(a[color[i]] - b[color[i]]);
		}
		return res/2;
	}

}


// Powered by FileEdit
// Powered by CodeProcessor
