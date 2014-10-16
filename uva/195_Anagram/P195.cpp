/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  195  C++  "Ad Hoc, Simple Math" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

char buf[128];
struct cmp {
	bool operator()(const char &T1, const char &T2) {
		if(tolower(T1)!=tolower(T2)) 
          return tolower(T1) < tolower(T2);
		return T1 < T2;
	}
};

int main(int argc, char *argv[]) {
	int TC, n;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		gets(buf);
		n = strlen(buf);
		sort(buf,buf+n,cmp());
		do {
			printf("%s\n",buf);
		} while(next_permutation(buf,buf+n,cmp()));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
