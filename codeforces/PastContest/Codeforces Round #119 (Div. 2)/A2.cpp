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

int memo[4002][4002], X[3];

int rec(int n, int depth) {
   if(n == 0) return 0;
   if(memo[n][depth] >= 0) return memo[n][depth];
   int res = 0;
   for(int i = 0; i < 3; ++i) {
      if(n >= X[i]) {
         res = max(res, rec(n - X[i], X[i]) + 1);
      }
   }
   return memo[n][depth] = res;
}

int main(int argc, char *argv[]) { 
   int n, a, b, c, res;
   cin >> n >> a >> b >> c;
   X[0] = a; X[1] = b; X[2] = c;
   memset(memo, -1, sizeof(memo));
   res = rec(n, 0);
   cout << res << endl;
   return 0;
}

