/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10954  C++  "Simple Math" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

bool ispal(string &s) {
	int l = 0;
	int r = s.size()-1;
	while(l < r) {
		if(!isalpha(s[l])) {
			l++;
		} else if(!isalpha(s[r])) {
			r--;
		} else {
			if(tolower(s[l])!=tolower(s[r])) return false;
			l++;
			r--;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	string s;
	while(getline(cin,s)) {
		if(s=="DONE") break;
		if(ispal(s))puts("You won't be eaten!");
		else puts("Uh oh..");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
