/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  908  C++  "Graph Theory, MST, Disjoint Sets" */
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
 
class CostCmp {
public:
   bool operator()(const Edge& e1, const Edge& e2) {
      if (e1.cost != e2.cost) return e1.cost < e2.cost;
      if (e1.u != e2.u) return e1.u < e2.u;
      return e1.v < e2.v;
   }
};


int N, M, K;
vector<Edge> A, B;

int MST(vector<Edge> &a, DisjointSet &dset) {
	int cost = 0;
	dset.union_rep(0,1);
	for(int i = 0; i < a.size() && dset.size() > 1; ++i)
		if(dset.union_rep(a[i].u,a[i].v))
			cost+=a[i].cost;
	return cost;
}

int main(int argc, char *argv[]) {
	int TC=0, u, v, cost;
	while(1==scanf("%d",&N)) {
		if(TC++ > 0) putchar('\n');
		A.clear();
		B.clear();
		for(int i = 0; i < N-1; ++i) {
			scanf("%d%d%d",&u,&v,&cost);
			A.push_back(Edge(u,v,cost));
		}
		scanf("%d",&K);
		for(int i = 0; i < K; ++i) {
			scanf("%d%d%d",&u,&v,&cost);
			B.push_back(Edge(u,v,cost));
		}
		scanf("%d",&M);
		for(int i = 0; i < M; ++i) {
			scanf("%d%d%d",&u,&v,&cost);
			B.push_back(Edge(u,v,cost));		
		}
		DisjointSet dset1(N+1), dset2(N+1);
		sort(A.begin(),A.end(),CostCmp());
		sort(B.begin(),B.end(),CostCmp());
		printf("%d\n",MST(A,dset1));
		printf("%d\n",MST(B,dset2));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

