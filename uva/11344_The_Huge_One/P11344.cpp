/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11344  C++  "Number Theory" */
#include <iostream>
#include <string>

using namespace std;

typedef long long llong;

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

template<typename INT>
INT lcm(INT a, INT b) {
   return a / gcd(a,b) * b;
}

int main(int argc, char *argv[]) {
   string M;
   int TC, S, d, prod, res;
   cin >> TC;
   while(TC-- > 0) {
      cin >> M >> S;
      prod = 1;
      for(int i = 0; i < S; ++i) {
         cin >> d;
         prod = lcm(prod, d);
      }
      res = 0;
      for(int i = 0; i < (int)M.size(); ++i)
         res = (res*10 + (M[i] - '0')) % prod;
      if(res == 0) cout << M << " - Wonderful.\n";
      else cout << M << " - Simple.\n";
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
