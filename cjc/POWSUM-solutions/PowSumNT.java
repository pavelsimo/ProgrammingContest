import java.io.*;

public class PowSumNT {
   final static int P = 1000000007;

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
      // x==1  => no modular inverse, but S(1, n) is trivial
      if (x == 1) return n+1;

      long a = (1L -x + P) % P;
      // a must be co-prime of M
      int inv = powMod(a, P-2, P);
      int xn1 = powMod(x, n+1, P);
      long res = ((1L - xn1 + P) * inv) % P;
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

