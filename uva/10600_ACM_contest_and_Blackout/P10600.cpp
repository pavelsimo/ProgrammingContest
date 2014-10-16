/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10600  C++  "MST, Graph Theory, Disjoint Sets" */
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
#include <utility>
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
      if (e1.cost != e2.cost) return e1.cost < e2.cost;
      if (e1.u != e2.u) return e1.u < e2.u;
      return e1.v < e2.v;
   }
};

#define INF 0x3f3f3f3f
int N, M;

vector<Edge> edges;
vector<Edge> mst;
vector<Edge> n_mst;

int main(int argc, char *argv[]) {
	int TC, u, v, c, ans1, ans2;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&N,&M);
		edges.clear();
		mst.clear();
		n_mst.clear();
		for(int i = 0; i < M; ++i) {
			scanf("%d%d%d",&u,&v,&c);
			--u; --v;
			edges.push_back(Edge(u,v,c));
		}
		sort(edges.begin(),edges.end(),cmp());
		DisjointSet dset1(N);
		ans1=0;
		ans2=INF;
		bool found = false;
		for(int i = 0; i < edges.size(); ++i)  {
			if(dset1.union_rep(edges[i].u,edges[i].v)) {
				ans1+=edges[i].cost;
				mst.push_back(edges[i]);
			} else {
				n_mst.push_back(edges[i]);
			}
		}
		for(int i = 0; i < n_mst.size(); ++i)  {
			DisjointSet dset2(N);
			int best = 0;
			dset2.union_rep(n_mst[i].u,n_mst[i].v);
			best+=n_mst[i].cost;
			for(int j = 0; j < mst.size(); ++j)
				if(dset2.union_rep(mst[j].u,mst[j].v))
					best+=mst[j].cost;
			ans2 = min(ans2,best);
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

