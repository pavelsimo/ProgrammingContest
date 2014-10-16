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
int memo[20][2002];
int N, na, mask, tot, v[20];

int rec(int n, int sum) {
   if(n == N) {
      if(na < sum || na < tot-sum) return 0;
      return 1;
   }
   if(memo[n][sum]!=-1) 
      return memo[n][sum];
   int res = 0;
   res|=rec(n+1,sum);
   if(!(mask & (1<<n)))
      res|=rec(n + 1, sum+v[n]);
   return memo[n][sum] = res;
}

int main() {
    freopen("baleshare.in", "r", stdin);
    freopen("baleshare.out", "w", stdout);
    scanf("%d",&N);
    int res = 0;
    for(int i = 0; i < N; ++i) {
      scanf("%d",&v[i]);
      res+=v[i]; 
    }
    for(mask = 0; mask < (1<<N); ++mask) {
       memset(memo,-1,sizeof(memo));
       na = 0;
       tot = 0;
       for(int i = 0; i < N; ++i) {
          if(mask&(1<<i)) 
            na+=v[i];
          else 
            tot+=v[i];
       }
       if(rec(0,0)) res = min(res,na);
    }
    printf("%d\n",res);
    return 0;
}
