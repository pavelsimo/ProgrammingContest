/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  483  C++  "Ad Hoc" */
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

int main(int argc, char *argv[]) {
	stack<int> a;
	int ch;
	while((ch=getchar())!=EOF) {
		if(ch==' ' || ch=='\n' || ch==EOF) {
			while(!a.empty()) {
				putchar(a.top());
				a.pop();
			}
			putchar(ch);
		} else {
			a.push(ch);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

