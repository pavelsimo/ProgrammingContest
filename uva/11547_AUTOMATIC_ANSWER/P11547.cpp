/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11547  C++  "Simple Math" */
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
	int TC, d, x;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&x);
		x *=567;
		x /=9;
		x +=7492;
		x *=235;
		x /=47;
		x -=498;
		d = (x/10)%10;
		printf("%d\n",d<0?-d:d);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

