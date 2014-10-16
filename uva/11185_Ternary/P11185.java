/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11185  Java  "Ad Hoc, Base Conversion" */
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		while(in.hasNext()) {
			n = in.nextInt();
			if(n<0)break;
			System.out.println(Integer.toString(n, 3));
		}
	}
}
