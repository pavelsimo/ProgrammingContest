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

int N;
llong memo[256][256][256];

int go(int n, int cur, int first) {
   if(n == N) 
      return cur == first ? 0: 1;
   if(memo[n][cur][first] != -1) 
      return memo[n][cur][first];
   llong res = 0LL;
   for(int i = 1; i <= 4; ++i) {
      if(cur == i) continue;
      res += go(n + 1, i, first);
   }
   return memo[n][cur][first] = res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   cin >> TC;
   while(TC-- > 0) {
      cin >> N;
      memset(memo, -1, sizeof(memo));
      llong res = 0;
      for(int i = 1; i <= 4; ++i)
         res += go(1, i, i);
      cout << N << " : "<< res << endl;
   }
   return 0;
}

