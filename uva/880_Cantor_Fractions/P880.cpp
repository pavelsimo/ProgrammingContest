/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  880  C++  "Ad Hoc, Simple Math" */
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

typedef long long llong;

int main(int argc, char *argv[]) {
	llong n;
	while(scanf("%lld",&n)==1) {
		llong k=(llong)floor((sqrt(8.0*n+1)-1)/2-1e-9)+1; 
		llong s=k*(k+1)/2;
		printf("%lld/%lld\n",s-n+1,k-s+n);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

