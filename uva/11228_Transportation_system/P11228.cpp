/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11228  C++  "Graph Theory, MST, Disjoint Set" */
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
   double cost;
   Edge(int _u, int _v, double _cost) : u(_u), v(_v), cost(_cost) {}
};
 
class cmp {
public:
   bool operator()(const Edge& e1, const Edge& e2) {
      return e1.cost < e2.cost;
   }
};

double dist(double x1, double y1, double x2,  double y2) {
	double dx = x1-x2;
	double dy = y1-y2;
	return sqrt(dx*dx+dy*dy);
}

typedef pair<int,int> ii;
typedef vector<ii> VII;
int N, R;
VII P;
vector<Edge> edges;


int main() {
	int TC, x, y;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		scanf("%d%d",&N,&R);
		P.clear();
		edges.clear();
		for(int i = 0; i < N; ++i) {
			scanf("%d%d",&x,&y);
			P.push_back(ii(x,y));
		}
		for(int i = 0; i < N; ++i) {
			for(int j = i+1; j < N; ++j) {
				edges.push_back(Edge(i,j,dist(P[i].first,P[i].second,
					P[j].first,P[j].second)));
			}
		}
		sort(edges.begin(),edges.end(),cmp());
		DisjointSet dset(N);
		double cost_road=0.0, cost_railroad=0.0;
		int n_state = 1;
		for(int i = 0; i < edges.size() && dset.size() > 1; ++i) {
			if(dset.union_rep(edges[i].u,edges[i].v)) {
				if(edges[i].cost > R) {
					cost_railroad+=edges[i].cost;
					n_state++;
				} else {
					cost_road+=edges[i].cost;
				}
			}
		}
		printf("Case #%d: %d %d %d\n",tc,n_state,int(round(cost_road)),int(round(cost_railroad)));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
