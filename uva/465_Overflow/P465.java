/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  465  Java  "Big Integer" */
import java.math.BigInteger;
import java.util.Scanner;


public class P465 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);		
		while (in.hasNext()) {
			String s = in.nextLine();
			String token[] = s.split(" ");				
			BigInteger a = new BigInteger(token[0]);
			String opt = token[1];
			BigInteger b = new BigInteger(token[2]);
			System.out.println(s);
			if (a.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) > 0 || a.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) < 0)
				System.out.println("first number too big");
			if (b.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) > 0 || b.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) < 0)
				System.out.println("second number too big");
			BigInteger c;
			if (opt.contains("*"))
				c = a.multiply(b);
			else
				c = a.add(b);
			if (c.compareTo(BigInteger.valueOf(Integer.MAX_VALUE)) > 0 || c.compareTo(BigInteger.valueOf(Integer.MIN_VALUE)) < 0)
				System.out.println("result too big");
		}
	}

}
