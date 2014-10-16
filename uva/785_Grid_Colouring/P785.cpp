/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  785  C++  "DFS Flood Fill" */
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

int N;
string buf, a[60];
bool vis[60][128];
char border_ch;

void dfs(char ch, int i, int j) {
	if(i < 0 || i >= N || j < 0 || j >= a[i].size() || 
		a[i][j]==border_ch || vis[i][j]) return;
	a[i][j] = ch;
	vis[i][j] = true;
	dfs(ch,i+1,j);
	dfs(ch,i-1,j);
	dfs(ch,i,j+1);
	dfs(ch,i,j-1);
}

int main() {
	N=0;
	while(getline(cin,buf)) {
		if(buf[0]=='_') {
			memset(vis,false,sizeof(vis));
			bool found = false;
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j < a[i].size(); ++j) {
					if(!isspace(a[i][j])) {
						border_ch = a[i][j];
						found = true;
						break;
					}
				}
				if(found)break;
			}
			for(int i = 0; i < N; ++i) {
				for(int j = 0; j < a[i].size(); ++j) {
					if(a[i][j]!=border_ch && !isspace(a[i][j]))
						dfs(a[i][j],i,j);
				}
			}
			for(int i = 0; i < N; ++i)
				puts(a[i].c_str());
			puts(buf.c_str());
			N=0;
		} else {
			a[N++]=buf;
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
