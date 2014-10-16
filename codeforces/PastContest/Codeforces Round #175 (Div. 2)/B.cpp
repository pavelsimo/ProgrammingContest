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

const int MAXN = 100020;
int cnt[MAXN], p[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   memset(cnt, 0, sizeof(cnt));
   int n, s, t;
   cin >> n >> s >> t;
   for(int i = 1; i <= n; ++i)
      cin >> p[i];
   int res = 0;
   for(int i = 0; i < n; ++i) {
      cnt[s]++;
      if(cnt[s] >= 2) {
         cout << -1 << endl;
         return 0;
      }
      if(s == t) break;
      s = p[s];
      res++;
   }
   cout << res << endl;
   return 0;
}
