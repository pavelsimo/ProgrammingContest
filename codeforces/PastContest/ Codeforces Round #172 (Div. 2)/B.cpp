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

struct Fraction {
  llong a, b; 
  Fraction(llong _a = 0, llong _b = 0) : a(_a), b(_b) {}
  bool operator< (const Fraction &T) const {
     if(a * T.b != T.a * b) return a * T.b < T.a * b;
     if(b != T.b) return b < T.b;
     return a < T.a;
  }
};

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong x, y, n;
   cin >> x >> y >> n;
   bool ok = true;
   Fraction best, ans;
   for(llong b = 1LL; b <= n; ++b) {
      llong a = (b * x) / y;
      for(int j = 0; j <= 1; ++j) {
         // | x/y - a/b | = | bx - ya | / | yb |
         Fraction ab = Fraction((a + j), b);
         Fraction xyab = Fraction(abs(b * x - y * (a + j)), y * b);
         if(ok || xyab < best) {
            best = xyab;
            ans = ab;
            ok = false;
         }         
      }
   }
   cout << ans.a << '/' << ans.b << endl;
   return 0;
}
