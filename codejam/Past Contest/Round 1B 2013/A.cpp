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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

const int MAXN = 500000;
const int INF = 0x3f3f3f3f;
int memo[22][MAXN];
int S[22], N;

int rec(int cur, int s) {
   if(cur == N) 
      return 0;
   if(memo[cur][s] != -1) 
      return memo[cur][s];
   int res = INF;
   if(s > S[cur]) {
      res = min(res, rec(cur + 1, s + S[cur]));
   } else {
      res = min(res, rec(cur + 1, s) + 1);
      if((s - 1) > 0)
         res = min(res, rec(cur, s + (s - 1)) + 1);
   }
   return memo[cur][s] = res;
}

int main(int argc, char *argv[]) { 
   int TC, A;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      memset(memo, -1, sizeof(memo));
      scanf("%d%d",&A, &N);
      for(int i = 0; i < N; ++i)
         scanf("%d",&S[i]);
      sort(S, S + N);
      printf("Case #%d: %d\n",tc,rec(0, A));
   }
   return 0;
}
