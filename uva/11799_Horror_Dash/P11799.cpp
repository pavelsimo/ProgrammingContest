/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11799  C++  "Ad Hoc" */
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	int TC, n, x, ans;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		ans=0;
		scanf("%d",&n);
		for(int i = 0; i < n; ++i) {
			scanf("%d",&x);
			ans=max(ans,x);
		}
		printf("Case %d: %d\n",tc,ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

