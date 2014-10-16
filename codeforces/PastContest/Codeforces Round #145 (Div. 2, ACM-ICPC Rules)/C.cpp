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

llong A[1000002], B[1000002], C[1000002];

int main(int argc, char *argv[]) { 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   llong n;
   cin >> n;
   B[0] = C[0] = 0;
   for(int i = 1; i <= n; ++i) {
      cin >> A[i];
      B[i] = B[i - 1] + (A[i] >= 0);
      C[i] = C[i - 1] + (A[i] <= 0);
   }
   llong best = 1000000000000000000LL;
   for(int k = 1; k <= n - 1; ++k) {
      llong X1 = C[n] - C[k];
      llong X2 = B[k];
      llong X = X1 + X2;
      if(X < best)
         best = X;
   }
   cout << best << endl;
   return 0;
}

