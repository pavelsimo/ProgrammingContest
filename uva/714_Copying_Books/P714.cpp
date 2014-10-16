/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  714  C++  "Binary Search" */
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

typedef long long llong;

int N, K;
const int maxn = 502;
llong book[maxn];

bool check(llong x) {
	int scribecount = K-1;
	llong cur = 0;
	for(int i = N-1; i >= 0; --i) {
		if(cur+book[i] > x) {
			cur = book[i];
			scribecount--;
		} else {
			cur+=book[i];
		}
		if(i==scribecount) return true;
	}
	return scribecount==0;
}

int main(int argc, char *argv[]) {
	int TC, cnt;
	string ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&N,&K);
		llong lo = 0;
		llong hi = 0;
		for(int i = 0; i < N; ++i) {
			scanf("%lld",&book[i]);
			hi+=book[i];
			lo=max(lo,book[i]);
		}
		while(lo < hi) {
			llong mid = lo + (hi-lo)/2;
			if(check(mid))
				hi = mid;
			else
				lo = mid+1;
		}
		ans="";
		cnt=K-1;
		llong cur = 0;
		bool ok = false;
		for(int i = N-1; i >= 0; --i) {
			if(ok || cur+book[i] > lo) {
				cur = book[i];
				ans = tostr(book[i])+" / "+ans;
				cnt--;
			} else {
				cur += book[i];
				if(i<N-1) ans = tostr(book[i])+" "+ans;
				else ans = tostr(book[i])+ans;
			}
			if(i==cnt) ok=true;
		}
		puts(ans.c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

