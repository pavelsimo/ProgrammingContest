/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11262  C++  "Binary Search, Bipartite Matching" */
#include <algorithm>
#include <numeric>
#include <iostream>
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
using namespace std;


class BipartiteMatchingHK {
   const int static NIL_VERTEX = 0;
   const int static INF = 98765432;
   size_t Lsz, Rsz;
   vector<int> dist;
   bool _bfs();
   bool _dfs(int v);
public:
   vector< vector<int> > adj;
   vector<int> match;
   void add_edge(int u, int v);  // indice must start from 1
   BipartiteMatchingHK(size_t _Lsz, size_t _Rsz)
      : Lsz(_Lsz), Rsz(_Rsz), adj(Lsz+1, vector<int>()) {}
   int hopcroft_karp();
};
 
inline void BipartiteMatchingHK::add_edge(int u, int v) {
   adj[u].push_back(v + Lsz);
}
 
int BipartiteMatchingHK::hopcroft_karp() {
   match = vector<int>(Lsz+Rsz+1, +NIL_VERTEX);
   int nmatches = 0;
   dist = vector<int>(Lsz+1, +INF);
   while (_bfs()) {
      for (int v = 1; v <= Lsz; ++v)
         if (match[v] == NIL_VERTEX && _dfs(v))
            ++nmatches;
   }
   return nmatches;
}
 
bool BipartiteMatchingHK::_dfs(int v) {
   if (v == NIL_VERTEX)
      return true;
   for (int j = 0; j < adj[v].size(); ++j) {
      int u = adj[v][j];
      if ( dist[ match[u] ] == dist[v]+1 && _dfs(match[u]) ) {
         match[u] = v;
         match[v] = u;
         return true;
      }
   }
   dist[v] = INF;
   return false;
}
 
bool BipartiteMatchingHK::_bfs() {
   queue<int> q;
   for (int v = 1; v <= Lsz; ++v) {
      if (match[v] == NIL_VERTEX) {
         dist[v] = 0;
         q.push(v);
      }
      else
         dist[v] = INF;
   }
   dist[0] = INF;
   while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v == NIL_VERTEX) continue;
      for (int j = 0; j < adj[v].size(); ++j) {
         int u = adj[v][j];
         if (dist[ match[u] ] >= INF) {
            dist[ match[u] ] = dist[v] + 1;
            q.push(match[u]);
         }
      }
   }
   return dist[NIL_VERTEX] < INF;
}


struct Point {
	int x;
	int y;
};

int dist(Point &a, Point &b) {
	int dx = a.x-b.x;
	int dy = a.y-b.y;
	return dx*dx+dy*dy;
}

int N, K;
const int maxn = 102;
char buf[256], temp[64];
vector<Point> BLUE, RED;

bool check(int d) {
	BipartiteMatchingHK bpm(BLUE.size(), RED.size());
	int used = 0;
	for(int i = 0; i < BLUE.size(); ++i) {
		for(int j = 0; j < RED.size(); ++j) {
			int cur = dist(BLUE[i],RED[j]);
			if(cur <= d*d)
				bpm.add_edge(i+1, j+1);
		}
	}
	used = bpm.hopcroft_karp();
	return used>=K;
}

int binary_search() {
	int lo = 0;
	int hi = 10000;
	int mid;
	while(lo < hi) {
		mid = lo + (hi-lo)/2;
		if(check(mid))
			hi = mid;
		else
			lo = mid+1;
	}
	return lo;
}

int main() {
	int TC, ans;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		gets(buf);
		gets(buf);
		BLUE.clear();
		RED.clear();
		sscanf(buf,"%d%d",&N,&K);
		for(int i = 0; i < N; ++i) {
			Point p;
			gets(buf);
			sscanf(buf,"%d %d %s",&p.x,&p.y,temp);
			if(temp[0]=='b') BLUE.push_back(p);
			else RED.push_back(p);
		}
		ans = binary_search();
		if(check(ans)) printf("%d\n",ans);
		else puts("Impossible");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
