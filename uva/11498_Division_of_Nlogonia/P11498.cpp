/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11498  C++  "Ad Hoc" */
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
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int main(int argc, char *argv[]) {
	int k, n, m, x, y;
	while(scanf("%d",&k)==1) {
		if(k==0) break;
		scanf("%d%d",&n,&m);
		for(int i = 0; i < k; ++i) {
			scanf("%d%d",&x,&y);
			if(x==n || y==m) puts("divisa");
			else if(x>n && y>m) puts("NE");
			else if(x<n && y>m) puts("NO");
			else if(x>n && y<m) puts("SE");
			else if(x<n && y<m) puts("SO");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

