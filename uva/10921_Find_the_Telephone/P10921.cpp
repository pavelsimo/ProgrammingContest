/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10921  C++  "Ad Hoc" */
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

int A[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main(int argc, char *argv[]) {
	int ch;
	while((ch=getchar())!=EOF) {
		if(isalpha(ch)) {
			if(ch==0||ch==1) putchar(ch);
			else putchar(A[ch-'A']+'0');
		} else {
			putchar(ch);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

