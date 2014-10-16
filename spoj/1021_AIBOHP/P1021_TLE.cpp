#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 6200;
const int INF = 1000000;
char s[maxn];
short vis[maxn][maxn];
short memo[maxn][maxn];
int n, tc;

int d(int l, int r) {
	if(l >= r) return 0;
	if(v	) return memo[l][r];
	vis[l][r] = tc;
	if(s[l]==s[r]) return memo[l][r] = d(l+1,r-1);
	return memo[l][r] = min(d(l+1,r),d(l,r-1))+1;
}

int main(int argc, char *argv[]) {
   int TC;
	scanf("%d\n",&TC);
	for(tc=1; tc <= TC; ++tc) {
		gets(s);
		n = strlen(s);
		printf("%d\n",d(0,n-1));
	}
	return 0;
}
