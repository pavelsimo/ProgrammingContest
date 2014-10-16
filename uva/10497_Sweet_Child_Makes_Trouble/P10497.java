/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10497  C++  "Math, Derangements, BigInteger" */
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

public class P10497 {
   
   static HashMap<BigInteger, BigInteger> memo = new HashMap<BigInteger, BigInteger>();

   public static BigInteger der(BigInteger n) {
      if (n.compareTo(BigInteger.ZERO) == -1) return BigInteger.ZERO;
      if (n.compareTo(BigInteger.ZERO) == 0) return BigInteger.ONE;
      if(memo.containsKey(n)) return memo.get(n);
      BigInteger a = n.subtract(BigInteger.ONE);
      BigInteger b = n.subtract(BigInteger.valueOf(2));
      BigInteger c = der(a).add(der(b));
      memo.put(n, a.multiply(c));
      return memo.get(n);
   }

   public static void main(String[] args) {
      int N;
      Scanner in = new Scanner(System.in);
      while (in.hasNext()) {
         N = in.nextInt();
         if(N == -1) break;
         BigInteger x = der(BigInteger.valueOf(N));
         System.out.println(x.toString());
      }
   }
}
/* @END_OF_SOURCE_CODE */
