/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11342  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int vis[50010];
int x[50010];
int y[50010];
int z[50010];

void solve(int n) {
	memset(vis,0,sizeof(vis));
	int m = (int)sqrt(n);
		for(int a = 0; a <= m; ++a) {
			for(int b = a; b <= m; ++b) {
				for(int c=b; c <= m; ++c) {
					if(!vis[a*a+b*b+c*c]) {
						vis[a*a+b*b+c*c] = 1;
						x[a*a+b*b+c*c] = a;
						y[a*a+b*b+c*c] = b;
						z[a*a+b*b+c*c] = c;
					}
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int TC, n;
	scanf("%d",&TC);
	solve(50000);
	while(TC-- > 0) {
		scanf("%d",&n);
		if(vis[n]) printf("%d %d %d\n",x[n],y[n],z[n]);
		else printf("-1\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

