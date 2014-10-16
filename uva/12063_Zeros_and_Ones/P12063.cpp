/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12063  C++  "Dynamic Programming, Number Theory" */
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

typedef long long llong;

int N, MOD, tc;
llong memo[34][34][102];
int seen[34][34][102];

llong rec(int i, int j, int rem) {
   if((i<<1) > N || (j<<1) > N) 
      return 0;
   if(i + j == N)
      return rem == 0 && (i<<1) == N && (j<<1) == N;
   if(seen[i][j][rem] == tc) 
      return memo[i][j][rem]; 
   seen[i][j][rem] = tc;
   return memo[i][j][rem] = rec(i, j + 1, (rem<<1)%MOD) + rec(i + 1, j, (rem<<1|1)%MOD);
}

int main(int argc, char *argv[]) {
   int TC;
   scanf("%d",&TC);
   memset(seen,0,sizeof(seen));   
   for(tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&N,&MOD);
      printf("Case %d: %lld\n", tc, !MOD || N & 1 ? 0: rec(1,0,1%MOD));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
