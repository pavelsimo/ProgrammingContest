/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  264  C++  "Ad Hoc, Simple Math" */
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	int n, k, m, a, b;
	while(scanf("%d",&n)==1) {
		for(k = 0; (k*(k+1))/2 < n; ++k);	
		m = k*(k+1)/2;
		a = (k%2==0)?k-(m-n):1+m-n;
		b = (k%2==0)?1+m-n:k-(m-n);
		printf("TERM %d IS %d/%d\n",n,a,b);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
