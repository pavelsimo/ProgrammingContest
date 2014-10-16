/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  865  C++  "String Manipulation" */
#include <cstdio>
#include <map>
#include <cstdlib>
using namespace std;

char buf[128];
char a[128];
char b[128];

int main() {
	int TC,n,m;
	scanf("%d\n",&TC);
	for(int tc=0; tc<TC; ++tc) {
		if(tc!=0) putchar('\n');
		map<char, char> M;
		gets(a);
		gets(b);
		n = strlen(a);
		printf("%s\n%s\n",b,a);
		for(int i = 0; i < n; ++i) M[a[i]]=b[i];
		while(gets(buf)) {
			m = strlen(buf);
			if(m==0) break;
			for(int i = 0; i < m; ++i) {
				if(M.count(buf[i]) > 0) putchar(M[buf[i]]);
				else putchar(buf[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}

