/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10450  C++  "Math" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll a[52];

int main(int argc, char *argv[]) {
	a[0] = 1LL;
	a[1] = 2LL;
	a[2] = 3LL;
	for(int i = 3; i <= 50; ++i)
		a[i] = a[i-1]+a[i-2];

	int TC, n;
	scanf("%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		scanf("%d",&n);
		printf("Scenario #%d:\n",tc);
		printf("%lld\n\n",a[n]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

