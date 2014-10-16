/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10010  C++  "Ad Hoc" */
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
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

#define DIR 8
int dr[] = {+1,+0,-1,+0,+1,-1,+1,-1};
int dc[] = {+0,+1,+0,-1,+1,-1,-1,+1};
char G[51][51];

int dfs(char *s, int x, int y, int nrows, int ncols) {
	int n = strlen(s);
	REP(i,DIR) {
		int nr = x + dr[i];
		int nc = y + dc[i];
		int j;
		for(j=1; j < n; ++j) {
			if(nr > nrows || nr < 0 || nc > ncols || nc < 0) break;
			if(tolower(s[j]) != tolower(G[nr][nc])) break;
			nr+=dr[i];
			nc+=dc[i];
		}
		if(j==n) return 1;
	}
	return 0;
}


int main(int argc, char *argv[]) {
	int TC, n, m, p, ok;
	char word[64];
	scanf("%d",&TC);
	REP(tc,TC) {
		if(tc!=0) putchar('\n');
		scanf("%d%d",&m,&n);
		REP(i,m)
			scanf("%s",&G[i]);
		scanf("%d",&p);
		REP(k,p) {
			scanf("%s",&word);
			ok = 0;
			REP(i,m) {
				REP(j,n) {
					if(tolower(word[0]) == tolower(G[i][j])) {
						if(dfs(word,i,j,m,n)) {
							ok = 1;
							printf("%d %d\n",i+1,j+1);
							break;
						}
					}
				}
				if(ok) break;
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

