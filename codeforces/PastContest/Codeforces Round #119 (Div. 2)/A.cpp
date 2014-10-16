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

int main(int argc, char *argv[]) { 
   int n, a, b, c, res;
   cin >> n >> a >> b >> c;
   res = 0;
   for(int x = 0; x <= n; ++x) {
      for(int y = 0; y <= n; ++y) {
         int cz = n - a*x - b*y;
         if(cz >= 0 && cz % c == 0) {
            int z = cz / c;
            res = max(res, x + y + z);               
         }
      }
   }
   cout << res << endl;
   return 0;
}

