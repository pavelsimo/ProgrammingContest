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

pair<llong,llong> best_cut(llong m, llong k) {
   pair<llong,llong> res = make_pair(-1,-1);
   if(m > 1 && k == 1) 
      return make_pair(k, m);
   for(llong x = 2; x * x <= m; ++x) {
      if(m % x == 0) {
         llong part = m / x;
         if(part >= k) {
            res.first = part;
            res.second = x;
         }
      }
   } 
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   llong n, m, k, cnt = 1;

   return 0;
}
