/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10815  C++  "Sorted Set" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
	string s;
	set<string> a;
	while( getline(cin,s) ) {
		for(int i = 0; i < s.size(); ++i) {
			if ( isalpha(s[i])) {
				string word = "";
				while(isalpha(s[i]))
					word+=tolower(s[i++]);
				a.insert(word);
			}
		}
	}
	FORE(a,it)
		printf("%s\n",it->c_str());
	return 0;
}
/* @END_OF_SOURCE_CODE */
