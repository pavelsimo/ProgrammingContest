/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  679  C++  "Binary Tree" */
#include <stdio.h>
#define MAXD 20 
int a[1<<MAXD];

int main(int argc, char *argv[]) {
	int TC, maxd, depth, nball, ans;
	scanf("%d",&TC);
	while(TC-- > 0) {
		memset(a,0,sizeof(a));
		scanf("%d%d",&depth,&nball);
		maxd = 1<<depth;
		int i;
		for(i = 0; i < nball; ++i) {
			int k = 1;
			for(;;) {
				a[k] = !a[k];
				k = a[k] ? k*2: k*2+1;
				if(k > maxd) break;
			}
			ans = k/2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

