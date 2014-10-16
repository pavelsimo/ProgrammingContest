/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10369  C++  "Binary Search, Disjoint Sets" */
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

typedef vector<int> VI;
int S, P;
VI X, Y;

bool check(double d) {
	DisjointSet dset(P);
	for(int i = 0; i < P; ++i) {
		for(int j = i+1; j < P; ++j) {
			double dist = (X[j]-X[i])*(X[j]-X[i]) + (Y[j]-Y[i])*(Y[j]-Y[i]);
			if(dist > d*d) continue;
			dset.union_rep(i,j);
		}
	}
	return dset.size()<=S;
}

double binary_search() {
	double lo = 0;
	double hi = 100000;
	for(int i = 0; i < 100; ++i) {
		double mid = lo + (hi-lo)/2.0;
		if(check(mid))
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}

int main(int argc, char *argv[]) {
	int TC, px, py;
	double ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&S,&P);
		X.clear();
		Y.clear();
		for(int i = 0; i < P; ++i) {
			scanf("%d%d",&px,&py);
			X.push_back(px);
			Y.push_back(py);
		}
		ans=binary_search();
		printf("%.2lf\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

