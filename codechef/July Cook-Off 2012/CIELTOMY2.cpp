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

typedef pair<int,int> ii;
typedef vector<ii> vii;

const int MAXN = 22;
const int INF = 2147483630;
vii adj[MAXN];
int D[MAXN];

int dijkstra(int src, int dst) {
   priority_queue<ii,vector<ii>,greater<ii> > Q;
   Q.push(ii(0,src));
   D[src]=0;
   while(!Q.empty()) {
      ii cur = Q.top(); Q.pop();
      int d = cur.first;
      int v = cur.second;
      if(v==dst) return d;
      if(d <= D[v]) {
         for(int i = 0; i < (int)adj[v].size(); ++i) {
            ii nxt = adj[v][i];
            int cost = nxt.first;
            int u = nxt.second;
            if(D[v]+cost < D[u]) {
               D[u] = D[v]+cost;
               Q.push(ii(D[u],u));
            }
         }
      }
   }
   return 0;
}

int n, m, spath_cost;
bool seen[22];
int memo[22][2100];

int rec(int cur, int sum) {
   if(sum > spath_cost) return 0;
   if(cur == n - 1) return sum == spath_cost ? 1: 0;
   if(memo[cur][sum] >= 0) return memo[cur][sum];
   int res = 0;
   for(int i = 0; i < (int)adj[cur].size(); ++i) {
      int d = adj[cur][i].first;
      int u = adj[cur][i].second;
      if(!seen[u]) {
         seen[u] = true;
         res += rec(u, sum + d);
         seen[u] = false;                  
      }
   }
   return memo[cur][sum] = res;
}


int main() { 
   int TC, ai, bi, ci;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&n,&m);
      memset(seen, false, sizeof(seen));
      memset(memo, -1, sizeof(memo));
      for(int i = 0; i < n; ++i) {
         D[i] = INF;
         adj[i].clear();
      }
      for(int i = 0; i < m; ++i) {
         scanf("%d%d%d",&ai,&bi,&ci);
         --ai; --bi;
         adj[ai].push_back(ii(ci,bi));
         adj[bi].push_back(ii(ci,ai));
      }
      spath_cost = dijkstra(0, n - 1);
      seen[0] = true;
      printf("%d\n",rec(0,0));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
