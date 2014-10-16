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

struct Point {
  llong x, y; 
};

int ccw(Point a, Point b, Point c) {
  double area2 = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
  if (area2 < 0) return -1;
  else if (area2 > 0) return +1;
  return  0;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   Point a, b, c;
   cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
   int dir = ccw(a, b, c);
   if(dir == 0) cout << "TOWARDS" << endl;
   else if(dir == -1) cout << "RIGHT" << endl;
   else cout << "LEFT" << endl;
   return 0;
}

