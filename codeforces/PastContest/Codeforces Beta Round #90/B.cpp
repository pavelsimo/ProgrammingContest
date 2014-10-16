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


const int MAXN = 202, INF = 100000;
int n, k, q, a[MAXN], f[MAXN][MAXN];
int memo[MAXN][MAXN], memo2[MAXN][MAXN];
bool used[MAXN];
set<int> F;

int rec(int i, int j) {
   if(i == n && j > 0) return -INF;
   if(j == 0) return 0;
   if(memo[i][j] >= 0) return memo[i][j];
   int res = 0;
   res = max(res, rec(i + 1, j));
   if(!F.count(i)) res = max(res, rec(i + 1, j - 1) + a[i]);
   return memo[i][j] = res; 
}

int rec2(int i, int j) {
   if(i == n && j > 0) return INF;
   if(j == 0) return 0;
   if(memo2[i][j] >= 0) return memo2[i][j];
   int res = INF;
   res = min(res, rec2(i + 1, j));
   if(!F.count(i)) res = min(res, rec2(i + 1, j - 1) + a[i]);
   return memo2[i][j] = res; 
}

int main(int argc, char *argv[]) {
   int u, lo, hi;
   memset(memo,-1,sizeof(memo));
   memset(memo2,-1,sizeof(memo2));
   cin >> n >> k;
   for(int i = 0; i < n; ++i) 
      cin >> a[i];
   cin >> q;
   hi = 0;
   lo = INF;
   for(int i = 0; i < q; ++i) {
      int sum = 0;
      for(int j = 0; j < n/k; ++j) {
         cin >> u;
         --u;
         sum+=a[u];
         F.insert(u);
      }
      lo = min(lo,sum);
      hi = max(hi,sum);
   }
   int C = n/k;
   if(sz(F) / C < k) {
      lo = min(lo,rec2(0,n/k));
      hi = max(hi,rec(0,n/k));
   }
   printf("%lf %lf\n",(1.0*lo/C),(1.0*hi/C));      
   return 0;
}

