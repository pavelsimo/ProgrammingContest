/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10480  C++  "Graph Theory, Minimum Cut, Max Flow, Edmonds-Karp" */
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

typedef long long llong;

const int MAXN = 52;
const llong INF = 0x3f3f3f3f;

const int n_source = 0;
const int n_sink   = 1;

vector<int> adj[MAXN];
llong d[MAXN], p[MAXN], flow[MAXN][MAXN], cap[MAXN][MAXN];
bool S[MAXN];

llong mf_edmonds_karp(int src, int dst) {
   memset(flow, 0, sizeof(flow));
   queue<int> q;
   llong f = 0LL;
   while(1) {
      memset(d, 0, sizeof(d));
      d[src] = INF;
      q.push(src);
      while(!q.empty()) {
         int cur = q.front(); q.pop();
         for(int i = 0; i < sz(adj[cur]); ++i) {
            int nxt = adj[cur][i];
            if(d[nxt] == 0 && cap[cur][nxt] > flow[cur][nxt]) {
               p[nxt] = cur;
               q.push(nxt);
               d[nxt] = min(d[cur], cap[cur][nxt] - flow[cur][nxt]);
            }
         }
      }
      if(d[dst] == 0) break;
      for(int cur = dst; cur != src; cur = p[cur]) {
         flow[p[cur]][cur] += d[dst];
         flow[cur][p[cur]] -= d[dst];
      }
      f += d[dst];
   }
   return f;
}


void dfs(int cur) {
   S[cur] = true;
   for(int i = 0; i < sz(adj[cur]); ++i) {
      int nxt = adj[cur][i];
      if(!S[nxt] && flow[cur][nxt] < cap[cur][nxt])
	 dfs(nxt);
   }      
}

int main(int argc, char *argv[]) {
   int N, M, u, v;
   llong c;
   while(scanf("%d%d",&N,&M) == 2) {
      if(!N && !M) break;
      memset(cap, 0, sizeof(cap));
      memset(S, false, sizeof(S));
      for(int i = 0; i < N; ++i) adj[i].clear();
      for(int i = 0; i < M; ++i) {
	 scanf("%d%d%lld",&u,&v,&c);
	 --u, --v;
	 cap[u][v] = cap[v][u] = c;
	 adj[u].push_back(v); 
	 adj[v].push_back(u);
      }
      mf_edmonds_karp(n_source, n_sink);
      dfs(n_source);
      for(int i = 0; i < N; ++i) {
	 if(S[i]) {
	    for(int j = 0; j < N; ++j) {
	       if(!S[j] && cap[i][j]) {
		  printf("%d %d\n", i + 1, j + 1);
	       }
	    }	    
	 }
      }
      printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

