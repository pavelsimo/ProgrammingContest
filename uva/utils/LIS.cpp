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

int a[1002], DP[1002], P[1002], ans[1002];

int main(int argc, char *argv[]) {
   int n, best;
   memset(P, -1, sizeof(P));
   cin >> n;
   DP[0] = 1;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   for(int i = 1; i < n; ++i) {
      DP[i] = 1;
      for(int j = 0; j < i; ++j) {
         if(a[j] < a[i] && DP[j] + 1 > DP[i]) {
            DP[i] = DP[j] + 1;  
            P[i] = j;
         }
      }
   }
   best = 0;
   for(int i = 0; i < n; ++i) {
      if(DP[i] > DP[best]) 
         best = i;
   }
   int m = 0;
   for(int i = best; i >= 0; i = P[i], ++m)
      ans[m] = a[i];
   cout << DP[best] << endl;
   for(int i = m-1; i >= 0; --i)
      cout << ans[i] << ' ';
   cout << endl;
   return 0;
}

