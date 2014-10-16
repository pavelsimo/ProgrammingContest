#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
using namespace std;

const int maxn = 2010;
int a[maxn];
int b[maxn];
int memo[maxn][maxn];
char buf[32768];
int n, m;

int lcs(int i, int j) {
	if(i==n || j==m) return 0;
	if(memo[i][j]>=0) return memo[i][j];
	int &ans = memo[i][j];
	if(a[i]==b[j]) return ans = lcs(i+1,j+1)+1;
	return ans = max(lcs(i+1,j),lcs(i,j+1));
}

int main(int argc, char *argv[]) {
	int TC, t, ans;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		char *token;
		t=1;
		ans=0;
		while(gets(buf)) {
			if(buf[0]=='0') break;
			if(t) {
				n=0;
				t=0;
				for(token=strtok(buf," "); token; token=strtok(NULL," ")) {
					int x = atoi(token);
					if(x==0) break;
					a[n++] = x;
				}				
			} else {
				m = 0;
				for(token=strtok(buf," "); token; token=strtok(NULL," ")) {
					int x = atoi(token);
					if(x==0) break;
					b[m++] = x;
				}				
				memset(memo,-1,sizeof(memo));
				int cost = lcs(0,0);
				ans=max(ans,cost);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
