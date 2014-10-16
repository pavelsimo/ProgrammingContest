/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11830  C++  "Ad Hoc, Simple Math" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

string buf, digit, num, ans;

string format(const string &s) {
	if(s.size()==0) return "0";
	int pos;
	for(pos=0; pos < s.size(); ++pos)
		if(s[pos]!='0') break;
	string t=s.substr(pos);
	return t.size()==0?"0":t;
}

int main(int argc, char *argv[]) {
	while(getline(cin,buf)) {
		if(buf[0]=='0' && buf[2]=='0') break;
		istringstream ncin(buf);
		getline(ncin,digit,' ');
		getline(ncin,num,' ');
		ans="";
		for(int i = 0; i < num.size(); ++i)
			if(num[i]!=digit[0]) 
				ans+=num[i];
		cout << format(ans) << endl;
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
