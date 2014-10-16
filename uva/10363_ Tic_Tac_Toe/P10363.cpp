/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10363  C++  "Ad Hoc" */
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

const int N = 3;
char board[N+1][N+1];
int dr[] = {+1,-1,+0,+0,+1,-1,+1,-1};
int dc[] = {+0,+0,+1,-1,+1,+1,-1,-1};
int dir = 8;

int win(char ch) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(ch==board[i][j]) {
				for(int d = 0; d < dir; ++d) {
					int dx = i;
					int dy = j;
					int k;
					for(k = 1; k < N; ++k) {
						dx+=dr[d];
						dy+=dc[d];
						if(dx < 0 || dx >= N || dy < 0 || dy >= N || board[dx][dy]!=ch) break;
					}
					if(k == N) return 1;
				}
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int TC, x, o, ok;
	scanf("%d",&TC);
	while(TC-- > 0) {
		x=o=0;
		ok=1;
		for(int i = 0; i < N; ++i) {
			scanf("%s",board[i]);
			for(int j = 0; j < N; ++j) {
				if(board[i][j]=='X')x++;
				else if(board[i][j]=='O')o++;
			}
		}
		if(o > x) ok = 0;
		else if(x-o > 1) ok = 0;
		else if(win('X') && x!=o+1 ) ok = 0;
		else if(win('O') && x!=o ) ok = 0;
		else if(win('X') && win('O')) ok = 0;
		printf("%s\n",ok?"yes":"no");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

