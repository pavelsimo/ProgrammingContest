/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10943  C++  "Dynamic Programming" */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

typedef long long llong;


const llong MOD = 1000000LL;

llong memo[102][102];
int N, K;

llong rec(int n, int k) {
   if(n == 0 || k == 1) return 1LL;
   llong res = 0;
   if(memo[n][k] >= 0LL) return memo[n][k];
   for(int i = 0; i <= n; ++i)
      res = (res + rec(n - i, k - 1)) % MOD;   
   return memo[n][k] = res;
}

int main(int argc, char *argv[]) {  
   llong res;
   memset(memo, -1, sizeof(memo));
   while(2 == scanf("%d%d",&N,&K)) {
      if(!N && !K) break;  
      res = rec(N, K);
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
