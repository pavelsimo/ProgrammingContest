/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  836 C++  "DP, Maximum Consecutive Subsequence 2D" */
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

char buf[1024];
int a[30][30];
int b[30];
int INF = 1000000;

int mcs(int n) {
	int sum=0, best = b[0];
	for(int i = 0; i < n; ++i) {
		sum+=b[i];
		if(sum > best) best = sum;
		if(sum < 0) sum=0;
	}
	return best;
}

int main(int argc, char *argv[]) {
	int TC, n, cost, ans;
	gets(buf);
	sscanf(buf,"%d",&TC);
	gets(buf);
	for(int tc=0; tc < TC; ++tc) {
		if(tc>0) putchar('\n');
		n=0;
		for(int i = 0; gets(buf); ++i) {
			int m=strlen(buf);
			if(m==0)break;
			n=m;
			for(int j = 0; j < m; ++j) {
				if(buf[j]=='1') a[i][j]=1;
				else a[i][j]=-INF;
			}
				
		}
		ans=a[0][0];
		for(int start = 0; start < n; ++start) {
			for(int end = start; end < n; ++end) {
				memset(b,0,sizeof(b));
				for(int j = 0; j < n; ++j) {
					for(int i = start; i <= end; ++i) {
						b[j]+=a[i][j];
					}
				}
				cost = mcs(n);
				if(cost > ans) ans = cost;
			}
		}
		printf("%d\n",ans==-INF?0:ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

