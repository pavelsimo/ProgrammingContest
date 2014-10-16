/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  272  C  "Ad Hoc, String" */
#include <stdio.h>

int main(int argc, char *argv[]) {
	int ch;
	int t = 1;
	while((ch=getchar())!=EOF) {
		if(ch=='"') {
			printf("%s",t ? "``": "''");
			t=!t;
		} else printf("%c",ch);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

