/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11218  C++  "Brute Force, Dynamic Programming, Bitmasking" */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 8100000;
const int t_state = (1<<9) - 1;
int memo[128][512], N, a[128], b[128], c[128], s[128];

bool is_set(int mask, int bit) {
   return (mask & (1 << bit)) > 0;
}

int go(int n, int mask) {
   if(mask == t_state) return 0;
   if(n >= N) return mask == t_state ? 0: -INF;
   if(memo[n][mask] != -1) return memo[n][mask];
   int res = -INF;
   res = max(res, go(n + 1, mask));
   if(!is_set(mask, a[n]) && !is_set(mask, b[n]) && !is_set(mask, c[n])) {
      int nmask = mask;
      nmask |= (1 << a[n]), nmask |= (1 << b[n]), nmask |= (1 << c[n]);
      res = max(res, go(n + 1, nmask) + s[n]);
   }
   return memo[n][mask] = res;
}

int main(int argc, char *argv[]) {
   int res, tc = 1;   
   while(1 == scanf("%d", &N)) {
      if(!N) break;  
      memset(memo, -1, sizeof(memo));
      for(int i = 0; i < N; ++i) {
         scanf("%d%d%d%d",&a[i],&b[i], &c[i], &s[i]);
         a[i]--, b[i]--, c[i]--;
      }
      res = go(0, 0);
      printf("Case %d: %d\n",tc++,res < 0 ? -1: res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
