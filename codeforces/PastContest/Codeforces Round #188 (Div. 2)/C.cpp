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


llong solve(llong x, llong y, llong m) {
   if(x >= m || y >= m) return 0;
   if(x <= 0 && y <= 0) return -1;
   int res = 1;
   while(true) {
      llong t = x + y;
      if(x + y >= m) return res;
      if(x > y) y = t;
      else x = t;
      res++;
   }
   return -1;
}

int main() { 
   llong x, y, m;
   cin >> x >> y >> m;
   cout << solve(x,y,m) << endl;
   return 0;
}
