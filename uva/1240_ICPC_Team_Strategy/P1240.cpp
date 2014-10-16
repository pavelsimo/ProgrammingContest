/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1240  C++  "Dynamic Programming" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int MAXN = 14;
int N;
int A[3][MAXN];
int memo[1<<12][300][4];

int rec(int mask, int t, int p) {
   if(memo[mask][t][p] >= 0)
      return memo[mask][t][p];
   int res = 0;
   for(int i = 0; i < N; ++i) {
      if(!(mask & (1<<i))) {
         for(int j = 0; j < 3; ++j) {
            if(p == j) continue;
            if(t >= A[j][i])
               res = max(res,rec(mask|(1<<i), t - A[j][i], j)  + 1);
         }                  
      }
   }
   return memo[mask][t][p] = res;
}

int main(int argc, char *argv[]) {
   int TC;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < 3; ++i) {
         for(int j = 0; j < N; ++j)
            scanf("%d",&A[i][j]);         
      }
      memset(memo,-1,sizeof(memo));
      printf("%d\n",rec(0,280,3));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
