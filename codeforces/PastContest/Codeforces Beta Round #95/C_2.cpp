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

typedef long long llong;
const int MAXN = 32;
llong N, M, T;
llong memo[MAXN][MAXN];

llong rec(int b, int g) {
   if(b > N) return 0LL;
   if(g > M) return 0LL;
   if(b + g == T) {
      if(b >= 4 && g >= 1) return 1LL;
      return 0LL;
   }
   return memo[b][g] = rec(b + 1, g) + rec(b, g + 1);
}

int main(int argc, char *argv[]) {
   memset(memo,-1,sizeof(memo));
   cin >> N >> M >> T;
   cout << rec(0,0) << endl;
   return 0;
}

