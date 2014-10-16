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

using namespace std;

const int MAXN = 302;
const int MAXM = 10000002;
const int INF = 0x3f3f3f3f;
bool c_station[MAXN];
vector<int> adj[MAXN];
int ti[MAXN][MAXN];
int N, M, P, C;
int D[MAXN][MAXM];

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

struct Node {
   int node, battery, ti;
   Node(int _node, int _battery, int _ti) : 
      node(_node), battery(_battery), ti(_ti) {}
};

class CNode {
   public:
      bool operator()(const Node &a, const Node &b) const {
         if(a.ti != b.ti) return a.ti < b.ti;
         return a.battery > b.battery;
      } 
};

int dijkstra() {
   memset(D, 0x3f, sizeof(D));
   priority_queue<Node, vector<Node>, CNode> Q;
   Q.push(Node(0,(c_station[0] ? C: 0),0));
   D[0][c_station[0] ? C: 0] = 0;
   while(!Q.empty()) {
      Node cur = Q.top(); Q.pop();
      fprintf(stderr, "node=%d battery=%d tot_time=%d\n", cur.node, cur.battery, D[cur.node][cur.battery]); 
      if(cur.node == N - 1) 
         return D[cur.node][cur.battery];
      if(cur.ti <= D[cur.node][cur.battery]) {
         for(int i = 0; i < sz(adj[cur.node]); ++i) {
            int n_node = adj[cur.node][i];
            int n_time = ti[cur.node][n_node];
            if(cur.battery - n_time < 0) continue;
            int n_battery = max(0, cur.battery - n_time);
            int n_ti = cur.ti + n_time;
            if(c_station[n_node]) n_battery = C;
            fprintf(stderr, " * node=%d battery=%d tot_time=%d\n", n_node, n_battery, n_ti); 
            if(n_ti < D[n_node][n_battery]) {
               D[make_pair(n_node, n_battery)] = n_ti;
               Q.push(Node(n_node, n_battery, n_ti));
            }
         }
      }
   }
   return -1;
}

int main() {
   
   while(scanf("%d%d%d%d", &N, &M, &P, &C) == 4) {
      int pi, u, v, cost;
      for(int i = 0; i < MAXN; ++i) 
         adj[i].clear();
      memset(ti, 0, sizeof(ti));
      for(int i = 0; i < P; ++i) {
         scanf("%d", &pi);
         c_station[pi] = true;
      }
      for(int i = 0; i < M; ++i) {
         scanf("%d%d%d", &u, &v, &cost);
         adj[u].push_back(v);
         adj[v].push_back(u);
         ti[u][v] = cost; ti[v][u] = cost;
      }
      printf("%d\n",dijkstra());
   }
   return 0;
}
