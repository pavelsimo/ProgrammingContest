/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  852  C++  "DFS Flood Fill" */
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

const int N = 9;
char B[N][N], buf[64];
bool vis_white[N][N], vis_black[N][N];

void dfs_black(int i, int j) {
	if(i >= N || i < 0 || j >= N || j < 0 
		|| vis_black[i][j] || B[i][j]=='O') return;
	vis_black[i][j] = true;
	dfs_black(i+1,j);
	dfs_black(i-1,j);
	dfs_black(i,j+1);
	dfs_black(i,j-1);
}

void dfs_white(int i, int j) {
	if(i >= N || i < 0 || j >= N || j < 0 
		|| vis_white[i][j] || B[i][j]=='X') return;
	vis_white[i][j] = true;
	dfs_white(i+1,j);
	dfs_white(i-1,j);
	dfs_white(i,j+1);
	dfs_white(i,j-1);
}

int main() {
	int TC, white, black;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		memset(vis_white,false,sizeof(vis_white));
		memset(vis_black,false,sizeof(vis_black));
		white=black=0;
		for(int i = 0; i < N; ++i)
			gets(B[i]);
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if(!vis_black[i][j] && B[i][j]=='X') dfs_black(i,j);
				if(!vis_white[i][j] && B[i][j]=='O') dfs_white(i,j);
			}
		}	
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				if(vis_black[i][j] && !vis_white[i][j]) black++;
				else if(!vis_black[i][j] && vis_white[i][j]) white++;
			}
		}
		printf("Black %d White %d\n",black,white);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
