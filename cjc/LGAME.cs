using System;
using System.Collections.Generic;
using System.Text;

class LGAME {
   static void Main(string[] args) {
      (new LGAME()).Run();
   }
   
   void Run() {
      build_pascal_triangle();
      int TC = int.Parse(Console.ReadLine());
      for (int tc = 1; tc <= TC; ++tc) {
         string[] tok = Console.ReadLine().Split(' ');
         int N = int.Parse(tok[0]);
         int M = int.Parse(tok[1]);
         tok = Console.ReadLine().Split(' ');
         int C1 = int.Parse(tok[0]);
         int C2 = int.Parse(tok[2]);
         double res = 0.0;
         for (int k = 0; k < C1; ++k)
            res += PT[N, k] * Math.Pow(1.0/M, k) * Math.Pow((M-1.0)/M, N-k);
         for (int k = C2; k <= N; ++k)
            res += PT[N, k] * Math.Pow(1.0/M, k) * Math.Pow((M-1.0)/M, N-k);
         res *= 0.5;
         Console.WriteLine("{0:F2}", res);
      }
   }


   const int MAXN = 21;
   long[,] PT = new long[MAXN,MAXN];
   void build_pascal_triangle() {
      PT[0, 0] = 1;
      for (int n = 1; n < MAXN; ++n) {
         PT[n, 0] = 1;
         for (int k = 1; k < n; ++k)
            PT[n, k] = PT[n-1, k-1] + PT[n-1, k];
         PT[n, n] = 1;
      }
   }
}