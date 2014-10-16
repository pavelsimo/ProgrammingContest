/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  154  C++  "Bruteforce" */
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

const int maxn = 200;
const int maxm = 255;
char a[maxn][maxm];
char bin[] = {'r','o','y','g','b'};
int nbin = 5;

int main() {
	string buf, s;
	int n=0;
	while(getline(cin,buf)) {
		if(buf[0]=='#') break;
		if(buf[0]=='e') {
			int ans = 1;
			int best = 0;
			for(int i = 0; i < n; ++i) {
				int cost = 0;
				for(int d = 0; d < nbin; ++d) {
					for(int j = 0; j < n; ++j) {
						if(i==j) continue;
						if(a[i][bin[d]]==a[j][bin[d]]) cost++;
					}
				}
				if(cost > best) {
					best = cost;
					ans = i+1;
				}
			}
			printf("%d\n",ans);
			n = 0;
			continue;
		}
		int k = 0;
		istringstream ncin(buf);
		while(getline(ncin,s,','))
			a[n][s[0]] = s[2];
		n++;
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
