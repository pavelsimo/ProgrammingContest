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

llong T[2002], C[2002];

int main(int argc, char *argv[]) {
   llong n, m, l, r, t, c, res = 0;
   cin >> n >> m;
   memset(T, 0x3f, sizeof(T));
   memset(C, 0, sizeof(C));
   for(int i = 0; i < m; ++i) {
      cin >> l >> r >> t >> c;
      for(int j = l; j <= r; ++j) {
         if(t < T[j])
            T[j] = t, C[j] = c;
      }
   }
   for(int i = 1; i <= n; ++i)
      res += C[i];
   cout << res << endl;
   return 0;
}

 
