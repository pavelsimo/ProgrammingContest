/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ HS10SQFT C++ "Number Theory, Perfect Squares" */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long llong;

bool ispsq(llong x) {
   llong sq = llong(sqrt(x));
   return sq*sq == x;
}

int main(int argc, char *argv[]) {
   int TC;
   llong n;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      printf("Case #%d:\n",tc);
      scanf("%lld",&n);
      int cnt = 0;
      for(llong b = 2LL; b * b * b * b <= n; ++b) {
         if(n % (b*b - 1) == 0) {
            llong a2 = n / (b*b - 1) + 1;
            if(ispsq(a2)) {
               llong a1 = llong(sqrt(a2));
               llong b1 = b;
               if(cnt == 0) printf("%lld=",n);
               else printf("=");
               if(a1 > b1) swap(a1,b1);
               printf("(%lld^2-1)*(%lld^2-1)",a1, b1);                        
               cnt++;
            }
         }
      }
      if(!cnt)
         printf("For n=%lld there is no almost square factorisation.",n);
      printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
