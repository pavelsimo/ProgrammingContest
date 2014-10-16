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

const int MAXN = 100020;
int a[MAXN];

int main(int argc, char *argv[]) { 
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int n, m;
   scanf("%d",&n);
   for(int i = 0; i < n; ++i)
      scanf("%d",&a[i]);
   int lo, hi;
   m = lo = hi = 0;
   sort(a, a + n);
   while(hi < n) {
      if(a[hi] <= 2 * a[lo]) {
         m = max(m, hi - lo + 1);
         hi++;
      } else {
         lo++;
      }
   }
   printf("%d\n",n - m);
   return 0;
}
