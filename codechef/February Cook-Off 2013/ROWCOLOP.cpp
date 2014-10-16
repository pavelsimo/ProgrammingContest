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

const int MAXN = 3141800;
llong R[MAXN], C[MAXN];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong res, N, Q, k, X, ma;
   string cmd;
   while(cin >> N >> Q) {
      ma = res = 0LL;
      memset(R, 0, sizeof(R));
      memset(C, 0, sizeof(C));
      for(int i = 0; i < Q; ++i) {
         cin >> cmd >> k >> X;
         if(cmd[0] == 'R') R[k] += X;
         else C[k] += X;
         ma = max(ma, C[k]);
      }
      for(int i = 1; i <= N; ++i)
         res = max(res, R[i] + ma);         
      cout << res << endl;
   }
   return 0;
}
