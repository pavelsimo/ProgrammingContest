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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

const int MAXN = 20;
llong lo, hi;
int L[22], H[22];
llong memo[22][22][22];

int rec(int cur, int cnt4, int cnt7) {
   if(cur == MAXN) 
      return cnt4*cnt7;
   int res = 0;
   if(memo[cur][cnt4][cnt7] >= 0) 
      return memo[cur][cnt4][cnt7];
   for(int d = 0; d <= 9; ++d)
     res = max(res, rec(cur + 1, cnt4 + (d==4), cnt7 + (d==7)));
   return memo[cur][cnt4][cnt7] = res;
}

int main(int argc, char *argv[]) {
   int TC;
   scanf("%d",&TC);   
   while(TC-- > 0) {
      scanf("%lld%lld",&lo,&hi);
      memset(L, 0, sizeof(L));
      memset(H, 0, sizeof(H));
      memset(memo, -1, sizeof(memo));
      llong l = lo, h = hi;
      for(int i = 19; i >= 0; --i) {
         L[i] = l%10;
         H[i] = h%10;
         l/=10LL;
         h/=10LL;
      }
      cout << rec(0, 0, 0) << endl;
   }
   return 0;
}
