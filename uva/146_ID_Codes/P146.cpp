/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  146  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int main(int argc, char *argv[]) {	
	string s,t;
	while(getline(cin,s)) {
		if(s[0]=='#') break;
		t = s;
		next_permutation(s.begin(),s.end());
		if(strcmp(t.c_str(),s.c_str()) < 0) printf("%s\n",s.c_str());
		else printf("No Successor\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

