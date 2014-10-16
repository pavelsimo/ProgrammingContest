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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())

int N;
int C[1010];
map<pair<int,int>,int> memo;
int INF = 100000000;

int doit(int cur, int A, int B, int D, int E) {
   if(cur >= N) {
      if(A>0 && B>0 && E==D)
         return max(A,B);
      return -INF;
   }
   if(memo.count(make_pair(cur,abs(A-B)))!=0) 
      return memo[make_pair(cur,abs(A-B))];
   int res = 0;
   res = max(doit(cur+1, A+C[cur], B, D^C[cur],E), doit(cur+1, A, B+C[cur],D, E^C[cur]));
   return memo[make_pair(cur,abs(A-B))] = res;
}


int main() {
   int TC, res;
   scanf("%d",&TC);
   int tc = 1;
   while(TC-- > 0) {
      memo.clear();
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) 
         scanf("%d",C+i);
      res = doit(0,0,0,0,0);
      if(res >= 0)
         printf("Case #%d: %d\n",tc++,res);
      else
         printf("Case #%d: NO\n",tc++);
   }
   return 0;
}
