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

const int MAXN = 2000002;
const llong MOD = 1000000000;
llong a[MAXN], f[MAXN];

void calc() {
   f[0] = f[1] = 1LL;
   for(int i = 2; i < MAXN; ++i)
      f[i] = (f[i-1] + f[i-2]) % MOD;
}

int main(int argc, char *argv[]) { 
   calc();
   llong n, m, t, xi, vi, li, ri, di, sum;
   cin >> n >> m;
   for(int i = 1; i <= n; ++i)
      cin >> a[i];
   while(m-- > 0) {
      cin >> t;
      if(t == 1) {
         cin >> xi >> vi;
         a[xi] = vi;
      } else if(t == 2) {
         cin >> li >> ri;
         sum = 0LL;
         for(int x = 0; x <= ri - li; ++x)
            sum = (sum + f[x] * a[li + x]) % MOD;
         cout << sum << endl;
      } else if(t == 3) {
         cin >> li >> ri >> di;
         for(int x = li; x <= ri; ++x)
            a[x] = (a[x] + di) % MOD;
      }
   }
   return 0;
}
