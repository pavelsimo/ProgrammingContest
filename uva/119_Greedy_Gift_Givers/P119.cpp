/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  119  C++  "Ad Hoc" */
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
	int n, m, total;
	string name, s;
	int tc=0;
	while(cin >> n) {
		map<string, int> group;
		vector<string> lst;
		if(tc++ != 0) putchar('\n');
		for(int i = 0; i < n; ++i) {
			cin >> name;
			group[name] = 0;
			lst.push_back(name);
		}
		for(int i = 0; i < n; ++i) {
			cin >> name >> total >> m;
			if(m==0) continue;
			int x = total/m;
			for(int j = 0; j < m; ++j) {
				cin >> s;
				group[s] += x;
				group[name]-=x;
			}
		}
		for(int i = 0; i < n; ++i)
			printf("%s %d\n",lst[i].c_str(),group[lst[i]]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

