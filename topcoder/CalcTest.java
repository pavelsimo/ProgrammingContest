import java.util.*;

public class CalcTest {
	public String[] uniform(String[] numbers) {
		int n = numbers.length;
		String[] res = new String[n];
		for (int i = 0; i < n; ++i) {
			res[i] = "";
			String s = numbers[i];
			for (int j = 0; j < s.length(); ++j) {
				if (s.charAt(j) != ' ') {
					if (Character.isDigit(s.charAt(j)))
						res[i] += s.charAt(j);
					else
						res[i] += '.';
				}
			}
		}
		return res;
	}

}


// Powered by FileEdit
// Powered by CodeProcessor
