/*
ID: 13
PROG: space
LANG: C++
*/
#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
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

int N, ans;
const int maxn = 1024;
char board[maxn][maxn];
bool vis[maxn][maxn];

void dfs(int i, int j) {
  if ( i >= N || i < 0 || j >= N || j < 0 
        || board[i][j]=='.' || vis[i][j] )
    return;
  vis[i][j]=true;
  dfs(i+1, j);
  dfs(i-1, j);
  dfs(i, j+1);
  dfs(i, j-1);
}

int main() {
	freopen("space.in", "r", stdin);
	freopen("space.out", "w", stdout);
	memset(vis,false,sizeof(vis));
	scanf("%d",&N);
	for(int i = 0; i < N; ++i)
		scanf("%s",&board[i]);
	ans=0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(!vis[i][j] && board[i][j]=='*') {
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
