/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  850  C++  "Ad Hoc" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
using namespace std;

const string sample = "the quick brown fox jumps over the lazy dog";

int main(int argc, char *argv[]) {
	int TC;
	string buf;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&TC);
	getline(cin,buf);
	for(int tc = 0; tc < TC; ++tc) {
		vector<string> text;
		bool keyfound = false;
		string key;
		if(tc>0) putchar('\n');
		while(getline(cin,buf)) {
			if(buf.size()==0) break;
			string word;
			text.push_back(buf);
			if(!keyfound) {
				if(buf.size()==sample.size()) {
					set<char> q;
					bool iskey = true;
					for(int i = 0; i < buf.size(); ++i) {
						if(isalpha(buf[i])) {
							q.insert(buf[i]);
						} else {
							if(buf[i]!=sample[i]) {
								iskey=false;
								break;
							}
						}
					}
					if(iskey && q.size()==26) {
						key = buf;
						keyfound = true;
					}
				}							
			}
		}
		if(keyfound) {
			for(int i = 0; i < text.size(); ++i) {
				string s = text[i];
				for(int j = 0; j < s.size(); ++j) {
					if(isalpha(s[j])) {
						int p = key.find(s[j]);
						putchar(sample[p]);
					} else putchar(s[j]);
				}
				putchar('\n');
			}
		} else {
			puts("No solution.");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
