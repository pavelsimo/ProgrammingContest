/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  263  C++  "String Manipulation */
#include <iostream>
#include <sstream>
#include <functional>
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

char buf[32];

void chain(int n) {	
	int i,a,b,size,x=n;
	set<int> vis;
	vis.insert(x);
	printf("Original number was %d\n",n);
	for(i = 1; 1; ++i) {
		sprintf(buf,"%d",x);
		size = strlen(buf);
		sort(buf,buf+size);
		a = atoi(buf);
		sort(buf,buf+size,greater<char>());
		b = atoi(buf);
		x = b-a;
		printf("%d - %d = %d\n",b,a,b-a);
		if(vis.count(x)>0) break;
		vis.insert(x);
	}
	printf("Chain length %d\n",i);
}

int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d",&n)==1) {
	   if(n==0) break;
	   chain(n);
	   putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

