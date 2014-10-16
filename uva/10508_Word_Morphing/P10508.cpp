/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10508  C++  "Backtracking, String" */
#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
using namespace std;
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

string word[100000];
int vis[100000];
int n,m;

int valid(string &cur, string &next) {
	int cnt = 0;
	for(int i = 0; i < m; ++i)
		if(cur[i] != next[i]) cnt++;
	return cnt==1 ? 1: 0;
}

void dfs(int cur, string s) {
	cout << s << endl;
	if(cur==n) {
		return;
	} else {
		for(int i = 0; i < n; ++i) {
			if(!vis[i] && valid(s,word[i])) {
				vis[i] = 1;
				dfs(cur+1,word[i]);
			}
		}
	}
}

int main() {
	while(cin >> n >> m) {
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; ++i)
			cin >> word[i];
		vis[0] = 1;
		dfs(0,word[0]);
	}
	return 0;
}
