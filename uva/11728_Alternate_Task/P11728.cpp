/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11728  C++  "Factors, Sieve, Divisors" */
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

// MAX SUM ~ 3048
const int MAXN = 1002;
int D[MAXN], ans[3052];

void sieve() {
   memset(D, 0, sizeof(D));   
   memset(ans, -1, sizeof(ans));
   for(int i = 1; i < MAXN; ++i) {
      for(int j = i; j < MAXN; j+=i) {
         D[j] += i;
      }
   }
   for(int i = 1; i < MAXN; ++i) {
      if(D[i]) 
         ans[D[i]] = i;
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int S, TC = 1;
   while(scanf("%d",&S) == 1) {
      if(!S) break;
      printf("Case %d: %d\n",TC,ans[S]);
      ++TC;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

