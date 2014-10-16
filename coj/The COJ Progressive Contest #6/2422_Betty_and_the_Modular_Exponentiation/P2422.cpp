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

const llong MOD = 1000000000LL;

llong mulmod(llong x, llong y, llong m) {
   llong res = 0;
   x %= m;
   while (y) {
      if (y & 1) {
         res += x;
         res %= m;
      }
      x <<= 1;
      x %= m;
      y >>= 1;
   }
   return res;
}

llong powmod(llong x, llong n, llong m) {
   llong res = 1;
   x %= m;
   while (n) {
      if (n & 1) {
         res = mulmod(res, x, m);
         n--;
      }
      x = mulmod(x, x, m);
      n >>= 1;
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   cin >> TC;
   while(TC-- > 0) {
      llong x, y;
      cin >> x >> y;
      cout << powmod(x, y, MOD) << endl;
   }
   return 0;
}
