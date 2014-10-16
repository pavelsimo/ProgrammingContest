/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10407  C++  "Math, Number Theory, GCD" */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1002;
int A[MAXN];

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

int main(int argc, char *argv[]) {
   int n = 0;
   while(1 == scanf("%d",&A[n])) {
      if(!A[n]) break;
      ++n;
      while(1 == scanf("%d",&A[n])) {
         if(!A[n]) break;
         n++;
      }
      sort(A, A + n);
      int mi = A[0];
      int res = 0;
      for(int i = 1; i < n; ++i) {
         A[i]-=mi;
         res = gcd(res, A[i]);
      }
      printf("%d\n",res);
      n = 0;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

