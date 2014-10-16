/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11839  C++  "Ad Hoc" */
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
	int n, ans, cnt;
	char ch;
	while(scanf("%d",&n)==1) {
      if(n==0)break;
		for(int i = 0; i < n; ++i) {
			cnt=0;
			for(int j = 0; j < 5; ++j) {
				scanf("%d",&ans);
				if(ans>=0 && ans<=127) {
					cnt++;
					ch='A'+j;
				}
			}
			if(cnt==1) printf("%c\n",ch);
			else puts("*");		
		}
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */

