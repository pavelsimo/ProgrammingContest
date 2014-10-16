/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10107  C++  "Median, Simple Math" */
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
	int x, n;
	vector<int> a;
	while(scanf("%d",&x)==1) {
		if ( a.size() == 0) {
			a.push_back(x);
		} else {
			int i;
			for(i = 0; i < a.size(); ++i)
				if ( x <= a[i] ) break;
			a.insert(a.begin()+i,x);
		}
		n = a.size();
		if ( (n%2)==0 )
			printf("%d\n",(a[n/2]+a[(n/2)-1])/2);
		else
			printf("%d\n",a[n/2]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

