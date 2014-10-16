/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10913  C++  "Dynamic Programming" */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 102, INF = 0x3f3f3f3f;
int N, K, A[MAXN][MAXN];
bool seen[MAXN][MAXN];

int di[] = {+1,+0,+0};
int dj[] = {+0,-1,+1};
int rec(int i, int j, int k) {
   if(i > N && j > N && k < K) return 0;
   if(j < 1 || seen[i][j] || k >= K) return -INF;   
   int res = 0;
   for(int d = 0; d < 3; ++d) {
      seen[i][j] = true;   
      res = max(res, rec(i + di[d], j + dj[d], (A[i][j] < 0) ? k + 1: k) + A[i][j]);
      seen[i][j] = false;
   }
   return res;
}

int main(int argc, char *argv[]) {  
   int res;
   for(int tc = 1; 2 == scanf("%d%d",&N,&K); ++tc) {
      if(!N && !K) break;
      cout << N << endl;
      cout << K << endl;
      memset(A, 0, sizeof(A));
      memset(seen, false, sizeof(seen));
      //memset(memo, -1, sizeof(memo));
      for(int i = 1; i <= N; ++i) {
         for(int j = 1; j <= N; ++j) {
            scanf("%d",&A[i][j]);
         }
      }
      res = rec(1,1,0);
      printf("Case %d: ",tc);
      if(res < 0) puts("impossible");
      else printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
