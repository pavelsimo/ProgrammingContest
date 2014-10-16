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

int main(int argc, char *argv[]) {
   int x1, x2, y1, y2, r1, r2;
   double X, d;
   cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
   d = hypot(x1 - x2, y1 - y2);
   if(d < max(r1, r2))
      X = max(r1,r2) - d - min(r1,r2);
   else
      X = d - r1 - r2;
   printf("%lf\n",max(0.0,X)/2.0);
   return 0;
}

