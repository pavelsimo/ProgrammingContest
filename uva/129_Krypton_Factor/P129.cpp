/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  129  C++  "Backtracking" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

using namespace std;

int ans = 0;

int is_hard(string s) {
	int n = s.size();
	for(int p = 0; p < n; ++p) {
		for(int k = 1; k <= n; ++k) {
			if(k==p) continue;
			int i;
			for(i = p; i < k; ++i) {
				if(k-p+i >= n) break;
				if(s[i] != s[k-p+i]) break;
			}
			if(i==k)return 0;
		}
	}
	return 1;
}

void search(int n, int L, string s) {
	if(ans > n) return;
	if(ans++ == n) {
		for(int i = 0; i < s.size(); ++i) {
			if(i!=0 && i%64==0) putchar('\n');
			else if(i!=0 && i%4==0) putchar(' ');
			putchar(s[i]);
		}
		putchar('\n');
		printf("%d",s.size());
	} else {
		for(int i = 0; i < L; ++i) {
			string t = s;
			t+=(char)('A'+i);
			if(is_hard(t)) search(n,L,t);
		}		
	}
}

int main(int argc, char *argv[]) {
	int N,L;
	while(scanf("%d%d",&N,&L)==2) {
		if(N==0 || L==0) break;
		ans=0;
		search(N,L,"");
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

