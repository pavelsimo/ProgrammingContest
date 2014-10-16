/*
2-SAT using SCC Kosaraju's algorithm

Write the boolean formula as a conjunction of implications (e.g. 
(x1->x2)^(~x1->x3)), and create a graph whose vertices are xi and ~xi 
for all variables xi, and whose edges are the implications. The 
formula is satisfiable if and only if no contradiction of the form
xi -> ~xi -> xi arises following a chain of such implications. This 
amounts to checking whether xi and ~xi are in the same strongly 
connected component, which can be done in linear time.

Building the Graph

The expression (u or v) is equivalent to (~u --> v) and also (~v --> u), 
and in fact the 2 equations together capture all the possibilities in the 
expression (u or v). Thus build a graph of size 2n (where n is the number
of variables), then for each expression (u or v) construct two directed 
edges accordingly. There is a contradiction (unsatisfiable) if, for some
variable x, there is a path from x to ~x AND a path from ~x to x. 
Otherwise for the given constraints our expression is satisfiable.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

#define sz(a) int((a).size())

typedef long long llong;

typedef vector<int> VI;
typedef vector<VI> VVI;

int N, S;

VVI adj, adjT;
VI seen, comp;
stack<int> L;

void dfs1(int cur) {
	seen[cur] = 1;
	for(int i = 0; i < sz(adj[cur]); ++i) {
		int nxt = adj[cur][i];
		if(!seen[nxt])
			dfs1(nxt);
	}
	L.push(cur);
}

void dfs2(int cur) {
	seen[cur] = 1;
   comp[cur] = S;
	for(int i = 0; i < sz(adjT[cur]); ++i) {
		int nxt = adjT[cur][i];
		if(!seen[nxt])
			dfs2(nxt);
	}
}

int neg(int u) {
   if(u > N) return u - N;
   return u + N;
}

int norm(int u) {
   if(u < 0) return -u + N;
   return u;
}

bool is_satisfiable() {
   for(int i = 1; i <= 2*N; ++i) {
      if(comp[i] == comp[neg(i)]) 
         return false;
   }
   return true;
}

int main(int argc, char *argv[]) { 
   int u, v;
   cin >> N;
   int MAXN = 2 * N + 2;
   adj  = VVI(MAXN);
   adjT = VVI(MAXN);
   for(int i = 0; i < N; ++i) {
      cin >> u >> v;
      // u v v  
      // ~u -> v
      // ~v -> u
      u = norm(u);
      v = norm(v);  
      adj[neg(u)].push_back(v);
      adjT[v].push_back(neg(u));
      adj[neg(v)].push_back(u);
      adjT[u].push_back(neg(v));
   }
   seen = VI(MAXN, 0);
   for(int i = 1; i <= 2*N; ++i) {
      if(!seen[i]) 
         dfs1(i);
   }		
   seen = VI(MAXN, 0);
   comp = VI(MAXN, 0);
   for(int i = 1; !L.empty(); ++i) {
      int u = L.top(); L.pop();
      if(!seen[u]) {
         S = u;
         dfs2(u);
      }
   }
   cout << (is_satisfiable() ? 1: 0) << endl;
   return 0;
}

