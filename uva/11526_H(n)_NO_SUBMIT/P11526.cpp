/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11877  C++  "Ad Hoc" */
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


int f(int full, int empty) {
	if(full==0) return 0;
	return (full+empty)/3 + f((full+empty)/3,(full+empty)%3);
}

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		int a = f(n,0);
		int b = f(n,1);
		printf("%d\n",max(a,b));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

