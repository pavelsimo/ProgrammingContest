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

const int MAXN = 100002;
int a[MAXN], b[MAXN], pa[MAXN], pb[MAXN], x[MAXN];

int main(int argc, char *argv[]) {
   int n;
   cin >> n;
   for(int i = 1; i <= n; ++i) {
      cin >> a[i]; 
      pa[a[i]] = i;
   }
   for(int i = 1; i <= n; ++i) {
      cin >> b[i];
      pb[b[i]] = i;
   }
   for(int i = 1; i <= n; ++i)
      x[pa[i]] = a[pb[i]];
   for(int i = 1; i <= n; ++i) {
      if(i > 1) cout << ' ';
      cout << x[i];
   }
   cout << endl;
   return 0;
}

