/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  624  C++  "Backtracking, DP" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 22;
int t[maxn];

int main() {
	int N, ntrack;
	while(scanf("%d%d",&N,&ntrack)==2) {
		for(int i = 0; i < ntrack; ++i) scanf("%d",t+i);
		int S = 1 << ntrack;
		int best = 0;
		int bmask = 0;
		for(int mask = 0; mask < S; ++mask) {
			int sum = 0;
			int ok = 1;
			for(int bit = 0; bit < ntrack; ++bit) {
				if((mask&(1<<bit))!=0) sum+=t[bit];
				if(sum > N) {
					ok = 0;
					break;
				}
			}
			if(ok) {
				if(sum > best) {
					bmask = mask;
					best = sum;
				}
			}
		}
		int sum=0;
		for(int i = 0; i < ntrack; ++i) {
			if((bmask&(1<<i))!=0) {
				sum+=t[i];
				printf("%d ",t[i]);
			}
		}
		printf("sum:%d\n",sum);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
