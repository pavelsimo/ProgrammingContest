/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10361  C++  "String Manipulation" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int main(int argc, char *argv[]) {
	int TC, k, pos[5], search;
	string s1,s2,t;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		getline(cin,s1);
		getline(cin,s2);
		k=0;
		t="";
		REP(i,s1.size()) {
			if(s1[i]=='<' || s1[i]=='>') {
				pos[k++] = i;
				continue;
			}
			t+=s1[i];
		}
		printf("%s\n",t.c_str());
		t = s1.substr(pos[2]+1,pos[3]-pos[2]-1) 
			+ s1.substr(pos[1]+1,pos[2]-pos[1]-1)
			+ s1.substr(pos[0]+1,pos[1]-pos[0]-1)
			+ s1.substr(pos[3]+1);
		s2.replace(s2.find("..."),3,t);
		printf("%s\n",s2.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
