/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10892  C++  "Math, Number Theory, GCD, LCM" */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

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
   int n, res;
   while(1 == scanf("%d",&n)) {
      if(!n) break;      
      int x = n;
      vector<int> D;
      int m = (int)sqrt(n);
      for(int d = 1; d <= m; ++d) {
         if(x % d == 0) {
            int d2 = x / d;
            D.push_back(d);
            if(d != d2) D.push_back(d2);
         }
      }
      res = 0;
      for(int i = 0; i < sz(D); ++i) {
         for(int j = i; j < sz(D); ++j) {
            if(lcm(D[i],D[j]) == n) 
               res++;
         }
      }
      printf("%d %d\n", n, res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
