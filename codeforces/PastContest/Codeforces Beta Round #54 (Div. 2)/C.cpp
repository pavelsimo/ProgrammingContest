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

int a[100002];

bool check(int lo, int hi, int n) {
   return n & 1 ? lo <= hi : lo < hi;
}

int main(int argc, char *argv[]) {
   int n, lo, hi;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   lo = 0, hi = n - 1;
   int ma = max_element(a, a + n) - a;
   int mi = min_element(a, a + n) - a;
   DEBUG(ma);
   DEBUG(mi);
   return 0;
}

 
