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

llong N, K, ma;

llong f(llong k) {
   return k*(k-1LL)/2LL + 1;
}

llong sum(llong k) {
   return ma - f(K - k) - 1;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> N >> K;
   if(f(K) < N) {
      cout << -1 << endl; 
      return 0;
   }
   if(N == 1) {
      cout << 0 << endl;
      return 0;
   }
   if(K >= N) {
      cout << 1 << endl;
      return 0;
   }
   llong lo = 0;
   llong hi = K;
   ma = f(K);
   while(lo < hi) {
      llong mid = (lo + hi) / 2LL;
      if(sum(mid) < N) 
         lo = mid + 1;
      else
         hi = mid;
   }
   cout << lo << endl;
   return 0;
}
