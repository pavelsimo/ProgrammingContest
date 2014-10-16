/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  573  C++  "Ad Hoc" */
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
	
	int H, U, D, F;
	while(scanf("%d%d%d%d",&H,&U,&D,&F)==4) {
		if(H==0 && U==0 && D==0 && F==0) break;
		H*=100; U*=100; D*=100;
		int h=0;
		int f=(U*F)/100;
		for(int i = 1; 1; ++i) {
			if(U<0) U=0;
			h+=U;
			if(h > H){ printf("success on day %d\n",i); break;}
			h-=D;
			if(h < 0) { printf("failure on day %d\n",i); break;}
			U-=f;
		}
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */

