/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  490  C++  "Ad Hoc, String Manipulation" */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

char s[101][101];

int main(int argc, char *argv[]) {
	int N=0, M = 0;
	memset(s,0,sizeof(s));
	while(gets(s[M])) {
		N = max(N,(int)strlen(s[M]));
		M++;
	}
	for(int j = 0; j < N; ++j) {
		for(int i = M-1; i >= 0; --i) {
			if(s[i][j]==0)
				putchar(' ');
			else
				putchar(s[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

