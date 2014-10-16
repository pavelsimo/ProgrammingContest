/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10910  C++  "Dynamic Programming" */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

typedef long long llong;

llong N, T, P, memo[102][102];

llong rec(llong cur, llong rem) {
   if(cur == 1 || rem == 0LL) return 1LL;
   if(memo[cur][rem] >= 0LL) return memo[cur][rem];
   llong res = 0;
   for(int i = 0; i <= rem; ++i)
      res+=rec(cur - 1, rem - i);      
   return memo[cur][rem] = res;
}

int main(int argc, char *argv[]) {  
   int TC;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld%lld",&N,&T,&P);      
      memset(memo, -1, sizeof(memo));
      printf("%lld\n",rec(N, T - N * P));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
