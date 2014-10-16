/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11417  C++  "Ad Hoc" */
#include <iostream>
using namespace std;

int a[520];

int gcd(int a, int b) {
	int t;
	while(b != 0) {
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}

int main(int argc, char *argv[]) {
	for(int k = 2; k <= 500; ++k) {
		int G=0;
		for(int i=1;i<k;i++) {
			for(int j=i+1;j<=k;j++)
				G+=gcd(i,j);
		}
		a[k]=G;
	}
	int n;
	while(scanf("%d",&n)==1) {
		if(n==0) break;
		printf("%d\n",a[n]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

