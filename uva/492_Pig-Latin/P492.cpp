/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  492 C++  "Ad Hoc, String Manipulation" */
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
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int isvocal(char c) {
	char ch = tolower(c);
	return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}

int main(int argc, char *argv[]) {
	int ch;
	string s="";
	while((ch=getchar())!=EOF) {
		if(isalpha(ch)) {
			s+=ch;
		} else {
			if(s.size()>0) {
				if(isvocal(s[0])) {
					s+="ay";
				} else {
					s+=s[0];
					s+="ay";
					s = s.substr(1,s.size());
				}
				printf("%s",s.c_str());
			}
			s="";
			putchar(ch);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

