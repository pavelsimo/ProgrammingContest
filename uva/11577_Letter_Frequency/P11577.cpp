/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11577  C++  "Ad Hoc" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int freq[26];
char buf[256];

int main(int argc, char *argv[]) {
	int TC, n, best;
	char ch;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		gets(buf);
		n = strlen(buf);
		best=0;
		memset(freq,0,sizeof(freq));
		for(int i = 0; i < n; ++i) {
			if(isalpha(buf[i])) {
				ch = tolower(buf[i]);
				++freq[ch-'a'];
				best=max(best,freq[ch-'a']);
			}
		}
		for(int i = 0; i < n; ++i) {
			if(freq[i]==best) 
				putchar('a'+i);
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
