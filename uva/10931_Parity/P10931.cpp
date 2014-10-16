/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10931 C++  "Ad Hoc" */
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
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int nbit = 31;

int main(int argc, char *argv[]) {	
	int n, cnt, ok;
	string s;
	while(scanf("%d",&n)==1) {
		if(n==0)break;
		s="";
		cnt = 0;
		for(int b = nbit; b >= 0; --b) {
			if((n&(1<<b))!=0) {
				s+="1";
				cnt++;
			} else if(cnt > 0) {
				s+="0";
			}
		}
		printf("The parity of %s is %d (mod 2).\n",s.c_str(),cnt);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

