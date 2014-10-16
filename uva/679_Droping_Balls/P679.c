/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  679  C++  "Binary Tree" */
#include <stdio.h>

int main(int argc, char *argv[]) {
	int TC, depth, nball, k;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&depth,&nball);
		k = 1;
		int i;
		for(i=0; i < depth-1; ++i) {
			if(nball%2==0) {
				k = 2*k+1;
				nball/=2;
			} else {
				k = 2*k;
				nball=(nball+1)/2;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

