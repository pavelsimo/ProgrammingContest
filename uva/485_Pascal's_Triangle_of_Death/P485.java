/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  485  C++  "Math, Binomial Coefficients, Combinations, BigInteger" */
import java.math.BigInteger;

public class P485 {

   static BigInteger C[][] = new BigInteger[500][500];
   static BigInteger MAXN = BigInteger.valueOf(10).pow(60);

   public static void main(String[] args) {
      C[0][0] = BigInteger.ONE;
      System.out.println(C[0][0]);
      boolean stop = false;
      for (int i = 1; i < 500; ++i) {
         for(int j = 0; j <= i; ++j) {
            if(j > 0) System.out.print(' ');
            if(j == 0 || j == i)
               C[i][j] = BigInteger.ONE;
            else
               C[i][j] = C[i-1][j-1].add(C[i-1][j]);
            if(C[i][j].compareTo(MAXN) == 1) stop = true;
            System.out.print(C[i][j].toString());
         }
         System.out.println();
         if(stop) break;
      }
   }
}
/* @END_OF_SOURCE_CODE */
