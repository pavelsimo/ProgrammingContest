public class VerifyCreditCard {
	public String checkDigits(String cardNumber) {
		String res = "INVALID";
		int n = cardNumber.length();
		String s = "";
		int m = 0;
		if (n % 2 == 0)
			m = 1;
		for (int i = 0; i < n; ++i) {
			int a = (cardNumber.charAt(i) - '0');
			if ((i + 1) % 2 == m)
				a *= 2;
			s += a;
		}
		int sum = 0;
		for (int i = 0; i < s.length(); ++i)
			sum += (s.charAt(i) - '0');
		if (sum % 10 == 0)
			res = "VALID";
		return res;
	}

}


// Powered by FileEdit
// Powered by CodeProcessor
