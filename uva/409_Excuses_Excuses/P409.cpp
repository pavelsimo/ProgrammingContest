/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  409  C++  "String Manipulation" */
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

string keyword[22];

int main(int argc, char *argv[]) {
	string s,ans;
	int n,m,best;
	int tc=1;
	while(scanf("%d%d\n",&n,&m)==2) {
		map<string,int> C;
		for(int i = 0; i < n; ++i) getline(cin,keyword[i]);
		best=0;
		for(int i = 0; i < m; ++i) {
			int cnt = 0;
			getline(cin,s);
			string t =" "+s+" ";
			for(int j = 0; j < t.size(); ++j) t[j] = tolower(t[j]);
			for(int j = 0; j < n; ++j) {
				int pos = 0;
				while((pos=t.find(keyword[j],pos)) != string::npos) {
					if(!isalpha(t[pos-1]) && !isalpha(t[pos+keyword[j].size()])) cnt++;
					pos++;
				}
			}
			if(cnt > best) best = cnt;
			C[s] = cnt;
		}
		printf("Excuse Set #%d\n",tc++);
		FORE(C,it) {
			if(it->second==best)
				printf("%s\n",it->first.c_str());
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

