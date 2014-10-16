/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PT07Z C++ "Graph Theory, Longest Path, Tree" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef vector<int> VI;
typedef vector<VI> VVI;

const int MAXN = 10010;
int N, dist[MAXN];
bool vis[MAXN];
VVI adj;

void dfs(int cur, int d) {
   vis[cur] = true;
   dist[cur] = d;
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];
      if(!vis[nxt]) 
         dfs(nxt, d + 1);
   }
}

int main(int argc, char *argv[]) {
   int u, v, res, best;
   while(1==scanf("%d",&N)) {
      adj = VVI(N+2);
      for(int i = 0; i < N-1; ++i) {
         scanf("%d%d",&u,&v);
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      res = 0;
      best = 1;
      memset(vis,false,sizeof(vis));
      dfs(1,0);
      for(int i = 1; i <= N; ++i) {
         if(dist[i] > dist[best]) 
            best = i;
      }
      memset(vis,false,sizeof(vis));
      dfs(best,0);
      for(int i = 1; i <= N; ++i) {
         if(dist[i] > res) 
            res = dist[i];
      }
      printf("%d\n",res);      
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
