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

const int INF = 0x3f3f3f3f;
int memo[20][2002][2002];
int a, N;
int v[20];

int rec(int n, int b, int c) {
   if(n == N) {
      if(c > b) swap(b,c);
      if(a-(b+c) < b) return INF;
      return a - (b + c);
   }
   if(memo[n][b][c] >= 0) 
      return memo[n][b][c];
   int res = INF;
   res = min(rec(n+1,b,c),min(rec(n+1,b+v[n],c),rec(n+1,b,c+v[n])));
   return memo[n][b][c] = res;
}

int main() {
    freopen("baleshare.in", "r", stdin);
    freopen("baleshare.out", "w", stdout);
    memset(memo,-1,sizeof(memo));
    scanf("%d",&N);
    for(int i = 0; i < N; ++i) {
      scanf("%d",&v[i]); 
      a+=v[i];
    }
    printf("%d\n",rec(0,0,0));
    return 0;
}
