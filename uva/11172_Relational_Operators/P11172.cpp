/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11172  C++  "Simple Math" */
#include <iostream>
#include <cstring> 
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int TC;
	LL a,b;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%lld%lld",&a,&b);
		if(a < b) printf("<\n");
		else if(a > b) printf(">\n");
		else printf("=\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

