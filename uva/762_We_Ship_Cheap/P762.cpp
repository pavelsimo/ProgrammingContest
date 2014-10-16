/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  762  C++  "Graph Theory, BFS, Shortest-Path" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int m[1020][1020];
int parent[1020];
int vis[1020];
int k;

int bfs(int from, int to) {
	queue<int> Q;
	Q.push(from);
	vis[from] = 1;
	while(!Q.empty()) {
		int ns = Q.front();
		Q.pop();
		if(ns == to) return 1;
		for(int i = 0; i < k; ++i) {
			if(!vis[i] && m[ns][i]) {
				vis[i] = 1;
				parent[i] = ns;
				Q.push(i);
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {	
	int n,TC=0;
	string buf, u, v;
	while(scanf("%d\n",&n)==1) {
		memset(m,0,sizeof(m));
		memset(parent,0,sizeof(parent));
		memset(vis,0,sizeof(vis));
		map<string,int> idx;
		map<int,string> tostr;
		stack<string> out;
		if(TC!=0) printf("\n"); TC++;
		k = 0;
		for(int i = 0; i < n; ++i) {
			cin >> u >> v;
			if(idx.count(u)==0) idx[u] = k++;
			if(idx.count(v)==0) idx[v] = k++;
			m[idx[u]][idx[v]] = 1;
			m[idx[v]][idx[u]] = 1;
			tostr[idx[u]] = u;
			tostr[idx[v]] = v;
		}
		cin >> u >> v;
		if(idx.count(u)==0 || idx.count(v)==0 ) {
			printf("No route\n");
		} else if(bfs(idx[u],idx[v])) {
         int cur = idx[v];
         while(cur!=idx[u]) {
				out.push(tostr[parent[cur]] + " " + tostr[cur]);
				cur = parent[cur];
			}
			while(!out.empty()) {
				printf("%s\n",out.top().c_str());
				out.pop();
			}                        
		} else {
			printf("No route\n");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

