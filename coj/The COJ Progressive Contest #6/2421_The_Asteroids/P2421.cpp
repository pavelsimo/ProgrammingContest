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

const llong INF = 1000000000000000000LL;

double dist(llong x1, llong y1, llong x2, llong y2, llong r2) {
   llong dx = x1 - x2;
   llong dy = y1 - y2;
   return sqrt(dx*dx + dy*dy) - r2;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong N, xt, yt, xi, yi, ri;
   while(cin >> N) {
      if(!N) break;
      cin >> xt >> yt;
      double mi = INF;
      llong res = 1LL;
      for(int i = 1; i <= N; ++i) {
         cin >> xi >> yi >> ri;
         double d = dist(xt, yt, xi, yi, ri);
         if(d < mi) {
            mi = d;
            res = i;
         }
      }
      cout << res << endl;
   }
   return 0;
}
