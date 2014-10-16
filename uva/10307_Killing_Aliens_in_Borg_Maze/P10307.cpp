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

typedef pair<int,int> ii;

int N, M;
char B[62][62];
int C[62][62];
char buf[1024];
int dr[] = {+1,-1,+0,+0};
int dc[] = {+0,+0,+1,-1};

void bfs(int r, int c) {
	memset(C,-1,sizeof(C));
	queue<ii> Q;
	Q.push(ii(r,c));
	C[r][c] = 0;
	while(!Q.empty()) {
		ii cur = Q.front();
		Q.pop();
		int cr = cur.first;
		int cc = cur.second; 
		for(int i = 0; i < 4; ++i) {
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if(nr >= N || nr < 0 || nc >= M || nc < 0 || B[nr][nc]=='#' || C[nr][nc]>=0) continue;
			Q.push(ii(nr,nc));
			C[nr][nc] = C[cr][cc] + 1;
		}
	}
}

int main() {
	int TC, sr, sc;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		gets(buf);
		sscanf(buf,"%d%d",&N,&M);
		for(int i = 0; i < N; ++i)
			gets(B[i]);
		for(int r = 0; r < N; ++r) {
			for(int c = 0; c < M; ++c) {
				if(B[r][c]=='S') {
					sr = r;
					sc = c;
				}
			}
		}
		bfs(sr,sc);
		// DEBUG
		for(int r = 0; r < N; ++r) {
			for(int c = 0; c < M; ++c) {
				if(C[r][c]<0) putchar(' ');
				else printf("%d",C[r][c]);
			}
			putchar('\n');
		}
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */
