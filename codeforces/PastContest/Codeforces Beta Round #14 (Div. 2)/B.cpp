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

const int INF = 3000;
int X[1002];

int main(int argc, char *argv[]) {
   int n, x0, a, b, res;
   cin >> n >> x0;
   memset(X, 0, sizeof(X));
   for(int i = 0; i < n; ++i) {
      cin >> a >> b;
      if(a > b) swap(a, b);
      for(int j = a; j <= b; ++j) X[j]++;   
   }
   res = INF;
   for(int i = 0; i <= 1000; ++i) {
      if(X[i] == n)
         res = min(res, abs(x0 - i));
   }
   if(res >= INF) cout << -1 << endl;
   else cout << res << endl;
   return 0;
}

