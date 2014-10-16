/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10147  C++  "Graph Theory, MST, Disjoint Sets" */
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
      return e1.cost < e2.cost;
   }
};

struct Point {
	int x;
	int y;
	Point(int _x, int _y) : x(_x), y(_y) {}
};

int N, M;
vector<Point> P;
vector<Edge> edges;

int main(int argc, char *argv[]) {
	int TC, x, y, u, v;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		if(tc>1) putchar('\n');
		scanf("%d",&N);
		P.clear();
		edges.clear();
		for(int i = 0; i < N; ++i) {
			scanf("%d%d",&x,&y);
			P.push_back(Point(x,y));
		}
		scanf("%d",&M);
		DisjointSet dset(N);
		for(int i = 0; i < M; ++i) {
			scanf("%d%d",&u,&v);
			--u; --v;
			dset.union_rep(u,v);
		}
		for(int i = 0; i < N; ++i) {
			for(int j = i+1; j < N; ++j) {
				int d = (P[j].x-P[i].x)*(P[j].x-P[i].x) + (P[j].y-P[i].y)*(P[j].y-P[i].y);
				edges.push_back(Edge(i,j,d));
			}
		}
		sort(edges.begin(),edges.end(),cmp());
		bool found = false;
		for(int i = 0; i < edges.size() && dset.size() > 1; ++i) {
			if(dset.union_rep(edges[i].u,edges[i].v)) {
				found = true;
				printf("%d %d\n",edges[i].u+1,edges[i].v+1);
			}
		}
		if(!found) puts("No new highways need");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

