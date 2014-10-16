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
int N, DP[256][256], A[256];
int main(int argc, char *argv[]) {  
   int TC, res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      memset(DP, 0, sizeof(DP));
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) 
         scanf("%d",&A[i]);
      res = N;
      for(int i = 1; i < N; ++i) {
         for(int j = i - 1; j >= 0; --j)  {
            int diff = A[i] - A[j];
            DP[i][j] = 1;
            for(int k = j - 1; k >= 0; --k) {
               int diff2 = A[j] - A[k]; 
               if(diff == diff2) DP[i][j] += DP[j][k];
               if(DP[i][j] >= MOD) DP[i][j] -= MOD;
            }
            res += DP[i][j];
            if(res >= MOD) res -= MOD;
         }
      }   
      printf("Case %d: %d\n",tc, res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
