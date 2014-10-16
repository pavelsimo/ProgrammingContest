/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID: 482  C++  "Ad Hoc" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 1000000;
string a[maxn];

int main(int argc, char *argv[]) {		
	int TC, index, n;
	string s;
	string buf1, buf2, t1, t2;
	scanf("%d\n",&TC);
	for(int tc=0; tc<TC; ++tc) {
		if(tc!=0) putchar('\n');
		if(tc>=1) getline(cin,buf1);
		getline(cin,buf1);
		getline(cin,buf2);
		istringstream idx(buf1);
		istringstream val(buf2);
		n = 1;
		while(getline(idx,t1,' ')) {
			getline(val,s,' ');
			istringstream(t1) >> index;
			a[index] = s;
			n++;
		}
		for(int i = 1; i < n; ++i)
			printf("%s\n",a[i].c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

