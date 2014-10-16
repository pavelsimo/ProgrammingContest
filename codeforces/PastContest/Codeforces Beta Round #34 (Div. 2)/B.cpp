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


int a[102];
int main(int argc, char *argv[]) { 
   int n, m, res, sum;
   cin >> n >> m;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   sort(a, a + n);
   res = sum = 0;
   for(int i = 0; i < m; ++i) {
      sum += -a[i];
      res = max(res, sum);
   }
   cout << res << endl;
   return 0;
}
