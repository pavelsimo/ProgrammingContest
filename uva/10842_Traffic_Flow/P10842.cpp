/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10842  C++  "Graph Theory, MST, Disjoint Set" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <bitset>
using namespace std;

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
      if (e1.cost != e2.cost) return e1.cost > e2.cost;
      if (e1.u != e2.u) return e1.u < e2.u;
      return e1.v < e2.v;
   }
};

#define INF 0x3f3f3f3f

int N, M;
vector<Edge> edges;

int main() {
	int TC, u, v, c, ans;
	scanf("%d",&TC);
	for(int tc = 1; tc <= TC; ++tc) {
		scanf("%d%d",&N,&M);
		edges.clear();
		for(int i = 0; i < M; ++i) {
			scanf("%d%d%d",&u,&v,&c);
			edges.push_back(Edge(u,v,c));
		}
		DisjointSet dset(N);
		sort(edges.begin(),edges.end(),cmp());
		ans = INF;
		for(int i = 0; i < edges.size() && dset.size() > 1; ++i) {
			if(dset.union_rep(edges[i].u,edges[i].v))
				ans = min(ans,edges[i].cost);
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
