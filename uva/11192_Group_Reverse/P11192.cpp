/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11192  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <stack>
#include <cstdio>
#include <cstdlib>
using namespace std;

char buf[256];
char s[128];

int main(int argc, char *argv[]) {
	int n, g, k;
	while(gets(buf)) {
		sscanf(buf,"%d %s",&g,s);
		if(g==0) break;		
		stack<char> st;
		n = strlen(s);
		k = n/g;
		for(int i = 0; i < n; ++i) {
         st.push(s[i]); 
			if(((i+1)%k)==0) {
				while(!st.empty()) {
					putchar(st.top());
					st.pop();
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

