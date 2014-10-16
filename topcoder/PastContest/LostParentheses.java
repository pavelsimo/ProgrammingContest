public class LostParentheses {

	public int minResult(String e) {

		String[] op = e.split("-");
		int res = 0;

		for (int i = 0; i < op.length; i++) {

			int n = 0;
			String[] sum = op[i].split("[+]");

			for (int j = 0; j < sum.length; j++)
				n += Integer.valueOf(sum[j]);

			if (i == 0)
				res += n;
			else
				res -= n;
		}

		return res;
	}
}
