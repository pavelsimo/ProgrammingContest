/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10397  C++  "Graph Theory, MST, Disjoint Sets" */
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
   double cost;
   Edge(int _u, int _v, double _cost) : u(_u), v(_v), cost(_cost) {}
};
 
class cmp {
public:
   bool operator()(const Edge& e1, const Edge& e2) {
      return e1.cost < e2.cost;
   }
};

double dist(double x1, double x2, double y1, double y2) {
	double dx = x1-x2;
	double dy = y1-y2;
	return sqrt(dx*dx+dy*dy);
}

typedef vector<int> VI;
int N, M;
VI X, Y;
vector<Edge> edges;

int main(int argc, char *argv[]) {
	double ans;
	int _x, _y, u, v;
	while(1==scanf("%d",&N)) {
		X.clear();
		Y.clear();
		edges.clear();
		DisjointSet dset(N);
		for(int i = 0; i < N; ++i) {
			scanf("%d%d",&_x,&_y);
			X.push_back(_x);
			Y.push_back(_y);
		}
		scanf("%d",&M);
		ans = 0.0;
		for(int i = 0; i < M; ++i) {
			scanf("%d%d",&u,&v);
			--u; --v;
			dset.union_rep(u,v);
		}
		for(int i = 0; i < N; ++i) {
			for(int j = i+1; j < N; ++j) {
				double d = dist(X[i],X[j],Y[i],Y[j]);
				edges.push_back(Edge(i,j,d));
			}
		}
		sort(edges.begin(),edges.end(),cmp());
		for(int i = 0; i < edges.size() && dset.size() > 1; ++i) {
			if(dset.union_rep(edges[i].u,edges[i].v)) 
				ans+=edges[i].cost;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

