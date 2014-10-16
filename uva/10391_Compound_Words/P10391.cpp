/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10391  C++  "String Manipulation" */
#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
using namespace std;

string word[120010];

int main() {
	set<string> dictionary;
	int n;
	for(n=0; getline(cin,word[n]); ++n)
		dictionary.insert(word[n]);
	for(int i = 1; i < n; ++i) {
		for(int j = 1; j <= word[i].size(); ++j) {
			string a = word[i].substr(0,j);
			string b = word[i].substr(j);
			if(a=="" || b=="") continue;
			if(dictionary.count(a) > 0 && dictionary.count(b) > 0) {
				printf("%s\n",word[i].c_str());
				break;
			}
		}
	}
	return 0;
}
