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


vector<int> adj[202];
int p[202], c[202], del_u, del_v;
bool seen[202];
vector<pair<int,int> > edges;

int find_set(int u) {
   if(u != p[u]) p[u] = find_set(p[u]);
   return p[u];
}

void union_set(int u, int v) {
   u = find_set(u); v = find_set(v);
   p[u] = v;
}

int dfs(int cur) {
   int res = 0;
   if(!seen[cur]) {
      seen[cur] = true;
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         if(cur == del_u && nxt == del_v) continue;
         if(cur == del_v && nxt == del_u) continue;
         if(seen[nxt]) continue;
         res = max(res, 1 + dfs(nxt));
      }            
   }
   return res;
}

int main(int argc, char *argv[]) {
   int n, u, v, res;
   cin >> n;
   for(int i = 0; i < n - 1; ++i) {
      cin >> u >> v;
      --u; --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      edges.push_back(make_pair(u,v));
   }
   res = 0;
   del_u = del_v = -1;
   for(int i = -1; i < n - 1; ++i) {
      for(int j = 0; j < n; ++j) {
         p[j] = j;
         c[j] = 0;
      }
      for(int j = 0; j < n - 1; ++j) {
         if(i == j) {
            del_u = edges[j].first;
            del_v = edges[j].second;
            continue;
         }
         union_set(edges[j].first, edges[j].second);
      }
      for(int j = 0; j < n; ++j) {
         int cur = find_set(j);
         memset(seen, false, sizeof(seen));
         c[cur] = max(c[cur], dfs(j));
      }
      sort(c, c + n);
      res = max(res, c[n-1] * c[n-2]);
   }
   cout << res << endl;
   return 0;
}

