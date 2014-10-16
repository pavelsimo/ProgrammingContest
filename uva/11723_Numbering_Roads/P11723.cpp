/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11723  C++  "Ad Hoc, Simple Math" */
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int tc=0, R, N, k, ans;
	while(scanf("%d%d",&R,&N)==2) {
		if(R==0 || N==0) break;
		k=N;
		ans=0;
		for(int i = 1; i <= 26; ++i) {
			if(k >= R) break;
			k+=N;
			ans++;
		}
		if(k>=R) printf("Case %d: %d\n",++tc,ans);
		else printf("Case %d: impossible\n",++tc);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
