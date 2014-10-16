/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11313  C++  "Ad Hoc, Simple Math, Recursion" */
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
	int TC, n, m;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&n,&m);
      if((n-1)%(m-1)==0) printf("%d\n",(n-1)/(m-1));
      else puts("cannot do this");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
