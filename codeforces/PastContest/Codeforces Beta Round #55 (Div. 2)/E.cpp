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

typedef pair<int,pair<int,int> > PIII;
typedef pair<int,int> PII;

int N, a_cur, a_prev;
set<PIII> triplets;
vector<int> adj[3002];
pair<int,int> P[3002][3002];
bool seen[3002][3002];

int bfs() {
   memset(P, -1, sizeof(P));
   memset(seen, false, sizeof(seen));
   queue<PII> Q;
   Q.push(make_pair(0,0));
   while(!Q.empty()) {
      PII cur = Q.front();
      Q.pop();
      if(cur.first == N - 1) {
         a_cur  = cur.first;
         a_prev = cur.second;
         return 0;
      }
      for(int i = 0; i < sz(adj[cur.first]); ++i) {
         int nxt = adj[cur.first][i];
         PIII t = make_pair(cur.second, make_pair(cur.first, nxt));
         if(triplets.count(t) || seen[nxt][cur.first]) continue;         
         P[nxt][cur.first] = make_pair(cur.first, cur.second);
         seen[nxt][cur.first] = true;
         Q.push(make_pair(nxt, cur.first));
      }
   }
   return -1;
}

int main(int argc, char *argv[]) {
   int n, m, k, u, v, a, b, c;
   cin >> n >> m >> k;
   N = n;
   for(int i = 0; i < m; ++i) {
      cin >> u >> v;
      --u; --v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   for(int i = 0; i < k; ++i) {
      cin >> a >> b >> c;
      --a; --b; --c;
      triplets.insert(make_pair(a, make_pair(b, c)));
   }
   int res = bfs();
   if(res >= 0) {
      vector<int> path;
      int cur = a_cur, prev = a_prev;
      while(true) {
         path.push_back(cur);
         if(cur == 0) break;
         int u = P[cur][prev].first;
         int v = P[cur][prev].second;
         cur = u;
         prev = v; 
      }
      cout << sz(path) - 1 << endl;
      for(int i = sz(path) - 1; i >= 0; --i)
         cout << path[i] + 1 << ' ';
      cout << endl;
   } else {
      cout << res << endl;
   }
   return 0;
}

