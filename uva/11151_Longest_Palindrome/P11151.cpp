/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11151  C++  "DP String" */
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
   if(l > r) return 0;
   if(l == r) return 1;
	if(memo[l][r]>=0) return memo[l][r];
	int &ans = memo[l][r];
	if(s[l]==s[r]) return ans = d(l+1,r-1)+2;
	return ans = max(d(l+1,r),d(l,r-1));
}

int main(int argc, char *argv[]) {
	int TC, n;
	gets(s);
	sscanf(s,"%d",&TC);
	while(TC-- > 0) {
      memset(memo,-1,sizeof(memo));
		gets(s);
		n = strlen(s);
		printf("%d\n",d(0,n-1));
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */

