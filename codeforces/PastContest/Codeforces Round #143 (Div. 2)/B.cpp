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

const int INF = 0x3f3f3f3f;
int memo[102][102][2], N, D, L;

int go(int n, int l, int s, int d) {
   printf("(%s) n=%d l=%d d=%d\n",s ? "-": "+",n,l,d);
   if(n == N) return d == D;
   int res = 0;
   if(memo[n][l][s] != -1) 
      return memo[n][l][s];
   for(int i = 1; i <= L; ++i)
      res |= go(n + 1, i, s ^ 1, s ? (d + i): (d - i));
   return memo[n][l][s] = res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   memset(memo, -1, sizeof(memo));
   cin >> N >> D >> L;
   DEBUG(go(1, 1, N % 2, D));
   return 0;
}

