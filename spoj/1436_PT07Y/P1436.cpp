/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PT07Y C++ "Graph Theory, Tree" */
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

int N, M, cnt=0;
const int MAXN = 10002;
VVI adj;
bool vis[MAXN];
int low[MAXN], id[MAXN];

void dfs(int cur) {
   if(!vis[cur]) {
      vis[cur] = true;
      id[cur] = low[cur] = ++cnt;
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         if(!vis[nxt]) 
            dfs(nxt);
         else
            low[cur] = min(low[cur], low[nxt]);
      }
   }
}

int main(int argc, char *argv[]) {
   int u, v;
   bool res;
   scanf("%d%d",&N,&M);
   memset(vis,false,sizeof(vis));
   adj = VVI(N+2);
   for(int i = 0; i < N; ++i) {
      scanf("%d%d",&u,&v);
      adj[u].push_back(v);
   }
   for(int i = 1; i <= N; ++i)
      if(!vis[i]) dfs(i);
   res = true;
   for(int i = 1; i <= N; ++i) {
      if(low[i] < id[i]) {
         res = false;
         break;
      }
   }
   printf("%s\n",res?"YES":"NO");
   return 0;
}
/* @END_OF_SOURCE_CODE */
