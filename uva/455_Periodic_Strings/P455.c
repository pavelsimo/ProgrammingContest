/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  455  C  "Ad Hoc, String" */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char s[128];
	int TC, tc, n, m, i, j, ans;
	scanf("%d\n",&TC);
	for(tc=0; tc<TC; ++tc) {
		if(tc!=0) putchar('\n');
		scanf("%s\n",s);
		n = strlen(s);
		m = n/2;
		ans = n;
		for(i = 1; i <= m; ++i) {
			if(n%i != 0) continue;
			for(j = i; j < n; ++j)
				if(s[j%i] != s[j]) break;
			if(j==n) {
				ans = i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

