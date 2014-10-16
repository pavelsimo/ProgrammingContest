/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11875  C++  "Ad Hoc, Simple Math, Recursion" */
#include <iostream>
#include <algorithm>
using namespace std;

int a[16];

int main(int argc, char *argv[]) {
	int TC, n;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		scanf("%d",&n);
		for(int i = 0; i < n; ++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("Case %d: %d\n",tc,a[n/2]);
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */
