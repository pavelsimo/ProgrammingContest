public class PrefixCode {
	public String isOne(String[] words) {
		String res = "Yes";
		int n = words.length;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				if (words[j].startsWith(words[i]))
					return "No, " + i;
			}
		}
		return res;
	}

}


// Powered by FileEdit
// Powered by CodeProcessor
