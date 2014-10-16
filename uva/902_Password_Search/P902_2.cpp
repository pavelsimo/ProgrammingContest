/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  902  C++  "String Manipulation */
#include <iostream>
#include <sstream>
#include <functional>
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
	int n,m,cnt;
	string buf,ans;
	while(cin >> n >> buf) {
		map<string, int> C;
		m = buf.size();
		int best = 0;
		ans="";
		for(int i = 0; i <= m-n; ++i) {
			string s = buf.substr(i,n);
			int t = ++C[s];
			if(t > best) {
				best = t;
				ans = s;
			}
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

