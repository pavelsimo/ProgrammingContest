/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11420  C++  "Dynamic Programming" */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

typedef long long llong;

int N, S;
llong memo[72][72][2];

llong rec(int n, int s, int p) {
   if(s > S) return 0;
   if(n == N) return s == S;
   llong res = 0LL;
   if(memo[n][s][p] >= 0) return memo[n][s][p];
   res += rec(n + 1, s, 0);
   res += rec(n + 1, s + (p ? 1: 0), 1);
   return memo[n][s][p] = res;
}

int main(int argc, char *argv[]) {  
   llong res;
   while(2 == scanf("%d%d",&N,&S)) {
      if(N<0 && S<0) break;  
      memset(memo, -1, sizeof(memo));
      res = rec(0, 0, 1);
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
