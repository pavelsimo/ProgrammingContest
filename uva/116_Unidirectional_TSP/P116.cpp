/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  116  C++  "Backtracking, Primes" */
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
const int maxn = 101;
int a[maxn][maxn];
int dp[maxn][maxn];

int d(int i, int j) {
   if(dp[i][j] != -1) return dp[i][j];
   dp[i][j] = a[i][j] + (j<0 || i<0 || i >=n || j >=m? 0: min(d(i-1,j-1),min(d(i,j-1),d(i+1,j-1))));
   return dp[i][j];
}


int main(int argc, char *argv[]) {
   
   while(scanf("%d%d",&n,&m)==2) {
      memset(a,0,sizeof(a));
      memset(dp,-1,sizeof(dp));
      for(int i = 0; i < n; ++i) 
         for(int j = 0; j < m; ++j) 
            scanf("%d",&a[i][j]);
      
      cout << d(n,m) << endl;
            
      // debug
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < m; ++j)
            printf("%d ",a[i][j]);
         putchar('\n');
      }
      putchar('\n');
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < m; ++j)
            printf("%d ",dp[i][j]);
         putchar('\n');
      }

            
      
   }
   

	return 0;
}
/* @END_OF_SOURCE_CODE */
