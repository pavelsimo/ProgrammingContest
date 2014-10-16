/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11608  C++  "Ad Hoc" */
#include <iostream>
#include <cstdio>

using namespace std;

int a[12];

int main(int argc, char *argv[]) {
	int N, cnt, tc=0, cur;
	while(scanf("%d",&N)==1) {
		if(N<0) break;
		for(int i = 0; i < 12; ++i)
			scanf("%d",&a[i]);
		cnt=N;
		printf("Case %d:\n",++tc);
		for(int i = 0; i < 12; ++i) {
			scanf("%d",&cur);
			if(cnt >= cur) {
				puts("No problem! :D");
				cnt-=cur;
			} else { 
				puts("No problem. :("); 
			}
			cnt+=a[i];
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

