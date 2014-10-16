/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  111  C++  "Dynamic Programming, LIS" */
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

const int maxn = 30;
int L[maxn];
int A[maxn];
int M[maxn];

int lis(int n) {
	int ans = 0;
	for(int i = 0; i <= n; ++i) L[i] = 1;
	for(int j = 2; j <= n; ++j) {
		for(int i = j-1; i >= 1; --i) {
			if(A[M[i]] < A[M[j]])
				L[j] = max(L[j],L[i]+1);
		}
		ans = max(ans,L[j]);
	}
	return ans;
}

int main() {
	int n, x, tc=0;
	string buf, token;
	scanf("%d\n",&n);
	while(getline(cin,buf)) {
		istringstream ncin(buf);
		if(tc++==0) {
			for(int i = 1; i <= n; ++i) {
				getline(ncin,token,' ');
				istringstream(token) >> x;
				M[x] = i;
			}
		} else {
			for(int i = 1; i <= n; ++i) {
				getline(ncin,token,' ');
				istringstream(token) >> x;
				A[i] = x;
			}
			printf("%d\n",lis(n));
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
