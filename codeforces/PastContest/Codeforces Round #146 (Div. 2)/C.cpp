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

template<typename INT>
INT lcm(INT a, INT b) {
// a*b/gcd(a,b) overflows !!!
   return a / gcd(a,b) * b;
}

llong go(llong n) {
   llong X[n];
   X[0] = n;
   if(n <= 2) {
      return n;
   } else {
      for(llong k = n, i = 1; k >= 1; --k) {
         if(i == 1 && gcd(X[i - 1], k) == 1) {
            X[i] = k;
            i++;
         } else if(i == 2 && gcd(X[i - 1], k) == 1 && gcd(X[i - 2], k) == 1) {
            X[i] = k;
            i++;
         }
         if(i >= 3) break;
      }
      return lcm(X[0], lcm(X[1], X[2]));
   }
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong n;
   cin >> n;
   cout << max(go(n), go(n-1)) << endl;
   return 0;
}

