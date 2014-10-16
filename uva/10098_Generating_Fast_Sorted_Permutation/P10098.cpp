/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10098  C++  "Permutations" */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 16;
char s[MAXN];

int main(int argc, char *argv[]) {
	int TC, n;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%s",s);
		n = strlen(s);
		sort(s,s+n);
		do {
			printf("%s\n",s);
		} while(next_permutation(s,s+n));
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */