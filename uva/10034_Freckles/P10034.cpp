/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10034 C++  "Graph Theory, MST, Disjoint Set" */
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

double dist(double x1, double y1, double x2,  double y2) {
	double dx = x1-x2;
	double dy = y1-y2;
	return sqrt(dx*dx+dy*dy);
}

typedef pair<double,double> dd;
typedef vector<dd> VDD;
int N;
VDD P;
vector<Edge> edges;

int main(int argc, char *argv[]) {
	int TC;
	double ans, x, y;
	scanf("%d",&TC);
	for(int tc=0; tc<TC; ++tc) {
		scanf("%d",&N);
		if(tc>0) putchar('\n');
		edges.clear();
		P.clear();
		for(int i = 0; i < N; ++i) {
			scanf("%lf%lf",&x,&y);
			P.push_back(dd(x,y));
		}
		
		for(int i = 0; i < N; ++i)
			for(int j = i+1; j < N; ++j)
				edges.push_back(Edge(i,j,dist(P[i].first,P[i].second,P[j].first,P[j].second)));

		sort(edges.begin(),edges.end(),cmp());
		DisjointSet dset(N);
		ans=0.0;
		for(int i = 0; i < edges.size() && dset.size() > 1; ++i)
			if(dset.union_rep(edges[i].u,edges[i].v))
				ans+=edges[i].cost;
		printf("%.2lf\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

