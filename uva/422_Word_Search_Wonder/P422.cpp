/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  422  C++  "String Manipulation" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)


char board[102][102];
char buf[128];
int dr[] = {+1,-1,+0,+0,+1,-1,+1,-1};
int dc[] = {+0,+0,+1,-1,+1,+1,-1,-1};
int dir = 8;
int a[4];

int find(char *s, int n) {
	int m = strlen(s);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(board[i][j]==s[0]) {
				for(int d = 0; d < dir; ++d) {
					int dx=a[0]= i;
					int dy=a[1]= j;
					a[0]++;
					a[1]++;
					int k;
					for(k = 1; k < m; ++k) {
						dx+=dr[d];
						dy+=dc[d];
						if(dx >= n || dx < 0 || dy >= n || dy < 0 || s[k] != board[dx][dy]) break;
					}
					if(k==m) {
						a[2]=dx+1;
						a[3]=dy+1;
						return 1;
					}
				}
			
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d",&n)==1) {
		for(int i = 0; i < n; ++i)
			scanf("%s\n",board+i);
		while(gets(buf)) {
			if(buf[0] == '0') break;
			if(find(buf,n)) printf("%d,%d %d,%d\n",a[0],a[1],a[2],a[3]);
			else printf("Not found\n");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

