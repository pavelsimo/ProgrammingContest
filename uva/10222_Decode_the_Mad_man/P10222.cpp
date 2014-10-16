/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10222  C++  "Ad Hoc" */
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

const int size = 262144;
char *keyboard = "   `1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
char buf[size];

int main(int argc, char *argv[]) {
	int n, m=strlen(keyboard);
	while(gets(buf)) {
		n = strlen(buf);
		for(int i = 0; i < n; ++i) {
			char ch = isalpha(buf[i]) ? tolower(buf[i]) : buf[i];
			for(int j = 2; j < m; ++j) {
				if(keyboard[j]==ch) {
					putchar(keyboard[j-2]);
					break;
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

