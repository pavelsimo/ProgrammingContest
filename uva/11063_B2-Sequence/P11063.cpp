/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11063  C++  "Ad Hoc, Simple Math" */
#include <iostream>
using namespace std;

int N, b[102];
bool vis[20010];

bool doit() {
	memset(vis,false,sizeof(vis));
	for(int i = 0; i < N; ++i) {
		if(b[i] <= 0) return false;
		for(int j = i; j < N; ++j) {
			if((i!=j && b[i] >= b[j]) || vis[b[i]+b[j]]) return false;
			vis[b[i]+b[j]] = true;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	int tc=0;
	while(scanf("%d",&N)==1) {
		for(int i = 0; i < N; ++i)
			scanf("%d",&b[i]);
		if(doit()) printf("Case #%d: It is a B2-Sequence.\n",++tc);
		else printf("Case #%d: It is not a B2-Sequence.\n",++tc);
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
