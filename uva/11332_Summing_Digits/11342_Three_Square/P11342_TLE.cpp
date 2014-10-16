/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11342  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

int ans[3];

int solve(int n) {
	int m = (int)sqrt(n);
	int t = 0;
	for(int a = 0; a <= m; ++a) {
		if(a*a > n) break;
		for(int b = a; b <= m; ++b) {
			if(a*a+b*b > n) break;
			for(int c=b; c <= m; ++c) {
				if(a*a+b*b+c*c > n) break;
				if(a*a+b*b+c*c == n) {
					ans[0] = a; 
					ans[1] = b;
					ans[2] = c;
					return 1;	
				}
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int TC, n;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d",&n);
		if(solve(n)) printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		else printf("-1\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

