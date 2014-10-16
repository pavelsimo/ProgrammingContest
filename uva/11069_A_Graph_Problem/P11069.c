/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11069  C++  "DP" */
#include<stdio.h>
#define MAXN 80
int a[MAXN];
int main() {
   int n, i;
   a[0] = 0;
   a[1] = 1;
   a[2] = 2;
   a[3] = 2;
   for(i = 4; i <= 76; ++i) a[i] = a[i-2]+a[i-3];
	while(scanf("%d",&n)==1) printf("%d\n",a[n]);
	return 0;
}
