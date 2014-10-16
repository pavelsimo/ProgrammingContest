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

llong r, t;

// overflow
bool check(llong k) {
   return k * (2*r + 2*k -1) <= t;
}

int main(int argc, char *argv[]) { 
   int TC;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lld%lld",&r,&t);
      llong lo = 1;
      llong hi = t;
      while(hi - lo > 1) {
         llong mid = (lo + hi) / 2LL;
         if(check(mid)) lo = mid;
         else hi = mid;
      }
      printf("Case #%d: %lld\n",tc,lo);
   }
   return 0;
}
