/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11854  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int n = 3;
int s[n];

int main(int argc, char *argv[]) {
	while(scanf("%d%d%d",&s[0],&s[1],&s[2])==3) {
		if(s[0]==0&&s[1]==0&&s[2]==0) break;
		sort(s,s+n);
		printf("%s\n",(s[0]*s[0]+s[1]*s[1]==s[2]*s[2])?"right":"wrong");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

