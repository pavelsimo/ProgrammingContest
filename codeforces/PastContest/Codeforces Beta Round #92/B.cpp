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

const int MAXN = 20, INF = 0x3f3f3f3f;
int a[MAXN][MAXN];
int p[MAXN];

int main(int argc, char *argv[]) {
   int n, k, res = INF;
   string s;
   cin >> n >> k;
   for(int i = 0; i < n; ++i) {
      cin >> s;
      for(int j = 0; j < k; ++j)
         a[i][j] = s[j] - '0';
   }
   for(int i = 0; i < k; ++i)
      p[i] = i;
   do {
      int lo = INF;
      int hi = 0;
      for(int i = 0; i < n; ++i) {
         int x = 0;
         for(int j = 0; j < k; ++j)
            x = x*10 + a[i][p[j]];
         lo = min(lo,x);
         hi = max(hi,x);
      }
      res = min(res,hi-lo);
   } while(next_permutation(p,p+k));
   cout << res << endl;
   return 0;
}

