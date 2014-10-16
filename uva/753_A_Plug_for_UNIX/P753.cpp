/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  753  C++  "Graph Theory, Maximum Flow, Bipartite Matching, Edmonds-Karp, BFS" */
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

const int MAXN = 520, INF = 0x3f3f3f3f;

const int n_source = 505;
const int n_sink   = 506;

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

map<string, int> m_id;
string buf;
int id;

inline void add_node(const string &s, bool is_receptacle = false) {
   if(!m_id.count(s))
      m_id[s] = id++;
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   int TC, N, M, K;
   string device, receptacle, adapt1, adapt2;
   getline(cin, buf);
   sscanf(buf.c_str(), "%d", &TC);
   while(TC-- > 0) {
      getline(cin, buf);
      
      for(int i = 0; i < MAXN; ++i) adj[i].clear();
      id = 0, m_id.clear();
      memset(cap, 0, sizeof(cap));

      getline(cin, buf);
      sscanf(buf.c_str(), "%d", &N);
      for(int i = 0; i < N; ++i) {
	 getline(cin, receptacle);
	 add_node(receptacle);
	 int u = m_id[receptacle];
	 cap[u][n_sink] += 1;
	 adj[u].push_back(n_sink), adj[n_sink].push_back(u);
      }
      getline(cin, buf);
      sscanf(buf.c_str(), "%d", &M);      
      for(int i = 0; i < M; ++i) {
	 getline(cin, buf);
	 istringstream in(buf);
	 in >> device >> receptacle;	 
	 add_node(device), add_node(receptacle);
	 int u = m_id[device], v = m_id[receptacle];
	 
	 cap[n_source][u] += 1;
	 adj[n_source].push_back(u), adj[u].push_back(n_source);
	 
	 cap[u][v] = INF;
	 adj[u].push_back(v), adj[v].push_back(u);
      }
      getline(cin, buf);
      sscanf(buf.c_str(), "%d", &K);            
      for(int i = 0; i < K; ++i) {
	 getline(cin, buf);
	 istringstream in(buf);
	 in >> adapt1 >> adapt2;	 
	 	 
	 add_node(adapt1), add_node(adapt2);
	 int u = m_id[adapt1], v = m_id[adapt2];	 
	 cap[u][v] = INF;
	 adj[u].push_back(v), adj[v].push_back(u);
      }
      cout << M - mf_edmonds_karp(n_source, n_sink) << '\n';
      if(TC) cout << '\n';
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

