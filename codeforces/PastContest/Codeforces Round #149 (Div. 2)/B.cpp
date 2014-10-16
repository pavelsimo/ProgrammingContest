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

vector<pair<int,int> > seg;

const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, l, r;
   cin >> n;
   int mi = INF;
   int ma = 1;
   for(int i = 0; i < n; ++i) {
      cin >> l >> r;
      seg.push_back(make_pair(l,r));
      mi = min(mi, l);
      ma = max(ma, r);
   }
   for(int i = 0; i < n; ++i) {
      if(mi == seg[i].first && ma == seg[i].second) {
         cout << i + 1 << endl;
         return 0;
      }
   }
   cout << -1 << endl;
   return 0;
}
