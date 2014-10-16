/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10074 C++  "DP, Maximum Consecutive Subsequence 2D" */
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

int n, m;
int a[102][102];
int b[102];
int INF = 1000000;

int mcs() {
	int sum=0,best=b[0];
	for(int i = 0; i < m; ++i) {
		sum+=b[i];
		if(sum > best) best=sum;
		if(sum < 0) sum=0;
	}
	return best;
}

int main(int argc, char *argv[]) {
	int ans, cost;
	while(scanf("%d%d",&n,&m)==2) {
		if(n==0||m==0) break;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				scanf("%d",&a[i][j]);
				if(a[i][j]) 
					a[i][j]=-INF;
				else 
					a[i][j]=1;
			}
		}
		ans=a[0][0];
		for(int start=0; start < n; ++start) {
			for(int end=start; end < n; ++end) {
				memset(b,0,sizeof(b));
				for(int j=0; j < m; ++j) {
					for(int i=start; i<=end; ++i) {
						b[j]+=a[i][j];
					}
				}
				ans = max(ans,mcs());
			}
		}
		printf("%d\n",ans==-INF?0:ans);
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */

