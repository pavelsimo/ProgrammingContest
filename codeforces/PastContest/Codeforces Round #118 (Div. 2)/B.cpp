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
   ios_base::sync_with_stdio(0);
   vector<pair<double, int> > X;
   int n, t1, t2, k, s1, s2;
   cin >> n >> t1 >> t2 >> k;
   for(int i = 0; i < n; ++i) {
      cin >> s1 >> s2;
      double c1 = ((s1 * t1)-((s1 * t1)*(k/100.0))) + s2*t2;
      double c2 = ((s2 * t1)-((s2 * t1)*(k/100.0))) + s1*t2;
      X.push_back(make_pair(max(c1,c2), -(i + 1)));
   }
   sort(X.rbegin(), X.rend());
   for(int i = 0; i < n; ++i)
      printf("%d %.2lf\n",abs(X[i].second),X[i].first);
   return 0;
}

