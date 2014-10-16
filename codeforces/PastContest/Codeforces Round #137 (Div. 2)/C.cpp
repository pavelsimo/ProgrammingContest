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

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

llong a[100002], b[100002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < n; ++i) cin >> a[i];
   for(int i = 0; i < m; ++i) cin >> b[i];
   sort(a, a + n);
   sort(b, b + n);
   int p1, p2;
   p1 = p2 = 0;
   while(p1 < n && p2 < m) {
      llong g = gcd(a[p1], b[p2]);
      if(g == 1LL) {
         if(a[p1] > b[p2]) 
            p2++;
         else
            p1++;
      } else {
         a[p1] /= g;
         b[p2] /= g;
      }
   }
   for(int i = 0; i < n; ++i) {
      DEBUG(a[i]);
   }
   for(int i = 0; i < m; ++i) {
      DEBUG(b[i]);
   }
   return 0;
}

