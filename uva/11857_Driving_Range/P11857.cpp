/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11857  C++  "Graph Theory, MST" */
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

class DisjointSet {
   size_t _n;
   size_t _size;
public:
   vector<int>    parent;
   vector<size_t> rank;
 
   DisjointSet(size_t n);
   size_t size() const;
   int find_rep(int u);
   bool union_rep(int u, int v);
};
 
DisjointSet::DisjointSet(size_t n) : _n(n), _size(n) {
   parent = vector<int>(_n, -1);
   rank   = vector<size_t>(_n, 0);
}
 
inline size_t DisjointSet::size() const {
   return _size;
}
 
int DisjointSet::find_rep(int u) {
   // path compresion
   return parent[u] < 0 ? u : parent[u] = find_rep(parent[u]);
}
 
bool DisjointSet::union_rep(int u, int v) {
   int u_root = find_rep(u);
   int v_root = find_rep(v);
   if (u_root == v_root)
      return false;
   int u_rank = rank[u_root];
   int v_rank = rank[v_root];
   if (u_rank > v_rank)
      parent[v_root] = u_root;
   else {
      parent[u_root] = v_root;
      if (u_rank == v_rank)
         rank[v_root] = rank[u_root] + 1;
   }
   --_size;
   return true;
}

struct Edge {
   int u, v;
   int cost;
   Edge(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}
};
 
class cmp {
public:
   bool operator()(const Edge& e1, const Edge& e2) {
      if (e1.cost != e2.cost) return e1.cost < e2.cost;
      if (e1.u != e2.u) return e1.u < e2.u;
      return e1.v < e2.v;
   }
};

int N, M;
vector<Edge> edges;
const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[]) {
   int u, v, cost, res;
   while(2==scanf("%d%d",&N,&M)) {
      if(N == 0 && M == 0) break;
      edges.clear();
      for(int i = 0; i < M; ++i) {
         scanf("%d%d%d",&u,&v,&cost);
         edges.push_back(Edge(u,v,cost));
      }
      DisjointSet dset(N);
      sort(all(edges),cmp());
      res = 0;
      for(int i = 0; i < sz(edges) && sz(dset) > 1; ++i) {
         if(dset.union_rep(edges[i].u, edges[i].v))
            res = max(res,edges[i].cost);
      }
      if(sz(dset) > 1) puts("IMPOSSIBLE");
      else printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
