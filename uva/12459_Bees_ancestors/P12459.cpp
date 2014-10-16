/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12459  C++  "Dynamic Programming, Fibonnaci" */
#include <cstdio>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 82;
typedef long long llong;
llong F[MAXN];

int main(int argc, char *argv[]) {  
   F[1] = 1LL;
   F[2] = 2LL;
   for(int i = 3; i < MAXN; ++i)
      F[i] = F[i - 1] + F[i - 2];
   int n;
   while(1 == scanf("%d",&n)) {
      if(!n) break;
      printf("%lld\n",F[n]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
