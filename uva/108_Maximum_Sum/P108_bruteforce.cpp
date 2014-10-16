/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  108 C++  "DP" */
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

int a[102][102];

int main(int argc, char *argv[]) {
	int n, ans;
	while(scanf("%d",&n)==1) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				scanf("%d",&a[i][j]);
			}
		}
		ans = a[0][0];
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				for(int ii = i; ii <= n; ++ii) {
					for(int jj = j; jj <= n; ++jj) {
						int cnt = 0;
						for(int b = i; b < ii; ++b) {
							for(int h = j; h < jj; ++h) {
								cnt+=a[b][h];
							}
						}
						if(cnt > ans) ans = cnt;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	
	

	return 0;
}
/* @END_OF_SOURCE_CODE */

