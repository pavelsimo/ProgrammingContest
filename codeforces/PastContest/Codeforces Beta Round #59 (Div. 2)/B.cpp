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

int n, k, a[102];

bool check() {
   for(int i = 0; i < n; ++i)
      if(a[i] < k) return false;
   return true;
}

int main(int argc, char *argv[]) {
   int res = 0;
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   bool seen[202];
   while(!check()) {
      ++res;
      memset(seen, false, sizeof(seen));
      for(int i = 0; i < n; ++i) {
         if(!seen[a[i]]) {
            seen[a[i]] = true;
            a[i]++;
         }
      }
   }
   cout << res << endl;
   return 0;
}
