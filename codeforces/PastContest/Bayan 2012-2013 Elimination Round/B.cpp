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

const llong MOD = 1000000007LL;
vector<llong> X;
llong a[10002];
int n, m;

llong solve() {
   llong res = 0LL;
   for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
         X.push_back(a[i] ^ a[j]);
      }
   } 
   sort(X.rbegin(), X.rend());
   for(int i = 0; i < m; ++i) {
      res += X[i];
      while(res >= MOD) res -= MOD;
   }
   return res;
}


int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   cout << solve() << endl;
   return 0;
}

