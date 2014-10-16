/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11716  C++  "String Manipulation" */
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

char s[10010];

int main(int argc, char *argv[]) {
	int TC, n, k;
	string ans;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		gets(s);
		n = strlen(s);
		k = (int)sqrt(n);
		ans="";
		if(k*k != n) {
			printf("INVALID\n");
		} else {
			for(int i=0; i < k; ++i)
				for(int j = i; j < n; j+=k) ans+=s[j];
			printf("%s\n",ans.c_str());
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
