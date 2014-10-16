/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  820  C++  "Graph Theory, Maximum Flow, Edmonds-Karp, BFS" */
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

const int INF = 0x3f3f3f3f;
const int MAXN = 102;

vector<int> adj[MAXN];
int c[MAXN], p[MAXN], flow[MAXN][MAXN], cap[MAXN][MAXN];

int mf_edmonds_karp(int src, int dst) {
   memset(flow, 0, sizeof(flow));
   queue<int> q;
   int f = 0;
   while(1) {
      memset(c, 0, sizeof(c));
      c[src] = INF;
      q.push(src);
      while(!q.empty()) {
         int cur = q.front(); q.pop();
         for(int i = 0; i < sz(adj[cur]); ++i) {
            int nxt = adj[cur][i];
            if(c[nxt] == 0 && cap[cur][nxt] > flow[cur][nxt]) {
               p[nxt] = cur;
               q.push(nxt);
               c[nxt] = min(c[cur], cap[cur][nxt] - flow[cur][nxt]);
            }
         }
      }
      if(c[dst] == 0) break;
      for(int cur = dst; cur != src; cur = p[cur]) {
         flow[p[cur]][cur] += c[dst];
         flow[cur][p[cur]] -= c[dst];
      }
      f += c[dst];
   }
   return f;
}

int main(int argc, char *argv[]) { 
   int N, M, src, dst, u, v, ce;
   for(int tc = 1; 1 == scanf("%d", &N); ++tc) {
      if(!N) break;
      scanf("%d%d%d",&src,&dst,&M);
      --src, --dst;
      memset(cap, 0, sizeof(cap));
      for(int i = 0; i < N; ++i) adj[i].clear();
      for(int i = 0; i < M; ++i) {
	 scanf("%d%d%d",&u,&v,&ce);
	 --u, --v;
	 cap[u][v] = cap[v][u] += ce;
	 adj[u].push_back(v);
	 adj[v].push_back(u);
      }
      printf("Network %d\nThe bandwidth is %d.\n\n", tc, mf_edmonds_karp(src, dst));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

