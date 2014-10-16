/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  628  C++  "Backtracking" */
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
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int maxn = 102;
string buf, word, rule, dict[maxn];

void doit(string tpl, string s) {
	for(int i = 0; i < tpl.size(); ++i) {
		if(isdigit(tpl[i])) {
			string ans = tpl;
			size_t pos = 0;
			while((pos=ans.find('#',pos))!=string::npos) {
				ans = ans.replace(pos,1,s);
				pos+=s.size();
			}
			puts(ans.c_str());
			if(tpl[i]=='9') continue;
			tpl[i]++;
			doit(tpl,s);
		}
	}
}

int main(int argc, char *argv[]) {
	int N, M;
	while(getline(cin,buf)) {
		sscanf(buf.c_str(),"%d",&N);
		for(int i = 0; i < N; ++i) {
			getline(cin,word);
			dict[i] = word;
		}
		getline(cin,buf);
		sscanf(buf.c_str(),"%d",&M);
		puts("--");
		for(int i = 0; i < M; ++i) {
			getline(cin,rule);
			for(int j = 0; j < N; ++j) {
				doit(rule,dict[j]);
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
