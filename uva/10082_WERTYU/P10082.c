/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10082  C  "Ad Hoc, String" */
#include <stdio.h>

int main(int argc, char *argv[]) {
	int ch, i;
	char *s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	while((ch=getchar())!=EOF) {
		for(i=1;s[i] != ch && s[i]; ++i);
		if(s[i]) putchar(s[i-1]);
		else putchar(ch);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

