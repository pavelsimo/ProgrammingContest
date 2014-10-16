/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10905  C++  "Ad Hoc" */
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

struct node {
   string s;
   node(string _s="") {
		s=_s;
	}
	bool operator< (const node &t) const {
		string a = s + t.s;
		string b = t.s + s;
		for(int i = 0; i < a.size(); ++i)
			if(a[i]!=b[i]) return b[i] < a[i];
		return false;
	}
};

node a[52];

int main(int argc, char *argv[]) {	
   int n, x;
	string s, ans;
	while(scanf("%d",&n)==1) {
      if(n==0)break;
		for(int i = 0; i < n; ++i) {
			cin >> s;
			node t(s);
			a[i] = t;
		}
		sort(a,a+n);
		ans="";
		for(int i = 0; i < n; ++i) ans+=a[i].s;
		printf("%s\n",ans.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

