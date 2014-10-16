/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  441  C++  "Bruteforce" */
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

const int maxn = 20;
int D[maxn];


int main() {
	int n;
	int tc=0;
	while(scanf("%d",&n)==1) {
		if(n==0)break;
		if(tc++!=0)putchar('\n');
		for(int i = 0; i < n; ++i)
			scanf("%d",D+i);
		for(int a = 0; a < n; ++a) {
			for(int b = a+1; b < n; ++b) {	
				for(int c = b+1; c < n; ++c) {	
					for(int d = c+1; d < n; ++d) {	
						for(int e = d+1; e < n; ++e) {	
							for(int f = e+1; f < n; ++f) {	
								printf("%d %d %d %d %d %d\n",D[a],D[b],D[c],D[d],D[e],D[f]);
							}	
						}	
					}	
				}			
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
