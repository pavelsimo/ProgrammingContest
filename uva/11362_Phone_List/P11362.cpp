/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11362  C++  "String Manipulation" */
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
	int TC,n,ok;
	string word;
	cin >> TC;
	while(TC-- > 0) {
		set<string> M;
		cin >> n;
		ok=1;
		for(int i = 0; i < n; ++i) {
			cin >> word;
			M.insert(word);
		}
		FORE(M,it) {
			string s = *it;
			for(int j = 1; j <= s.size()-1; ++j) {
				string t = s.substr(0,j);
				if(M.count(t) > 0) {
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

