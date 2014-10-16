/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11713  C++  "String Manipulation" */
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


int isvocal(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int equal(char *s1, char *s2) {
	int n = strlen(s1);
	int m = strlen(s2);
	if(n!=m) return 0;
	for(int i = 0; i < n; ++i) {
		if(!isvocal(s1[i]) || !isvocal(s2[i]))
			if(s1[i] != s2[i]) return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int TC;
	char s1[32];
	char s2[32];
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%s%s",&s1,&s2);
		printf("%s\n",equal(s1,s2)?"Yes":"No");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
