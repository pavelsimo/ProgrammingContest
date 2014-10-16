/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11483  C++  "Ad Hoc" */
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
#include <bitset>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

char buf[4096];

int main() {
	int n, m, tc=0;
	while(scanf("%d\n",&n)==1) {
		if(n==0)break;
		printf("Case %d:\n",++tc);
		printf("#include<string.h>\n");
		printf("#include<stdio.h>\n");
		printf("int main()\n");
		printf("{\n");
		for(int i = 0; i < n; ++i) {
			printf("printf(\"");
			gets(buf);
			m = strlen(buf);
			for(int j = 0; j < m; ++j) {
				if(buf[j] == '\"' || buf[j] == '\\')
					putchar('\\');
				putchar(buf[j]);
			}
			printf("\\n\");\n");
		}
		printf("printf(\"\\n\");\n");
		printf("return 0;\n");
		printf("}\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
