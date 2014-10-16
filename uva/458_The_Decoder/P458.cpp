/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  458  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

char buf[2048];

int main(int argc, char *argv[]) {
	int n;
   while(gets(buf)) {
		n = strlen(buf);
		for(int i = 0; i < n; ++i) buf[i]-=7;
		printf("%s\n",buf);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

