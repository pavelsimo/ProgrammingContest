/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  259  C++  "Graph Theory, Maximum Flow, Bipartite Matching, Edmonds-Karp, BFS" */
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

const int MAXN = 42;
const int INF = 0x3f3f3f3f;

const int n_source = 37;
const int n_sink   = 38;

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
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   memset(cap, 0, sizeof(cap));
   string buf, program, computer;
   int cnt_app = 0, f;
   bool ok;
   while(true) {
      if(!(ok = getline(cin, buf)) || sz(buf) == 0) {
	 f = mf_edmonds_karp(n_source, n_sink);
	 if(f == cnt_app) {
	    for(int i = 26; i <= 35; ++i) {
	       bool found = false;
	       for(int j = 0; j < sz(adj[i]); ++j) {
		  int nxt = adj[i][j];
		  if(nxt == n_sink) continue;
		  if(flow[i][adj[i][j]]) {
		     found = true;
		     cout << char('A' + adj[i][j]);
		     break;
		  }
	       }
	       if(!found) cout << '_';
	    }
	 } else {
	    cout << '!';
	 }
	 cout << '\n';
	 cnt_app = 0;
	 memset(cap, 0, sizeof(cap));
	 for(int i = 0; i <= n_sink; ++i) adj[i].clear();
	 if(!ok) break;
      } else {
	 istringstream in(buf);
	 in >> program >> computer;
	 int u = program[0] - 'A';
	 cap[n_source][u] = program[1] - '0';
	 adj[n_source].push_back(u); adj[u].push_back(n_source);
	 cnt_app += (program[1] - '0');
	 for(int i = 0; i < sz(computer) - 1; ++i) {
	    int v = computer[i] - '0' + 26;
	    cap[u][v] = cap[v][n_sink] = 1;
	    adj[u].push_back(v); adj[v].push_back(u);
	    adj[v].push_back(n_sink); adj[n_sink].push_back(v);
	 }	 
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

