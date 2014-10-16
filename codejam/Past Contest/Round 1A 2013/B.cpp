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

int v[22];
int memo[22][22];

int TC, E, R, N, res;

int rec(int cur, int e) {
   if(cur == N) return 0;
   if(memo[cur][e] != -1) return memo[cur][e];
   int res = 0;
   for(int ne = 0; ne <= e; ++ne)
      res = max(res, rec(cur + 1, min((e - ne) + R, E)) + (v[cur] * ne));
   return memo[cur][e] = res;
}

int main(int argc, char *argv[]) { 
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d%d",&E,&R,&N);
      memset(memo, -1, sizeof(memo));
      for(int i = 0; i < N; ++i)
         scanf("%d",&v[i]);
      printf("Case #%d: %d\n",tc, rec(0, E));
   }
   return 0;
}
