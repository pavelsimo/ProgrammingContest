/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10739  C++  "DP String" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
using namespace std;

const int maxn = 1024;
char s[maxn];
int memo[maxn][maxn];

int d(int l, int r) {	
	if(l >= r) return 0;
	if(memo[l][r]>=0) return memo[l][r];
	int &ans = memo[l][r];
	if(s[l]==s[r]) return ans = d(l+1,r-1);
	return ans = min(d(l+1,r-1)+1,min(d(l,r-1)+1,d(l+1,r)+1));
}

int main(int argc, char *argv[]) {
	int TC, n;
	scanf("%d\n",&TC);
	for(int tc=1; tc<=TC; ++tc) {
      memset(memo,-1,sizeof(memo));
		gets(s);
		n = strlen(s);
		printf("Case %d: %d\n",tc,d(0,n-1));
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */

