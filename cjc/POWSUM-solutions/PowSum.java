import java.io.*;

public class PowSum {
   final static int MOD = 1000000007;

   static int powMod(long x, int n, int M) {
      long res = 1;
      x %= M;
      while (true) {
         if ((n & 1) != 0)
            res = (res * x) % M;
         n /= 2;
         if (n == 0) break;
         x = (x * x) % M;
      }
      return (int) res;
   }

   int S(long x, int n) {
      if (n == 0) return 1;
      long res;
      if ((n & 1) != 0) {
         long Sn2 = S(x, (n-1)/2);
         long xn2 = powMod(x, (n+1)/2, MOD);
         res = (Sn2 * (1 + xn2)) % MOD;
      }
      else {
         long Sn2 = S(x, n/2);
         long xn2 = powMod(x, n/2, MOD);
         res = (Sn2 + (xn2 * ((Sn2 + MOD - 1) % MOD) % MOD)) % MOD;
      }
      return (int) res;
   }

   public static void main (String[] args) throws IOException {
      (new PowSum()).Run();
   }

   void Run() throws IOException {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      int TC = Integer.parseInt(in.readLine());
      for (int tc = 1; tc <= TC; ++tc) {
         String[] tok = in.readLine().split(" ");
         int x = Integer.parseInt(tok[0]);
         int n = Integer.parseInt(tok[1]);
         int res = S(x, n);
         System.out.println(res);
      }
   }
}

