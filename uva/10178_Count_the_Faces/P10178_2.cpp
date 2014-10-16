/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10178  C++  "Disjoint Sets" */
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

// http://en.wikipedia.org/wiki/Planar_graph#Euler.27s_formula
// http://pavelsimo.blogspot.com/2012/08/uva-10178-count-faces.html

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

map<string,int> m_id;
bool vis[256];
VVI adj;
int nV, nE, seen[256][256];

void dfs(int cur) {
   if(vis[cur]) return;
   vis[cur] = true;
   ++nV;
   for(int i = 0; i < (int)adj[cur].size(); ++i) {
      int nxt = adj[cur][i];
      if(seen[cur][nxt] == 0) continue;
      --seen[cur][nxt];
      --seen[nxt][cur];
      ++nE;
      dfs(nxt);
   }
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   string s, u, v;
   int N, M, p, q, f, i, n;
   while(cin >> N >> M) {
      m_id.clear();
      adj = VVI(256);
      memset(seen, false, sizeof(seen));
      memset(vis, false, sizeof(vis));
      for(i = 0, n = 0; i < M; ++i) {
         cin >> u >> v;
         if(m_id.count(u) == 0) m_id[u] = n++;
         if(m_id.count(v) == 0) m_id[v] = n++;
         p = m_id[u], q = m_id[v];
         seen[p][q]++;
         seen[q][p]++;
         adj[p].push_back(q); 
         adj[q].push_back(p); 
      }
      f = 1;
      for(i = 0; i < N; ++i) {
         if(!vis[i]) {
            nV = nE = 0;
            dfs(i);
            f += 1 + nE - nV;
         }
      }
      cout << f << '\n';
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
