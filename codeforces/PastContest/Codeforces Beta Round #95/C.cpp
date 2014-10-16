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

const int MAXN = 32;
typedef long long llong;
llong C[MAXN][MAXN];

int main(int argc, char *argv[]) {
   memset(C,0,sizeof(C));
   llong res;
   int n, m, t;
   cin >> n >> m >> t;
   C[0][0] = 1;
   for(int i = 1; i <= MAXN; ++i) {
      for(int j = 0; j <= i; ++j) {
         if(j == 0 || j == i)
            C[i][j] = 1;
         else
            C[i][j] = C[i-1][j-1] + C[i-1][j];
      }
   }
   res = 0LL;
   for(int i = 4; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
         if(i + j == t)
            res+=C[n][i]*C[m][j];
      }
   }
   cout << res << endl;
   return 0;
}

