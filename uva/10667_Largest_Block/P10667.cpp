/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10667 C++  "DP, Maximum Consecutive Subsequence 2D" */
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

int n;
int a[102][102];
int t[102];
int INF=1000000;

int mcs() {
	int best=t[0],sum=0;
	for(int i=0; i<n; ++i) {
		sum+=t[i];
		if(sum>best)best=sum;
		if(sum<0)sum=0;
	}
	return best;
}

int main(int argc, char *argv[]) {
	int TC, b, r1, c1, r2, c2, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&n);
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j <= n; ++j) {
				a[i][j]=1;
			}
		}
		scanf("%d",&b);
		while(b-- > 0) {
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			for(int i = r1; i <= r2; ++i) {
				for(int j = c1; j <= c2; ++j) {
					a[i-1][j-1]=-INF;
				}
			}
		}
		ans=a[0][0];
		for(int start=0; start < n; ++start) {
			for(int end=start; end < n; ++end) {
				memset(t,0,sizeof(t));
				for(int j = 0; j < n; ++j) {
					for(int i=start; i <= end; ++i) {
						t[j]+=a[i][j];
					}
				}
				ans=max(ans,mcs());
			}
		}
		printf("%d\n",ans==-INF?0:ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

