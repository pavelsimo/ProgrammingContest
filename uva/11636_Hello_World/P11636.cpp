/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11636  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 10010;
int a[10020];

int main(int argc, char *argv[]) {
	int n, tc=1;
	memset(a,0,sizeof(a));
	a[2] = 1;
	for(int i = 2; i <= maxn; i=i*2){
		int j;
		for(j = i+1; j <= i+i; ++j) {
			if(j > maxn) break;
         a[j] = a[i]+1;     
      }
	}
	
	while(scanf("%d",&n)==1) {
		if(n<=0) break;
		printf("Case %d: %d\n",tc++,a[n]);
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */

