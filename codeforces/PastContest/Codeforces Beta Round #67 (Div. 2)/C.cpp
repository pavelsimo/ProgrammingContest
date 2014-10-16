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

vector<llong> go(llong n) {
   vector<llong> res;
   for(llong x = 1; x * x <= n; ++x) {
      if(n % x == 0) {
         llong div1 = x;
         llong div2 = n / x;
         res.push_back(div1);
         if(div1 != div2) res.push_back(div2);
      }
   }
   return res;
}

int main(int argc, char *argv[]) {
   llong a, b, lo, hi;
   int tc;
   cin >> a >> b >> tc;
   vector<llong> X = go(a); sort(all(X));
   vector<llong> Y = go(b); sort(all(Y));
   vector<llong> Z(sz(X) + sz(Y) + 1);
   vector<llong>::iterator it = set_intersection (all(X), all(Y), Z.begin());
   int M = int(it - Z.begin());
   while(tc-- > 0) {
      cin >> lo >> hi;
      llong res = -1;
      for(int i = 0; i < M; ++i)
         if(Z[i] >= lo && Z[i] <= hi) 
            res = max(res, Z[i]);
      cout << res << endl;
   }
   return 0;
}

