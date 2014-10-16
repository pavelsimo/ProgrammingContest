/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11512  C++  "Simple Math" */
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
	int TC, n, best, size;
	string s;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		map<string, int> C;
		getline(cin,s);
		n=s.size();
		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j <= n; ++j) {
				string t = s.substr(i,j-i);
				C[t]++;
			}
		}
		best = 0;		
		string ans = s;
		FORE(C,it) {
			if(it->second > 1) {
				if(it->first.size() > best) {   
					ans = it->first;
					best = it->first.size();
				}
			}
		}
		if(ans==s) printf("No repetitions found!\n");
		else printf("%s %d\n",ans.c_str(),C[ans]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

