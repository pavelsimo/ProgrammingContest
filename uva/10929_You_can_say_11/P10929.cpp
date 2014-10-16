/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10929  C++  "Number Theory" */
#include <iostream>
#include <cstring> 
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

char s[1024];

int main(int argc, char *argv[]) {
	int n,a,b;
	while(gets(s)) {
		if(s[0]=='0'&&s[1]=='\0') break;
		n = strlen(s);
		a=b=0;
		for(int i = 0; i < n; ++i) {
			if(i%2==0) a+=s[i]-'0';
			else b+=s[i]-'0';
		}
		if((a-b)%11==0)
			printf("%s is a multiple of 11.\n",s);
		else
			printf("%s is not a multiple of 11.\n",s);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

