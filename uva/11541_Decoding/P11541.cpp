/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11541  C++  "Ad Hoc" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	int TC, n;
	string s;
	getline(cin,s);
	sscanf(s.c_str(),"%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		getline(cin,s);
		printf("Case %d: ",tc);
		for(int i = 0; i < s.size(); ++i) {
			char ch = s[i];
			string num = "";
			int j;
			for(j = i+1; j < s.size(); ++j) {
				if(!isdigit(s[j])) break;
				num+=s[j];
			}
			i = j-1;
			stringstream in(num); 
			in >> n;
			for(int k = 0; k < n; ++k)
				putchar(ch);
		}
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
