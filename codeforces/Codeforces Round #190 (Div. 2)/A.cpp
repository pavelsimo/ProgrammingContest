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

int b[202], g[202];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   vector<pair<int,int> > ans;
   cin >> n >> m;
   memset(b, 0, sizeof(b));
   memset(g, 0, sizeof(g));
   for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) {
         if(b[i] == 0 || g[j] == 0) {
            ans.push_back(make_pair(i,j));
            b[i]++;
            g[j]++;               
         }
      }
   }
   cout << sz(ans) << endl;
   for(int i = 0; i < sz(ans); ++i)
      cout << ans[i].first << " " << ans[i].second << endl;
   return 0;
}
