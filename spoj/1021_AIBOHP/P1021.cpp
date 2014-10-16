#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 6200;
const int INF = 1000000;
char s[maxn];
int dp[maxn][maxn];
int n, tc;


int main(int argc, char *argv[]) {
   int TC;
	scanf("%d\n",&TC);
	for(tc=1; tc <= TC; ++tc) {
		gets(s);
		n = strlen(s);
		for(int i = 0; i < n; ++i) dp[i][i] = 0;
		for(int d = 0; d < n; ++d) {
			for(int i = 0; i + d < n; ++i) {
				int l = i;
				int r = i+d;
				if(s[l]==s[r]) dp[l][r] = dp[l+1][r-1];
				else dp[l][r] = min(dp[l+1][r],dp[l][r-1])+1;
			}
		}
		printf("%d\n",dp[0][n-1]);
	}
	return 0;
}
