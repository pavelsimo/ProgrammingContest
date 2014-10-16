/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12376  C++  "Graph Theory, Greedy" */
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 102;
int w[MAXN], end;
vector<int> adj[MAXN];

int dfs(int cur) {
   end = cur;
   int res = 0, cost = 0, best = -1;
   for(int i = 0; i < (int)adj[cur].size(); ++i) {
      int nxt = adj[cur][i];
      if(w[nxt] > cost) best = nxt, cost = w[nxt];
   }
   if(best >= 0)
      res += dfs(best) + cost;
   return res;
}

int main(int argc, char *argv[]) {  
   int TC, n, m, u, v, res;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d%d",&n, &m);
      for(int i = 0; i < n; ++i)
         adj[i].clear();
      for(int i = 0; i < n; ++i)
         scanf("%d",&w[i]);
      
      for(int i = 0; i < m; ++i) {
         scanf("%d%d",&u, &v);
         adj[u].push_back(v);
      }
      end = 0;
      res = dfs(0);
      printf("Case %d: %d %d\n",tc,res,end);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
