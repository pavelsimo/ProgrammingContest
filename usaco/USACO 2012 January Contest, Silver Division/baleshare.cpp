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

const int MAXM = 20;
const int MAXN = 2000;
bool DP[2][MAXN+2][MAXN+2];
int A[MAXM], N;
int main() {
   //freopen("baleshare.in", "r", stdin);
   //freopen("baleshare.out", "w", stdout);
   scanf("%d",&N);
   int res = MAXN;
   memset(DP,false,sizeof(DP));
   DP[0][0][0] = true;
   for(int i = 0; i < N; ++i)
      scanf("%d",&A[i]);
   int sum = 0;
   for(int i = 0; i < N; ++i) {
      sum+=A[i];
      int cur = i & 1;
      int nxt = cur ^ 1;
      for(int j = 0; j <= MAXN; ++j) {
         for(int k = 0; k <= MAXN; ++k) {
            if(DP[cur][j][k]) {
               DP[nxt][j][k] = true;
               DP[nxt][j + A[i]][k] = true;
               DP[nxt][j][k + A[i]] = true;
            }
         }
      }
   }
   for(int i = 0; i <= MAXN; ++i) {
      for(int j = 0; j <= MAXN; ++j) {
         if(DP[N&1][i][j]) {
            res = min(res, max(i,max(j,sum-(i+j))));
         }
      }
   }
   printf("%d\n",res);
   return 0;
}
