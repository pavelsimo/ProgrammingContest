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

llong m[1000002];

int main(int argc, char *argv[]) { 
   llong n, k, a, b, c, r;
   int TC;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc) {
      cin >> n >> k >> a >> b >> c >> r;
      m[0] = a;
      for(int i = 1; i < k; ++i)
         m[i] = (b * m[i - 1] + c) % r;
      //sort(m, m + n);
      // DEBUG
      cout << "TC " << tc << endl;
      cout << "n = " << n << endl;
      cout << "k = " << k << endl;
      for(int i = 0; i < k; ++i)
         cout << m[i] << ' ';
      sort(m, m + k);
      cout << endl;
      cout << endl;
      for(int i = 0; i < k; ++i)
         cout << m[i] << ' ';
      cout << endl;
      cout << endl;
   }
   
   return 0;
}
