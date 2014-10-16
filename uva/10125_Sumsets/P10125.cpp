/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10125  C++  "Ad Hoc, Math, Brute Force" */
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
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef pair<int,int> pii;
const int maxn = 1010;
int v[maxn];

bool diff(int a, int b, int c, int d) {
    if(a==c || a==d) return false;
    if(b==c || b==d) return false;
    return true;
}

int main(int argc, char *argv[]) {
	int n, found;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		map<int,pii > memo;
		for(int i = 0; i < n; ++i)
			scanf("%d",&v[i]);
		sort(v,v+n);
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i==j) continue;
				memo[v[i]+v[j]] = make_pair(i,j);
			}
		}
		found=0;
		for(int i = n-1; i >= 0; --i) {
			for(int j = n-1; j >= 0; --j) {
				if(i==j) continue;
				int cur = v[i]-v[j];
				if(memo.count(v[i]-v[j]) > 0) {
					int a = v[memo[cur].first];
					int b = v[memo[cur].second];
					int c = v[j];
					int d = v[i];
					if(diff(a,b,c,d)) {
						found=1;
						printf("%d\n",d);										
						break;
					}
				}
			}
			if(found) break;
		}
		if(!found) puts("no solution");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

