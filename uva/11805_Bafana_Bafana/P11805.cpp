/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11805  C++  "Ad Hoc, Simple Math" */
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int TC, N, K, P, ans;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC;++tc) {
		scanf("%d%d%d",&N,&K,&P);
		ans = (K+P)%N;
		printf("Case %d: %d\n",tc,ans==0?N:ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
