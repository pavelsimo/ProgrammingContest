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

const int MAXN = 202;
int N, M;
llong AType[MAXN], AQty[MAXN], BType[MAXN], BQty[MAXN];
llong memo[MAXN][MAXN];

llong rec(int i, int j) {
   if(i >= N || j >= M) return 0;
   if(memo[i][j] >= 0) return memo[i][j];
   llong res = 0LL;
   if(AType[i] == BType[j]) {
      res = max(res, rec(i + 1, j + 1) + min(AQty[i],BQty[j]));
   } else {
      res = max(res, rec(i + 1, j));
      res = max(res, rec(i, j + 1));
   }
   return memo[i][j] = res;
}


int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int TC;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&N,&M);      
      for(int i = 0, j = 0, k = 0; i < 2*N; ++i) {
         if(i % 2 == 0)
            scanf("%lld",&AQty[j++]);
         else
            scanf("%lld",&AType[k++]);
      }
      for(int i = 0, j = 0, k = 0; i < 2*M; ++i) {
         if(i % 2 == 0)
            scanf("%lld",&BQty[j++]);
         else
            scanf("%lld",&BType[k++]);         
      }
      memset(memo, -1, sizeof(memo));
      printf("Case #%d: %lld\n",tc, rec(0, 0));
   }
   return 0;
}
