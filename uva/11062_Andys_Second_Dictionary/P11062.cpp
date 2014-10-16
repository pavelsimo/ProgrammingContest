/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11062  C++  "String Manipulation" */
#include <iostream>
#include <cstdio>
#include <set>
#include <cstdlib>
using namespace std;
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int main() {
	int ch, prev;
	set<string> dictionary;
	string word="";
	while((ch=getchar())!=EOF) {
		if(ch=='\n' && prev=='-') {
			if(word.size() > 1 && word[word.size()-1]=='-')
				word = word.substr(0,word.size()-1);
		} else if(isalpha(ch) || ch=='-') {
			word+=tolower(ch);
		} else if(prev!='-' && !isalpha(ch)) {
			if(word=="") continue;
			dictionary.insert(word);
			word="";
		}
		prev=ch;
	}
	FORE(dictionary,it)
		cout << *it << endl;
	return 0;
}
