/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11727  C++  "Ad Hoc" */
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

int A[3];

int main(int argc, char *argv[]) {
	int TC;
	scanf("%d",&TC);
	for(int tc=1; tc <=TC; ++tc) {
		scanf("%d%d%d",&A[0],&A[1],&A[2]);
		sort(A,A+3);
		printf("Case %d: %d\n",tc,A[1]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

