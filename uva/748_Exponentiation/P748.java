/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  748  C++  "Big Integer" */
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static String f(String s) {
		int n = s.length();
		int begin = 0;
		int end = 0;
		for (int i = 0; i < n; ++i) {
			if(s.charAt(i) != '0') {
				begin = i;
				break;
			}
		}
		for (int i = n-1; i >= begin; --i) {
			if(s.charAt(i) != '0') {
				end = i;
				break;
			}
		}
		return s.substring(begin,end+1);
	}
	public static void main(String[] args) {	
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			BigDecimal a = in.nextBigDecimal();
			int n = in.nextInt();
			System.out.println(f(a.pow(n).toPlainString()));
		}
	}	
}
