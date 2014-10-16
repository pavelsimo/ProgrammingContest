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
typedef pair<llong,llong> Vector;

llong N, M, xc, yc, k;

bool check(Vector v, llong xa, llong ya, llong c) {
   llong xb = xa + c * v.first;
   llong yb = ya + c * v.second;
   if(xb > N || yb > M || xb < 1 || yb < 1)
      return false;
   return true;
}

llong bs(Vector v, llong xa, llong ya) {
   llong lo = 1LL;
   llong hi = 1000000200LL;
   while(lo < hi) {
      llong mid = lo + (hi-lo)/2LL;
      if(check(v,xa,ya,mid))
         lo = mid + 1;
       else
         hi = mid;
   }
   return lo - 1;
}

int main(int argc, char *argv[]) {
   llong res = 0;
   Vector v;
   cin >> N >> M >> xc >> yc >> k;
   for(int i = 0; i < k; ++i) {
      cin >> v.first >> v.second;
      llong c = bs(v, xc, yc);
      res+=c;
      xc = xc + c*v.first;
      yc = yc + c*v.second;
   }
   cout << res << endl;
   return 0;
}

