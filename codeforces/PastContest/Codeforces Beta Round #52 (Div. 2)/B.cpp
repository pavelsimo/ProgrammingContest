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

int a[1002], b[1002];

int main(int argc, char *argv[]) {
   int n, lo = 0, hi = 0;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> a[i];
      b[a[i]] = i;
   }
   int cnt = 0;
   for(int i = 0, k = 1; i < n; ++i, ++k) {
      if(a[i] != k) {
         cnt++;
         int t = a[i];
         int j;
         for(j = i; j <= b[k]; ++j)
            if(t-- != a[j]) break;
         if(j == b[k] + 1) {
            lo = i + 1; 
            hi = b[k] + 1;
         }
         i = j;
         k = j + 1;
      }
   }
   if(cnt == 1) cout << lo << " " << hi << endl;
   else cout << 0 << " " << 0 << endl;
   return 0;
}
