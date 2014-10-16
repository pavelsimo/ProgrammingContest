/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10681  C++  "DP, Graph Theory" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int memo[210][110];
vector<int> adj[110];
int C, L, src, dst, ndays;

int d(int day, int v) {
	if(day==0) return dst==v;
	if(memo[day][v]>=0) return memo[day][v];
	int ans = 0;
	for(int i = 0; i < adj[v].size(); ++i) {
		int u = adj[v][i];
		ans |= d(day-1,u);
	}
	return memo[day][v] = ans;
}

int main(int argc, char *argv[]) {
	int v, u;
	while(scanf("%d%d",&C,&L)==2) {
		if(C==0&&L==0) break;
		for(int i = 0; i <= C; ++i) adj[i].clear();
		memset(memo,-1,sizeof(memo));
		for(int i = 0; i < L; ++i) {
			scanf("%d%d",&v,&u);
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		scanf("%d%d%d",&src,&dst,&ndays);
		if(d(ndays,src)) puts("Yes, Teobaldo can travel.");
		else puts("No, Teobaldo can not travel.");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

