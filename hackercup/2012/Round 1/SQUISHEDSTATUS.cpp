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

const llong MOD = 4207849484LL;
const int MAXN = 2002;

string S;
llong memo[MAXN][5], N, M;

llong rec(int i, int j) {
   if(i == sz(S))
      return 1LL;
   if(memo[i][j] >= 0) 
      return memo[i][j];
   llong X, res = 0LL;
   if((S[i]-'0') >= 1 && (S[i]-'0') <= M) {
      res+=rec(i + 1, 1)%MOD;
   }
   if(i + 1 < sz(S) && (S[i]-'0') != 0) {
      X = (S[i]-'0')*10 + (S[i+1]-'0'); 
      if(X >= 1 && X <= M) res+=rec(i + 2, 2)%MOD;
   }
   if(i + 2 < sz(S) && (S[i]-'0') != 0) {
      X = (S[i]-'0')*100 + (S[i+1]-'0')*10 + (S[i+2]-'0'); 
      if(X >= 1 && X <= M) res+=rec(i + 3, 3)%MOD;
   }
   return memo[i][j] = (res % MOD);
}

int main(int argc, char *argv[]) {
   cin >> N;
   for(int tc = 1; tc <= N; ++tc) {
      memset(memo,-1,sizeof(memo));
      cin >> M >> S;
      printf("Case #%d: %lld\n",tc,rec(0,1)%MOD);
   }
   return 0;
}
