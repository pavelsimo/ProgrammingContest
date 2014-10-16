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

const int MAXN = 1002;
typedef pair<double,double> Point;

double dist(Point a, Point b) {
   return hypot(a.first-b.first,a.second - b.second);
}

Point P[MAXN];

int main(int argc, char *argv[]) {
   double res = 0.0;
   int n, k;
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      cin >> P[i].first >> P[i].second;
   for(int i = 0; i < n - 1; ++i)
      res+=dist(P[i],P[i+1])/50.0;            
   printf("%lf\n",k*res);
   return 0;
}

