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

int main(int argc, char *argv[]) {
   int N, res, a, mi_odd;
   cin >> N;
   res = 0, mi_odd = 1002;
   for(int i = 0; i < N; ++i) {
      cin >> a;
      res += a;
      if(a & 1) mi_odd = min(mi_odd, a);
   }
   if(mi_odd >= 1002) mi_odd = 0;
   if(res & 1) cout << res << endl;
   else if((res - mi_odd) & 1) cout << (res - mi_odd) << endl;
   else cout << 0 << endl;
   return 0;
}
