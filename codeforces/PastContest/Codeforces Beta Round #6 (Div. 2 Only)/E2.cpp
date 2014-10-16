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

vector<pair<int,pair<int,int> > > X, ans;
int a[100002], best;

int main(int argc, char *argv[]) {
   std::ios_base::sync_with_stdio(false);
   int n, k, mi, ma;
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   best = 0;
   for(int i = 0; i < n; ) {
      int j;
      mi = ma = a[i];
      for(j = i + 1; j < n; ++j) {
         mi = min(mi, a[j]);
         ma = max(ma, a[j]);
         if(ma - mi > k) break;
      }
      best = max(best, j - i);
      X.push_back(make_pair(i, make_pair(j - 1, j - i)));
      i = (j - i) >= 2 ? j - 1: j;
   }
   for(int i = 0; i < n; ++i) {
      if(X[i].second.second == best)
         ans.push_back(X[i]);
   }
   cout << best << ' ' << sz(ans) << endl;
   for(int i = 0; i < sz(ans); ++i)
      cout << ans[i].first + 1 << ' ' << ans[i].second.first + 1 << endl;
   return 0;
}

