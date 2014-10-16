/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  457  C++  "Ad Hoc, String Manipulation" */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

#define N 50
#define M 40
int DNA[10];
string a[N+1];

int main(int argc, char *argv[]) {
	int TC;
	string t(40,' ');
	scanf("%d",&TC);
	REP(tc,TC) {
		if(tc!=0) putchar('\n');
		REP(i,10) scanf("%d",&DNA[i]);
		
		REP(i,N) a[i] = t;
		a[0][19] = '.';
		
		REP(i,N) {
			string s = a[i];
			REP(j,M) {
				char ch;
				int k = 0;
				if(a[i][j] == '.') k++;
				else if(a[i][j] == 'x') k+=2;
				else if(a[i][j] == 'W') k+=3;
				
				if(j-1 >= 0) {
					if(a[i][j-1] == '.') k++;
					else if(a[i][j-1] == 'x') k+=2;
					else if(a[i][j-1] == 'W') k+=3;
				}
				
				if(j+1 < M) {
					if(a[i][j+1] == '.') k++;
					else if(a[i][j+1] == 'x') k+=2;
					else if(a[i][j+1] == 'W') k+=3;				
				}
				
				if ( DNA[k] == 0 ) ch = ' ';
				else if ( DNA[k] == 1 ) ch = '.';
				else if ( DNA[k] == 2 ) ch = 'x';
				else if ( DNA[k] == 3 ) ch = 'W';
				s[j] = ch;
			}
			if (i+1 < N) a[i+1] = s;
		}
		REP(i,N) {
			REP(j,M)
				putchar(a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

