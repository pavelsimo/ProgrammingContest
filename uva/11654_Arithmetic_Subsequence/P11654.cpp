/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11654  C++  "Dynamic Programming" */
#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 10000007;

int N, memo[252][252], A[252];

int rec(int cur, int prev) {
   if(memo[cur][prev] >= 0) return memo[cur][prev];
   int res = 1;
   for(int nxt = cur + 1; nxt < N; ++nxt) {
      if(A[nxt] - A[cur] == A[cur] - A[prev]) {
         res += rec(nxt, cur);
         if(res >= MOD) res -= MOD;
      }
   }
   return memo[cur][prev] = res;
}

int main(int argc, char *argv[]) {  
   int TC, res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) 
         scanf("%d",&A[i]);
      res = 0;
      for(int i = 0; i < N; ++i)  {
         for(int j = i + 1; j < N; ++j) {
            memset(memo, -1, sizeof(memo));
            res += rec(j, i);                  
            if(res >= MOD) res-=MOD;
         }
      }   
      printf("Case %d: %d\n",tc, (res + N) % MOD);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
