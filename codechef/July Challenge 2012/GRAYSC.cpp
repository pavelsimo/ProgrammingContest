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

int a[100002], b[100002];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int n;
   cin >> n;
   memset(a, -1, sizeof(a));
   memset(b, -1, sizeof(b));
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   for(int i = 0; i < n - 1; ++i) {
      b[i] = a[i] ^ a[i + 1];
   }
   for(int i = 0; i < n - 1; ++i) {
      if(binary_search(b + i + 2, b + n, b[i])) {
         cout << "YES" << endl;
         return 0;
      }
   }
   cout << "NO" << endl;
   return 0;
}

