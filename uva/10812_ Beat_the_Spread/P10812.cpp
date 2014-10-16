/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10812  C++  "Simple Math" */
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
	int TC,s,d;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d %d",&s,&d);
		int a = (s+d)/2;
		int b = (s-a);
		if(b>=0 && a+b==s && a-b==d) printf("%d %d\n",a,b);
		else printf("impossible\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

