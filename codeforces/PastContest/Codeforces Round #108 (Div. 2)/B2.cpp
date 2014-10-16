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

const llong INF = 1000000000000LL;

int main(int argc, char *argv[]) {
   llong N, M, xc, yc, k, res = 0, dx, dy, step_x, step_y, step;
   cin >> N >> M >> xc >> yc >> k;
   for(int i = 0; i < k; ++i) {
      cin >> dx >> dy;
      step = step_x = step_y = INF;
      if(dx > 0) step_x = (N - xc) / dx;
      if(dx < 0) step_x = (xc - 1) / -dx;
      if(dy > 0) step_y = (M - yc) / dy;
      if(dy < 0) step_y = (yc - 1) / -dy;      
      step = min(step_x, step_y);
      res+=step;
      xc+=dx*step;      
      yc+=dy*step;
   }
   cout << res << endl;
   return 0;
}

