/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  127  C++  "Backtracking" */
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
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int maxn = 54;
char buf[16];
stack<string> deck[maxn];
int n;

int main(int argc, char *argv[]) {
	
	string buf, token;
	while(getline(cin,buf)) {
		if(buf[0]=='#') break;
		istringstream ncin(buf);
		n=0;
		while(getline(ncin,token,' ')) deck[n++].push(token);
		getline(cin,buf);
		istringstream ncin2(buf);
		while(getline(ncin2,token,' ')) deck[n++].push(token);
		
      // DEBUG
		for(int i = 0; i < n; ++i) {
         printf("%2d ",deck[i].size());
		   int k = 0;
			while(!deck[i].empty()) {
            if(k++==0) cout << "("<< deck[i].top() << ") ";
            else cout << deck[i].top() << " ";
				deck[i].pop();
			}
			cout << endl;
		}
		
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
