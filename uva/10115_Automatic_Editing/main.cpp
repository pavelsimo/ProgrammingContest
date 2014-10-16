/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10115  C++  "Ad Hoc, String Manipulation" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
	string edit, rule, replace;
	int N;
	while (scanf("%d\n",&N)==1) {
		if(N==0) break;
		vector<pair<string,string> >  R;
		REP(i,N) {	
			getline(cin,rule);
			getline(cin,replace);
			R.push_back(make_pair(rule,replace));
		}
		getline(cin,edit);
		int pos;
		REP(i,N) {
			int pos = edit.find(R[i].first);
			if(pos == string::npos) continue;
			edit.replace(pos, R[i].first.size(), R[i].second);
			i--;
		}
		printf("%s\n",edit.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

