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

const int MAXN = 1002;
vector<int> adj[MAXN];
bool seen[MAXN];
int memo[MAXN];

int dfs(int cur) {
   int res = 1;
   if(memo[cur] >= 0) 
      return memo[cur];
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];  
      if(!seen[nxt]) {
         seen[nxt] = true;
         res = max(res, 1 + dfs(nxt));
         seen[nxt] = false;
      }
   }
   return memo[cur] = res;
}

int main(int argc, char *argv[]) {
   int TC, N, M, u, v, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&N,&M);
      for(int i = 0; i < N; ++i)
         adj[i].clear();
      res = 1;   
      for(int i = 0; i < M; ++i) {
         scanf("%d%d",&u,&v);
         adj[u].push_back(v);
      }
      for(int i = 0; i < N; ++i) {
         memset(seen,false,sizeof(seen));
         memset(memo,-1,sizeof(memo));
         res = max(res,dfs(i));
      }
      printf("%d\n",res);
   }
   return 0;
}
