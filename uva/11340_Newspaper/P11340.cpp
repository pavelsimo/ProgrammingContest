/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11340  C++  "Ad Hoc" */
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
	int TC,x,n,m,tot;
	char ch,buf[10010];
	scanf("%d",&TC);
	while(TC-- > 0) { 
		map<char,int> M;
		tot=0;
		scanf("%d\n",&n);
		for(int i = 0; i < n; ++i) {
			gets(buf);
			sscanf(buf,"%c %d",&ch,&x);
			M[ch]=x;
		}
		scanf("%d\n",&m);
		for(int i = 0; i < m; ++i) {
			gets(buf);
			int len = strlen(buf);
			for(int j = 0; j < len; ++j)
				tot+=M[buf[j]];
		}
		printf("%.2lf$\n",((double)(tot/100.0)));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

