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

int mf_edmonds_karp2(int src, int dst) {
   queue<int> q;
   int f = 0;
   while(1) {
      memset(p, -1, sizeof(p));
      p[src] = src;
      q.push(src);
      while(!q.empty()) {
         int cur = q.front(); 
         q.pop();
         for(int i = 0; i < sz(adj[cur]); ++i) {
            int nxt = adj[cur][i];
            if(cap[cur][nxt] > 0 && p[nxt] == -1) {
               p[nxt] = cur;
               q.push(nxt);
            }
         }
      }
      if(p[dst] == -1) break;
      int mi = INF;
      for(int cur = dst; cur != src; cur = p[cur]) {
         int prev = p[cur];
         mi = min(mi, cap[prev][cur]);
      }
      for(int cur = dst; cur != src; cur = p[cur]) {
         int prev = p[cur];
         cap[prev][cur] -= mi;
         cap[cur][prev] += mi;
      }
      f += mi;
   }
   return f;
}

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
         int prev = p[cur];
         flow[prev][cur] += c[dst];
         flow[cur][prev] -= c[dst];
      }
      f += c[dst];
   }
   return f;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N, M, u, v, ce;
   while(cin >> N >> M) {
      memset(cap, 0, sizeof(cap));
      for(int i = 0; i < N; ++i) adj[i].clear();
      for(int i = 0; i < M; ++i) {
         cin >> u >> v >> ce;
         cap[u][v] = ce;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      cout << mf_edmonds_karp2(0, N - 1) << endl;
   }
   return 0;
}

