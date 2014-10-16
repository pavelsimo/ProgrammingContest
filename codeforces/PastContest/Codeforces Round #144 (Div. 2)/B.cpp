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

llong s(llong x) {
   llong sum = 0;
   while(x > 0LL) {
      sum += (x % 10LL);
      x/=10LL;
   }
   return sum;
}

llong f(llong x) {
   return x*x + s(x)*x;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong n;
   cin >> n;
   llong hi = sqrt(n);
   llong lo = 0;
   while(lo < hi) {
      llong x = lo + (hi-lo)/2LL;
      if(f(x) > n)
         hi = x;
      else
         lo = x + 1;
   }
   for(int i = -100; i <= 100; ++i) {
      if(lo - i <= 0) continue;
      if(f(lo - i) == n) {
         cout << lo - i << endl;      
         return 0;
      }
   }
   cout << -1 << endl;
   return 0;
}
