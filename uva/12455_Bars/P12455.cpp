/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12455  C++  "Ad Hoc, Brute Force" */
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int TC, n, m, p, A[22];

inline void solve() {
   m = 1 << p;
   for(int i = 0; i < m; ++i) {
      int sum = 0;
      for(int j = 0; j < p; ++j) {
         if(i & (1 << j)) 
            sum += A[j];
      }
      if(sum == n) {
         printf("YES\n");
         return;
      }
   }
   printf("NO\n");   
}

int main(int argc, char *argv[]) {
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&n,&p);
      for(int i = 0; i < p; ++i)
         scanf("%d",&A[i]);
      solve();
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

