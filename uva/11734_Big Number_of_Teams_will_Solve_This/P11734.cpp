/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11734  C++  "String Manipulation" */
#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
using namespace std;

int main() {
	int TC,n,m;
	char submit[32];
	char judge[32];
	scanf("%d\n",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		gets(submit);
		gets(judge);
		n = strlen(submit);
		m = strlen(judge);
		printf("Case %d: ",tc);
		if(n==m) {
			int ok = 1;
			for(int i = 0; i < n; ++i) {
				if(submit[i] != judge[i]) {
					ok = 0;
					break;
				}
			}
			printf("%s\n",ok?"Yes":"Wrong Answer");
		} else {
			int ok = 1;
			int i=0;
			int j=0;
			while(i < m) {				
				if(submit[j]==' ') {
					j++;
					continue;
				}
				if(j >= n || submit[j] != judge[i]) {
					ok = 0;
					break;
				}
				i++;
				j++;
			}
			printf("%s\n",ok?"Output Format Error":"Wrong Answer");
		}
	}	
	return 0;
}
