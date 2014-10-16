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


typedef long long ullong;

const ullong MOD = 1000000007LL;

ullong mulmod(ullong x, ullong y, ullong m) {
   ullong res = 0LL;
   x %= m;
   while (y) {
      if (y & 1LL) {
         res += x;
         res %= m;
      }
      x <<= 1LL;
      x %= m;
      y >>= 1LL;
   }
   return res;
}

ullong powmod(ullong x, ullong n, ullong m) {
   ullong res = 1LL;
   x %= m;
   while (n) {
      if (n & 1LL) {
         res = mulmod(res, x, m);
         n--;
      }
      x = mulmod(x, x, m);
      n >>= 1LL;
   }
   return res;
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   ullong N, res;
   cin >> N;
   if(N == 0) res = 1LL;
   else res = (powmod(4LL, N - 1, MOD) * 2LL + powmod(2LL, N - 1, MOD)) % MOD;
   cout << res << endl;   
   return 0;
}
