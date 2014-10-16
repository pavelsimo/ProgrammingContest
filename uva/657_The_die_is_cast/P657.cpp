/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  657  C++  "Graph Theory, DFS" */
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

#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef pair<int,int> ii;
typedef set<ii> SII;

int N, M;
bool vis[60][60], vis2[60][60];
char buf[256], B[60][60];
SII P;

void dfs(int i, int j) {
	if(i >= N || j >= M || i < 0 || j < 0 || B[i][j]=='.' || vis[i][j]) return;
	P.insert(ii(i,j));
	vis[i][j] = true;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1);
}

void dfs2(int i, int j) {
	if(i >= N || j >= M || i < 0 || j < 0 || B[i][j]!='X' 
		|| vis2[i][j] || P.count(ii(i,j))==0) return;
	vis2[i][j] = true;
	dfs2(i+1,j);
	dfs2(i-1,j);
	dfs2(i,j+1);
	dfs2(i,j-1);
}

int main(int argc, char *argv[]) {
	int TC = 0;
	while(gets(buf)) {
		if(sscanf(buf,"%d%d\n",&M,&N)!=2) break;
		if(N==0 && M==0) break;
		memset(vis,false,sizeof(vis));
		memset(vis2,false,sizeof(vis2));
		for(int i = 0; i < N; ++i)
			gets(B[i]);
		vector<int> ans;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < M; ++j) {
				if(!vis[i][j] && (B[i][j]=='*' || B[i][j]=='X')) {
					P.clear();
					ans.push_back(0);
					dfs(i,j);
					FORE(P,it) {
						int ni = it->first;
						int nj = it->second;
						if(!vis2[ni][nj] && B[ni][nj]=='X') {
							dfs2(ni,nj);
							ans[ans.size()-1]++;
						}
					}
				}
			}
		}
		sort(ans.begin(),ans.end());
		printf("Throw %d\n",++TC);
		for(int i = 0; i < ans.size(); ++i) {
			if(i > 0) putchar(' ');
			printf("%d",ans[i]);
		}
		putchar('\n');
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
