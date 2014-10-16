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
vector<pair<llong,llong> > X;

int main(int argc, char *argv[]) {
   llong res = 0LL, n, m, a, b;
   cin >> n >> m;
   for(int i = 0; i < m; ++i) {
      cin >> a >> b;
      X.push_back(make_pair(b, a));
      
   }
   sort(X.rbegin(), X.rend());
   for(int i = 0; i < m; ++i) {
      if(n >= X[i].second) {
         n-=X[i].second;
         res+=X[i].second*X[i].first;
      } else {
         res+=llong(n) * X[i].first;
         break;
      }
   }
   cout << res << endl;
   return 0;
}

