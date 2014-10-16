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

typedef long long llong;

typedef pair<int,int> edge;

const int MAXN = 100010;
vector<edge> edges;
map<int, int> m_ind, m_val;
vector<int> adj[MAXN];
bool seen[MAXN];
int freq[MAXN], src, dst, P[MAXN];

void bfs() {
   memset(seen, false, sizeof(seen));
   memset(P, -1, sizeof(P));
   queue<int> Q;
   Q.push(src);
   while(!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      if(seen[cur]) continue;
      seen[cur] = true;
      if(cur == dst) return;
      for(int i = 0; i < sz(adj[cur]); ++i) {
         int nxt = adj[cur][i];
         if(!seen[nxt]) {
            P[nxt] = cur;
            Q.push(nxt);
         }
      }
   }
}

int main(int argc, char *argv[]) {
   int n, m, u, v;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> u >> v;
      edges.push_back(make_pair(u,v));
   }
   m = 0;
   for(int i = 0; i < n; ++i) {
      u = edges[i].first;
      v = edges[i].second;
      if(m_ind.count(u) == 0)
         m_ind[u] = m, m_val[m] = u, m++;
      if(m_ind.count(v) == 0)
        m_ind[v] = m, m_val[m] = v, m++;
      u = m_ind[u]; v = m_ind[v];
      freq[u]++; freq[v]++;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   int cnt = 0;
   for(int i = 0; i < m; ++i) {
      if(freq[i] == 1 && cnt == 0) src = i, cnt++;
      else if(freq[i] == 1 && cnt == 1) dst = i;
   }
   bfs();
   for(int i = dst; i >= 0; i = P[i])
      cout << m_val[i] << ' ';
   cout << endl;
   return 0;
}

