/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11220  C++  "Ad Hoc" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	int TC, k;
	string buf, word;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&TC);
	getline(cin,buf);
	for(int tc=1; tc<=TC; ++tc) {
		if(tc>1) putchar('\n');
		printf("Case #%d:\n",tc);
		while(getline(cin,buf)) {
			if(buf.size()==0) break;
			istringstream in(buf);
			k = 0;
			while(in >> word) {
				if(k < word.size()) {
					putchar(word[k]);
					k++;
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
