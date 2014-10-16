/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10197  C++  "String Manipulation" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
	string a, b, root;
	char ch;
	int size, ok;
	int tc = 0;
	while(	cin >> a >> b ) {
		size = a.length();
		if ( tc++ != 0 ) printf("\n");
		ok = 0;
		printf("%s (to %s)\n",a.c_str(),b.c_str());
		if ( size > 1 ) {
			if ( a[size-1] == 'r' )  {
				ch = a[size-2];
				root = a.substr(0,size-2);
				if ( ch == 'a' || ch == 'e') {
					// first conjugation
					// second conjugation
					printf("eu        %so\n",root.c_str());
					printf("tu        %s%cs\n",root.c_str(),ch);
					printf("ele/ela   %s%c\n",root.c_str(),ch);
					printf("n%cs       %s%cmos\n",243,root.c_str(),ch);
					printf("v%cs       %s%cis\n",243,root.c_str(),ch);
					printf("eles/elas %s%cm\n",root.c_str(),ch);
					ok = 1;
				} else if (ch == 'i') {
					// third conjugation
					printf("eu        %so\n",root.c_str());
					printf("tu        %ses\n",root.c_str());
					printf("ele/ela   %se\n",root.c_str());
					printf("n%cs       %s%cmos\n",243,root.c_str(),ch);
					printf("v%cs       %s%cs\n",243,root.c_str(),ch);
					printf("eles/elas %sem\n",root.c_str());
					ok = 1;
				} 
			}
		}
		if ( !ok ) {
			printf("Unknown conjugation\n");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

